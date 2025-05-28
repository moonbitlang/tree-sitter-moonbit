import React, { useState, useEffect } from "react";
import { useVSCode } from "../hooks/useVSCode";
import SearchReplaceGroup from "./SearchReplaceGroup";
import SearchDetails from "./SearchDetails";
import SearchResults from "./SearchResults";
import { SearchOptions, Result, Response } from "../types";

const App: React.FC = () => {
  const vscode = useVSCode();
  const [initialized, setInitialized] = useState(false);
  const [searchPattern, setSearchPattern] = useState("");
  const [replacePattern, setReplacePattern] = useState("");
  const [searchOptions, setSearchOptions] = useState<SearchOptions>({
    includeIgnored: false,
    includePattern: "",
    excludePattern: "",
  });
  const [results, setResults] = useState<Record<string, Result[]>>({});
  const [stats, setStats] = useState({ matchCount: 0, fileCount: 0 });
  const [collapsedFiles, setCollapsedFiles] = useState<Record<string, boolean>>({});

  // Handle messages from extension
  useEffect(() => {
    const handleMessage = (event: MessageEvent<Response>) => {
      const message = event.data;
      switch (message.type) {
        case "insert": {
          setResults((results) => {
            const newResults = {};
            for (const [uri, resultsByUri] of Object.entries(results)) {
              if (uri === message.result.uri) {
                newResults[uri] = [...resultsByUri, message.result];
              } else {
                newResults[uri] = resultsByUri;
              }
            }
            if (!newResults[message.result.uri]) {
              newResults[message.result.uri] = [message.result];
            }
            return newResults;
          });
          setStats((stats) => ({
            matchCount: stats.matchCount + 1,
            fileCount: Object.keys(results).length,
          }));
          setCollapsedFiles((collapsedFiles) => {
            const newCollapsedFiles = { ...collapsedFiles };
            if (!collapsedFiles[message.result.uri]) {
              newCollapsedFiles[message.result.uri] = false;
            }
            return newCollapsedFiles;
          });
          break;
        }
        case "remove": {
          setResults((results) => {
            const newResults = {};
            for (const [uri, resultsByUri] of Object.entries(results)) {
              if (uri === message.result.uri) {
                const newResultsByUri = resultsByUri.filter(
                  (result) => result.id !== message.result.id
                );
                if (newResultsByUri.length > 0) {
                  newResults[uri] = newResultsByUri;
                }
              } else {
                newResults[uri] = resultsByUri;
              }
            }
            return newResults;
          });
          break;
        }
        case "clear":
          setResults({});
          setCollapsedFiles({});
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
      }
    };

    window.addEventListener("message", handleMessage);
    return () => window.removeEventListener("message", handleMessage);
  }, [searchPattern]); // Added searchPattern as dependency for performSearch

  useEffect(() => {
    let matchCount = 0;
    for (const resultsByUri of Object.values(results)) {
      matchCount += resultsByUri.length;
    }
    setStats({
      fileCount: Object.keys(results).length,
      matchCount,
    });
  }, [results]);

  // Save state when inputs or collapsed state changes
  useEffect(() => {
    if (!initialized) return;
    vscode.setState({
      searchPattern,
      replacePattern,
      ...searchOptions,
    });
  }, [searchPattern, replacePattern, searchOptions]);

  // Restore state when component mounts
  useEffect(() => {
    const state = vscode.getState();
    if (state) {
      setSearchPattern(state.searchPattern || "");
      setReplacePattern(state.replacePattern || "");
      setSearchOptions({
        includeIgnored: !!state.includeIgnored,
        includePattern: state.includePattern || "",
        excludePattern: state.excludePattern || "",
      });
    }
    setInitialized(true);
  }, []);

  const performSearch = (searchPattern: string) => {
    if (!searchPattern.trim()) return;

    vscode.postMessage({
      type: "search",
      value: {
        language: "moonbit",
        query: searchPattern,
        includePattern: searchOptions.includePattern,
        excludePattern: searchOptions.excludePattern,
      },
    });
  };

  const clearSearch = () => {
    setSearchPattern("");
    setReplacePattern("");
    setResults({});
    setStats({ matchCount: 0, fileCount: 0 });
    setCollapsedFiles({}); // Clear collapsed state when search is cleared

    vscode.postMessage({
      type: "clear",
    });
  };

  const collapseAll = () => {
    setCollapsedFiles((collapsedFiles) => {
      const newCollapsedFiles = {};
      for (const uri of Object.keys(collapsedFiles)) {
        newCollapsedFiles[uri] = true; // Collapse all files
      }
      return newCollapsedFiles;
    });
  };

  const expandAll = () => {
    setCollapsedFiles((collapsedFiles) => {
      const newCollapsedFiles = {};
      for (const uri of Object.keys(collapsedFiles)) {
        newCollapsedFiles[uri] = false; // Expand all files
      }
      return newCollapsedFiles;
    });
  };

  // Function to toggle collapse state for a specific file
  const toggleFileCollapse = (fileUri: string) => {
    setCollapsedFiles((prev) => ({
      ...prev,
      [fileUri]: !prev[fileUri],
    }));
  };

  const handleReplaceMatch = (id: string) => {
    vscode.postMessage({
      type: "replaceMatch",
      value: { id, replace: replacePattern },
    });
  };

  // Function to dismiss a match
  const handleDismissMatch = (id: string) => {
    vscode.postMessage({
      type: "dismissMatch",
      value: { id },
    });
  };

  return (
    <div className="container">
      <div className="search-container">
        <SearchReplaceGroup
          searchValue={searchPattern}
          replaceValue={replacePattern}
          onSearchChange={(value) => {
            setSearchPattern(value);
            performSearch(value);
          }}
          onReplaceChange={setReplacePattern}
          onSearch={() => {
            performSearch(searchPattern);
          }}
        />

        <SearchDetails
          includeIgnored={searchOptions.includeIgnored}
          onIncludeIgnoredChange={(value) =>
            setSearchOptions({ ...searchOptions, includeIgnored: value })
          }
          includePattern={searchOptions.includePattern}
          onIncludePatternChange={(value) =>
            setSearchOptions({ ...searchOptions, includePattern: value })
          }
          excludePattern={searchOptions.excludePattern}
          onExcludePatternChange={(value) =>
            setSearchOptions({ ...searchOptions, excludePattern: value })
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
    </div>
  );
};

export default App;
