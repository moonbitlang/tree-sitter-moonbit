import React, { useState, useEffect } from "react";
import { useVSCode } from "../hooks/useVSCode";
import SearchReplaceGroup from "./SearchReplaceGroup";
import SearchDetails from "./SearchDetails";
import SearchResults from "./SearchResults";
import { SearchOptions, Result, Response, SearchHistoryItem, SearchBookmark } from "../types";

type TabType = "search" | "history" | "bookmarks";

const App: React.FC = () => {
  const vscode = useVSCode();
  const [initialized, setInitialized] = useState(false);
  const [activeTab, setActiveTab] = useState<TabType>("search");
  const [searchPattern, setSearchPattern] = useState("");
  const [replacePattern, setReplacePattern] = useState("");
  const [searchOptions, setSearchOptions] = useState<SearchOptions>({
    includeIgnored: false,
    includePattern: "",
    excludePattern: "",
  });
  // Layer functionality removed for bookmark-history branch
  const [results, setResults] = useState<Record<string, Result[]>>({});
  const [stats, setStats] = useState({ matchCount: 0, fileCount: 0 });
  const [collapsedFiles, setCollapsedFiles] = useState<Record<string, boolean>>({});
  const [searchHistory, setSearchHistory] = useState<SearchHistoryItem[]>([]);
  const [bookmarks, setBookmarks] = useState<SearchBookmark[]>([]);
  const [showBookmarkModal, setShowBookmarkModal] = useState(false);
  const [bookmarkName, setBookmarkName] = useState("");

  // Handle messages from extension
  useEffect(() => {
    const handleMessage = (event: MessageEvent<Response>) => {
      const message = event.data;
      switch (message.type) {
        case "insert": {
          console.log(`[INSERT] Adding result: ${message.result.id} to ${message.result.uri}`);
          setResults((prevResults) => {
            const newResults = { ...prevResults }; // 保留所有现有结果
            if (!newResults[message.result.uri]) {
              newResults[message.result.uri] = [];
            }
            // 避免重复添加相同 ID 的结果
            if (!newResults[message.result.uri].some((r) => r.id === message.result.id)) {
              newResults[message.result.uri] = [...newResults[message.result.uri], message.result];
              console.log(`[INSERT] Added result to ${message.result.uri}, now has ${newResults[message.result.uri].length} results`);
            } else {
              console.log(`[INSERT] Skipped duplicate result: ${message.result.id}`);
            }
            return newResults;
          });
          // 移除这里的 setStats，让 useEffect 统一处理统计
          setCollapsedFiles((prev) => ({
            ...prev,
            [message.result.uri]: prev[message.result.uri] !== undefined ? prev[message.result.uri] : false,
          }));
          break;
        }
        case "remove": {
          setResults((prevResults) => {
            const newResults = { ...prevResults };
            if (newResults[message.result.uri]) {
              newResults[message.result.uri] = newResults[message.result.uri].filter(
                (r) => r.id !== message.result.id
              );
              if (newResults[message.result.uri].length === 0) {
                delete newResults[message.result.uri];
              }
            }
            return newResults;
          });
          // 移除结果后，统计会在 useEffect 中自动更新
          break;
        }
        case "clear":
          setResults({});
          setCollapsedFiles({});
          setStats({ matchCount: 0, fileCount: 0 });
          break;
        case "refresh":
          performSearch(searchPattern);
          break;
        case "collapseAll":
          collapseAll();
          break;
        case "expandAll":
          expandAll();
          break;
        case "historyLoaded":
        case "historyUpdated":
          setSearchHistory(message.history || []);
          break;
        case "bookmarksLoaded":
        case "bookmarksUpdated":
          setBookmarks(message.bookmarks || []);
          break;
      }
    };

    window.addEventListener("message", handleMessage);
    return () => window.removeEventListener("message", handleMessage);
  }, [results]); // 依赖 results 以响应状态变化

  useEffect(() => {
    let matchCount = 0;
    const fileCount = Object.keys(results).length;
    
    for (const [uri, resultsByUri] of Object.entries(results)) {
      matchCount += resultsByUri.length;
      console.log(`[STATS] File ${uri}: ${resultsByUri.length} results`);
    }
    
    console.log(`[STATS] Total: ${matchCount} results in ${fileCount} files`);
    
    setStats({
      fileCount,
      matchCount,
    });
  }, [results]);

  useEffect(() => {
    if (!initialized) return;
    vscode.setState({
      searchPattern,
      replacePattern,
      activeTab,
      ...searchOptions,
    });
  }, [searchPattern, replacePattern, searchOptions, activeTab, initialized]);

  useEffect(() => {
    const state = vscode.getState();
    if (state) {
      setSearchPattern(state.searchPattern || "");
      setReplacePattern(state.replacePattern || "");
      setActiveTab(state.activeTab || "search");
      setSearchOptions({
        includeIgnored: !!state.includeIgnored,
        includePattern: state.includePattern || "",
        excludePattern: state.excludePattern || "",
      });
    }
    setInitialized(true);
    vscode.postMessage({ type: "loadHistory" });
    vscode.postMessage({ type: "loadBookmarks" });
  }, []);

  const performSearch = (searchPattern: string) => {
    if (!searchPattern.trim()) {
      console.log("[performSearch] Empty search pattern, skipping");
      return;
    }
    
    console.log("[performSearch] Executing search", { 
      query: searchPattern
    });
    
    // 发送搜索请求
    vscode.postMessage({
      type: "search",
      value: { 
        language: "moonbit", 
        query: searchPattern, 
        ...searchOptions
      },
    });
  };

  const clearSearch = () => {
    setSearchPattern("");
    setReplacePattern("");
    setResults({});
    setStats({ matchCount: 0, fileCount: 0 });
    setCollapsedFiles({});
    vscode.postMessage({ type: "clear" });
  };

  const collapseAll = () =>
    setCollapsedFiles((prev) => Object.fromEntries(Object.keys(prev).map((uri) => [uri, true])));
  const expandAll = () =>
    setCollapsedFiles((prev) => Object.fromEntries(Object.keys(prev).map((uri) => [uri, false])));
  const toggleFileCollapse = (fileUri: string) =>
    setCollapsedFiles((prev) => ({ ...prev, [fileUri]: !prev[fileUri] }));
  const handleReplaceMatch = (id: string) =>
    vscode.postMessage({ type: "replaceMatch", value: { id, replace: replacePattern } });
  const handleDismissMatch = (id: string) =>
    vscode.postMessage({ type: "dismissMatch", value: { id } });
  const handleRerunHistorySearch = (item: SearchHistoryItem) => {
    setSearchPattern(item.query);
    setSearchOptions(item.options);
    setActiveTab("search");
    performSearch(item.query);
  };
  const handleDeleteHistoryItem = (id: string) =>
    vscode.postMessage({ type: "deleteHistoryItem", value: { id } });
  const handleClearHistory = () => vscode.postMessage({ type: "clearHistory" });
  const handleRunBookmark = (bookmark: SearchBookmark) => {
    setSearchPattern(bookmark.query);
    setSearchOptions(bookmark.options);
    setActiveTab("search");
    performSearch(bookmark.query);
  };
  const handleDeleteBookmark = (id: string) =>
    vscode.postMessage({ type: "deleteBookmark", value: { id } });

  const handleAddBookmark = () => {
    console.log("[handleAddBookmark] searchPattern:", searchPattern);
    if (!searchPattern.trim()) {
      console.error("[handleAddBookmark] No search pattern");
      vscode.postMessage({ type: "error", value: "No search query available." });
      return;
    }
    setShowBookmarkModal(true);
  };

  const handleSaveBookmark = () => {
    if (!bookmarkName.trim()) {
      console.error("[handleAddBookmark] No bookmark name");
      vscode.postMessage({ type: "error", value: "Bookmark name cannot be empty." });
      return;
    }
    vscode.postMessage({
      type: "addBookmark",
      value: { 
        name: bookmarkName, 
        query: searchPattern, 
        options: searchOptions
      },
    });
    console.log("[handleAddBookmark] Sent addBookmark:", {
      name: bookmarkName,
      query: searchPattern,
      options: searchOptions,
    });
    setShowBookmarkModal(false);
    setBookmarkName("");
  };

  const formatDate = (timestamp: number) => new Date(timestamp).toLocaleString();

  const renderSearchTab = () => (
    <>
      <div className="search-container">
        <SearchReplaceGroup
          searchValue={searchPattern}
          replaceValue={replacePattern}
          onSearchChange={(value) => {
            console.log("[SearchReplaceGroup] Updated searchPattern:", value);
            setSearchPattern(value);
            // 移除自动搜索，只在用户按回车时搜索
            // performSearch(value);
          }}
          onReplaceChange={setReplacePattern}
          onSearch={() => performSearch(searchPattern)}
        />
        <SearchDetails
          includeIgnored={searchOptions.includeIgnored}
          onIncludeIgnoredChange={(value) =>
            setSearchOptions((prev) => ({ ...prev, includeIgnored: value }))
          }
          includePattern={searchOptions.includePattern}
          onIncludePatternChange={(value) =>
            setSearchOptions((prev) => ({ ...prev, includePattern: value }))
          }
          excludePattern={searchOptions.excludePattern}
          onExcludePatternChange={(value) =>
            setSearchOptions((prev) => ({ ...prev, excludePattern: value }))
          }
        />
      </div>
      <SearchResults
        results={results}
        stats={stats}
        collapsedFiles={collapsedFiles}
        onToggleCollapse={toggleFileCollapse}
        onReplaceMatch={handleReplaceMatch}
        onDismissMatch={handleDismissMatch}
      />
    </>
  );

  const renderHistoryTab = () => (
    <div className="history-container">
      <div className="history-header">
        <h3>Search History</h3>
        <button className="icon-button" onClick={handleClearHistory} title="Clear History">
          <span className="codicon codicon-clear-all"></span>
        </button>
      </div>
      <div className="history-list">
        {searchHistory.length === 0 ? (
          <div className="no-history">
            <p>No search history yet</p>
          </div>
        ) : (
          searchHistory.map((item) => (
            <div key={item.id} className="history-item">
              <div className="history-item-header">
                <div className="history-query">{item.query}</div>
                <div className="history-actions">
                  <button
                    className="icon-button"
                    onClick={() => handleRerunHistorySearch(item)}
                    title="Rerun Search"
                  >
                    <span className="codicon codicon-search"></span>
                  </button>
                  <button
                    className="icon-button"
                    onClick={() => handleDeleteHistoryItem(item.id)}
                    title="Delete"
                  >
                    <span className="codicon codicon-trash"></span>
                  </button>
                </div>
              </div>
              <div className="history-item-details">
                <div className="history-meta">
                  <span className="history-timestamp">{formatDate(item.timestamp)}</span>
                  <span className="history-results">{item.resultCount} results</span>
                </div>
                {/* Layer functionality removed for bookmark-history branch */}
              </div>
            </div>
          ))
        )}
      </div>
    </div>
  );

  const renderBookmarksTab = () => (
    <div className="bookmarks-container">
      <div className="bookmarks-header">
        <h3>Bookmarks</h3>
        <button
          className="icon-button"
          onClick={handleAddBookmark}
          title="Add Current Search as Bookmark"
          disabled={!searchPattern.trim()}
        >
          <span className="codicon codicon-bookmark"></span>
        </button>
      </div>
      {showBookmarkModal && (
        <div className="modal-overlay">
          <div className="modal">
            <div className="modal-header">
              <h4>Add Bookmark</h4>
              <button 
                className="icon-button modal-close"
                onClick={() => setShowBookmarkModal(false)}
                title="Close"
              >
                <span className="codicon codicon-close"></span>
              </button>
            </div>
            <div className="modal-content">
              <div className="modal-input-group">
                <label htmlFor="bookmark-name">Bookmark Name</label>
                <input
                  id="bookmark-name"
                  type="text"
                  value={bookmarkName}
                  onChange={(e) => setBookmarkName(e.target.value)}
                  placeholder="Enter a name for this bookmark"
                  autoFocus
                  onKeyDown={(e) => {
                    if (e.key === 'Enter') {
                      handleSaveBookmark();
                    } else if (e.key === 'Escape') {
                      setShowBookmarkModal(false);
                    }
                  }}
                />
              </div>
              <div className="modal-preview">
                <label>Preview</label>
                <div className="preview-content">
                  <div className="preview-query">{searchPattern}</div>
                  {/* Layer functionality removed for bookmark-history branch */}
                </div>
              </div>
            </div>
            <div className="modal-actions">
              <button 
                className="modal-button modal-button-secondary"
                onClick={() => setShowBookmarkModal(false)}
              >
                Cancel
              </button>
              <button 
                className="modal-button modal-button-primary"
                onClick={handleSaveBookmark}
                disabled={!bookmarkName.trim()}
              >
                Save Bookmark
              </button>
            </div>
          </div>
        </div>
      )}
      <div className="bookmarks-list">
        {bookmarks.length === 0 ? (
          <div className="no-bookmarks">
            <p>No bookmarks yet</p>
          </div>
        ) : (
          bookmarks.map((bookmark) => (
            <div key={bookmark.id} className="bookmark-item">
              <div className="bookmark-item-header">
                <div className="bookmark-name">{bookmark.name}</div>
                <div className="bookmark-actions">
                  <button
                    className="icon-button"
                    onClick={() => handleRunBookmark(bookmark)}
                    title="Run Bookmark"
                  >
                    <span className="codicon codicon-play"></span>
                  </button>
                  <button
                    className="icon-button"
                    onClick={() => handleDeleteBookmark(bookmark.id)}
                    title="Delete"
                  >
                    <span className="codicon codicon-trash"></span>
                  </button>
                </div>
              </div>
              <div className="bookmark-item-details">
                <div className="bookmark-query">{bookmark.query}</div>
                <div className="bookmark-meta">
                  <span className="bookmark-timestamp">{formatDate(bookmark.timestamp)}</span>
                  {/* Layer functionality removed for bookmark-history branch */}
                </div>
              </div>
            </div>
          ))
        )}
      </div>
    </div>
  );

  return (
    <div className="container">
      <div className="tabs-header">
        <button
          className={`tab-button ${activeTab === "search" ? "active" : ""}`}
          onClick={() => setActiveTab("search")}
        >
          <span className="codicon codicon-search"></span> Search
        </button>
        <button
          className={`tab-button ${activeTab === "history" ? "active" : ""}`}
          onClick={() => setActiveTab("history")}
        >
          <span className="codicon codicon-history"></span> History
        </button>
        <button
          className={`tab-button ${activeTab === "bookmarks" ? "active" : ""}`}
          onClick={() => setActiveTab("bookmarks")}
        >
          <span className="codicon codicon-bookmark"></span> Bookmarks
        </button>
      </div>
      <div className="tab-content">
        {activeTab === "search" && renderSearchTab()}
        {activeTab === "history" && renderHistoryTab()}
        {activeTab === "bookmarks" && renderBookmarksTab()}
      </div>
    </div>
  );
};

export default App;