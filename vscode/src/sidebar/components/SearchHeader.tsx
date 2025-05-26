import React from "react";
import IconButton from "./IconButton";

interface SearchHeaderProps {
  onRefresh: () => void;
  onClear: () => void;
  onCollapseAll?: () => void;
  onExpandAll?: () => void;
}

export const SearchHeader: React.FC<SearchHeaderProps> = ({
  onRefresh,
  onClear,
  onCollapseAll,
  onExpandAll,
}) => {
  return (
    <div className="search-header">
      <h3>Search</h3>
      <div className="search-actions">
        <IconButton id="refreshButton" icon="refresh" title="Refresh" onClick={onRefresh} />
        <IconButton id="clearButton" icon="clear-all" title="Clear" onClick={onClear} />
        {onCollapseAll && (
          <IconButton
            id="collapseAllButton"
            icon="collapse-all"
            title="Collapse All"
            onClick={onCollapseAll}
          />
        )}
        {onExpandAll && (
          <IconButton
            id="expandAllButton"
            icon="expand-all"
            title="Expand All"
            onClick={onExpandAll}
          />
        )}
      </div>
    </div>
  );
};

export default SearchHeader;
