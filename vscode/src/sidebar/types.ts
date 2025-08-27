export interface Position {
  line: number;
  character: number;
}

export interface Range {
  start: Position;
  end: Position;
}

export interface Result {
  id: string;
  uri: string;
  range: Range;
  lines: string[];
  searchId?: string; // New, optional field
}

export interface SearchLayer {
  id: string;
  query: string;
  enabled: boolean;
}

export interface SearchOptions {
  includeIgnored: boolean;
  includePattern: string;
  excludePattern: string;
}

export interface SearchStats {
  matchCount: number;
  fileCount: number;
}

// New: bookmark related interfaces
export interface SearchBookmark {
  id: string;
  name: string;
  query: string;
  timestamp: number;
  options: SearchOptions;
  layers?: SearchLayer[]; // New: support multi-layer query bookmarks
}

export interface SearchHistoryItem {
  id: string;
  query: string;
  timestamp: number;
  resultCount: number;
  options: SearchOptions;
  layers?: SearchLayer[]; // New: support multi-layer query history
}

export type Response =
  | {
      type: "insert";
      result: Result;
    }
  | {
      type: "clear";
    }
  | {
      type: "refresh";
    }
  | {
      type: "collapseAll";
    }
  | {
      type: "expandAll";
    }
  | {
      type: "remove";
      result: {
        uri: string;
        id: string;
      };
    }
  | {
      type: "historyLoaded";
      history: SearchHistoryItem[];
    }
  | {
      type: "historyUpdated";
      history: SearchHistoryItem[];
    }
  | {
      type: "bookmarksLoaded";
      bookmarks: SearchBookmark[];
    }
  | {
      type: "bookmarksUpdated";
      bookmarks: SearchBookmark[];
    }
  | {
      type: "searchStarted";
      searchId: string;
    };

export type Request =
  | {
      type: "search";
      value: {
        language: string;
        query: string;
        includePattern: string;
        excludePattern: string;
        layers?: SearchLayer[]; // New: support multi-layer queries
        enableAstPrint?: boolean; // New: control AST printing
      };
    }
  | { type: "clear" }
  | { type: "refresh" }
  | { type: "collapseAll" }
  | { type: "expandAll" }
  | { type: "dismissMatch"; value: { id: string } }
  | { type: "replaceMatch"; value: { id: string, replace: string, enableAstPrint?: boolean } }
  | { type: "replaceAll"; value: { replace: string, enableAstPrint?: boolean } }
  | { type: "openMatch"; value: { uri: string; range: Range } }
  | { type: "loadHistory" }
  | { type: "clearHistory" }
  | { type: "deleteHistoryItem"; value: { id: string } }
  | { type: "loadBookmarks" }
  | { type: "addBookmark"; value: { name: string; query: string; options: SearchOptions; layers?: SearchLayer[] } }
  | { type: "deleteBookmark"; value: { id: string } }
  | { type: "updateResultCount"; value: { searchId: string; count: number } }
  | { type: "updateAstPrint"; value: { enableAstPrint: boolean } }
  // Remove addToHistory message type, history is now completely controlled by backend
  // | { type: "addToHistory"; value: { query: string; options: SearchOptions } }
  | { type: "error"; value: string };
