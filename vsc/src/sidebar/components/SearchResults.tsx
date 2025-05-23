import React from "react";
import { Result, SearchStats } from "../types";
import FileItem from "./FileItem";

interface SearchResultsProps {
  results: Record<string, Result[]>;
  stats: SearchStats;
  collapsedFiles: Record<string, boolean>;
  onToggleCollapse: (fileUri: string) => void;
  onReplaceMatch?: (id: string) => void;
  onDismissMatch?: (id: string) => void;
}

export const SearchResults: React.FC<SearchResultsProps> = ({
  results,
  stats,
  collapsedFiles,
  onToggleCollapse,
  onReplaceMatch,
  onDismissMatch,
}) => {
  if (Object.keys(results).length === 0) {
    return (
      <div className="no-results" id="noResultsMessage">
        No results found yet. Try searching for something.
      </div>
    );
  }

  return (
    <div className="search-results">
      <div className="search-info">
        <span>
          {stats.matchCount} results in {stats.fileCount} files
        </span>
      </div>

      {Object.entries(results).map(([file, matches]) => (
        <FileItem
          key={file}
          file={file}
          matches={matches}
          collapsed={!!collapsedFiles[file]}
          onToggleCollapse={() => onToggleCollapse(file)}
          onReplaceMatch={onReplaceMatch}
          onDismissMatch={onDismissMatch}
        />
      ))}
    </div>
  );
};

export default SearchResults;
