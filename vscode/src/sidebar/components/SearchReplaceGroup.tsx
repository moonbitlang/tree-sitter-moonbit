import React, { useState } from "react";
import SearchInput from "./SearchInput";
import ReplaceInput from "./ReplaceInput";
import ControlButton from "./ControlButton";

interface SearchReplaceGroupProps {
  searchValue: string;
  replaceValue: string;
  onSearchChange: (value: string) => void;
  onReplaceChange: (value: string) => void;
  onSearch: () => void;
  onReplaceAll?: () => void;
}

export const SearchReplaceGroup: React.FC<SearchReplaceGroupProps> = ({
  searchValue,
  replaceValue,
  onSearchChange,
  onReplaceChange,
  onSearch,
  onReplaceAll,
}) => {
  const [showReplace, setShowReplace] = useState(true);

  const toggleReplace = () => {
    setShowReplace(!showReplace);
  };

  return (
    <div className="search-replace-group">
      <ControlButton
        icon={showReplace ? "chevron-down" : "chevron-right"}
        title="Toggle Replace"
        onClick={toggleReplace}
        className="toggle-replace-button"
      />
      <div className="search-input-container">
        <SearchInput value={searchValue} onChange={onSearchChange} onSearch={onSearch} />
        {showReplace && (
          <ReplaceInput
            value={replaceValue}
            onChange={onReplaceChange}
            onSearch={onSearch}
            onReplaceAll={onReplaceAll}
          />
        )}
      </div>
    </div>
  );
};

export default SearchReplaceGroup;
