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
  searchId?: string; // 新增，可选字段
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

// 新增：书签相关接口
export interface SearchBookmark {
  id: string;
  name: string;
  query: string;
  timestamp: number;
  options: SearchOptions;
  layers?: SearchLayer[]; // 新增：支持多层查询书签
}

export interface SearchHistoryItem {
  id: string;
  query: string;
  timestamp: number;
  resultCount: number;
  options: SearchOptions;
  layers?: SearchLayer[]; // 新增：支持多层查询历史记录
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
    };

export type Request =
  | {
      type: "search";
      value: {
        language: string;
        query: string;
        includePattern: string;
        excludePattern: string;
        layers?: SearchLayer[]; // 新增：支持多层查询
      };
    }
  | { type: "clear" }
  | { type: "refresh" }
  | { type: "collapseAll" }
  | { type: "expandAll" }
  | { type: "dismissMatch"; value: { id: string } }
  | { type: "replaceMatch"; value: { id: string, replace: string } }
  | { type: "openMatch"; value: { uri: string; range: Range } }
  | { type: "loadHistory" }
  | { type: "clearHistory" }
  | { type: "deleteHistoryItem"; value: { id: string } }
  | { type: "loadBookmarks" }
  | { type: "addBookmark"; value: { name: string; query: string; options: SearchOptions; layers?: SearchLayer[] } }
  | { type: "deleteBookmark"; value: { id: string } }
  // 移除 addToHistory 消息类型，历史记录现在完全由后端控制
  // | { type: "addToHistory"; value: { query: string; options: SearchOptions } }
  | { type: "error"; value: string };
