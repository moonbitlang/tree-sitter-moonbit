import React from "react";
import { Result } from "../types";
import MatchItem from "./MatchItem";
import Codicon from "./Codicon";

interface FileItemProps {
  file: string;
  matches: Result[];
  collapsed: boolean;
  onToggleCollapse: () => void;
  onReplaceMatch?: (id: string) => void;
  onDismissMatch?: (id: string) => void;
}

export const FileItem: React.FC<FileItemProps> = ({
  file,
  matches,
  collapsed,
  onToggleCollapse,
  onReplaceMatch,
  onDismissMatch,
}) => {
  return (
    <div className={`file-item ${collapsed ? "collapsed" : ""}`}>
      <div className="file-header" onClick={onToggleCollapse}>
        <span className="expander">
          <Codicon name={`chevron-${collapsed ? "right" : "down"}`} />
        </span>
        <span className="file-name">{file}</span>
        <span className="match-count">{matches.length}</span>
      </div>
      <div className="match-list">
        {matches.map((match) => (
          <MatchItem
            key={`${match.uri}-${match.id}`}
            id={match.id}
            uri={match.uri}
            range={match.range}
            lines={match.lines}
            onReplace={onReplaceMatch}
            onDismiss={onDismissMatch}
          />
        ))}
      </div>
    </div>
  );
};

export default FileItem;
