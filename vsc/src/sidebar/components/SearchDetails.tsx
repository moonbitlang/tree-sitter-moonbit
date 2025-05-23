import React, { useState } from "react";
import InputBox from "./InputBox";
import ControlButton from "./ControlButton";
import IconButton from "./IconButton";

interface SearchDetailsProps {
  includeIgnored: boolean;
  onIncludeIgnoredChange: (value: boolean) => void;
  includePattern: string;
  onIncludePatternChange: (value: string) => void;
  excludePattern: string;
  onExcludePatternChange: (value: string) => void;
}

export const SearchDetails: React.FC<SearchDetailsProps> = ({
  includeIgnored,
  onIncludeIgnoredChange,
  includePattern,
  onIncludePatternChange,
  excludePattern,
  onExcludePatternChange,
}) => {
  const includeControls = (
    <ControlButton icon="book" title="Search only in Open Editors" onClick={() => {}} />
  );

  const excludeControls = (
    <ControlButton
      icon="gear"
      className={includeIgnored ? "active" : ""}
      onClick={() => onIncludeIgnoredChange(!includeIgnored)}
      title={includeIgnored ? "Exclude Ignored Files" : "Include Ignored Files"}
    />
  );

  const [isSearchDetailsExpanded, setIsSearchDetailsExpanded] = useState(true);

  const toggleSearchDetails = () => {
    setIsSearchDetailsExpanded(!isSearchDetailsExpanded);
  };

  return (
    <div className="search-details">
      <div className="search-details-header">
        <IconButton
          icon="ellipsis"
          title="Toggle Search Details"
          onClick={toggleSearchDetails}
          className="search-details-toggle"
        />
      </div>
      <div className={`search-details-section ${isSearchDetailsExpanded ? "" : "collapsed"}`}>
        <InputBox
          value={includePattern}
          onChange={onIncludePatternChange}
          placeholder=""
          controls={includeControls}
          label="files to include"
        />

        <InputBox
          value={excludePattern}
          onChange={onExcludePatternChange}
          placeholder=""
          controls={excludeControls}
          label="files to exclude"
        />
      </div>
    </div>
  );
};

export default SearchDetails;
