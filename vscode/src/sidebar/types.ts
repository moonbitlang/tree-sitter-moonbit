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
    };

export type Request =
  | {
      type: "search";
      value: {
        language: string;
        query: string;
        includePattern: string;
        excludePattern: string;
      };
    }
  | { type: "clear" }
  | { type: "refresh" }
  | { type: "collapseAll" }
  | { type: "expandAll" }
  | { type: "dismissMatch"; value: { id: string } }
  | { type: "replaceMatch"; value: { id: string, replace: string } }
  | { type: "openMatch"; value: { uri: string; range: Range } };
