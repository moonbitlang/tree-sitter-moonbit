import React from "react";
import IconButton from "./IconButton";
import { useVSCode } from "../hooks/useVSCode";
import { Range } from "../types";

interface MatchItemProps {
  id: string;
  uri: string;
  range: Range;
  lines: string[];
  onReplace?: (id: string) => void;
  onDismiss?: (id: string) => void;
}

export const MatchItem: React.FC<MatchItemProps> = ({
  id,
  uri,
  range,
  lines,
  onReplace,
  onDismiss,
}) => {
  const vscode = useVSCode();

  const handleClick = () => {
    vscode.postMessage({
      type: "openMatch",
      value: {
        uri,
        range,
      },
    });
  };

  const handleDismiss = () => {
    if (onDismiss) {
      onDismiss(id);
    }
  };

  const handleReplace = () => {
    if (onReplace) {
      onReplace(id);
    }
  };

  return (
    <div className="match-item" onClick={handleClick}>
      <div className="match-content">
        <div className="match-item-actions">
          <IconButton icon="replace" title="Replace match" onClick={handleReplace} />
          <IconButton icon="close" title="Dismiss match" onClick={handleDismiss} />
        </div>
        {lines.map((line, i) => (
          <div key={i} className="match-line">
            {i === 0 && <span className="match-text">{line.slice(0, range.start.character)}</span>}
            <span className="match-highlight">
              {line.slice(
                i === 0 ? range.start.character : 0,
                i === lines.length - 1 ? range.end.character : line.length
              )}
            </span>
            {i === lines.length - 1 && (
              <span className="match-text">{line.slice(range.end.character)}</span>
            )}
          </div>
        ))}
      </div>
    </div>
  );
};

export default MatchItem;
