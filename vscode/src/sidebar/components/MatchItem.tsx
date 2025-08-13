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

  // Parse match markers and highlight
  const parseMatchLine = (line: string) => {
    const parts: Array<{text: string, isMatch: boolean}> = [];
    let currentIndex = 0;
    
    // Find match markers
    const matchStartIndex = line.indexOf('[MATCH_START]');
    const matchEndIndex = line.indexOf('[MATCH_END]');
    
    if (matchStartIndex !== -1 && matchEndIndex !== -1) {
      // Case with match markers
              // Text before match start
      if (matchStartIndex > 0) {
        parts.push({
          text: line.slice(0, matchStartIndex),
          isMatch: false
        });
      }
      
              // Matched text
      parts.push({
        text: line.slice(matchStartIndex + 13, matchEndIndex), // 13 = '[MATCH_START]'.length
        isMatch: true
      });
      
              // Text after match end
      if (matchEndIndex + 11 < line.length) { // 11 = '[MATCH_END]'.length
        parts.push({
          text: line.slice(matchEndIndex + 11),
          isMatch: false
        });
      }
          } else {
        // Case without match markers, entire line not highlighted
      parts.push({
        text: line,
        isMatch: false
      });
    }
    
    return parts;
  };

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
        {lines.map((line, i) => {
          // Parse match markers and highlight
          const parts = parseMatchLine(line);
          return (
            <div key={i} className="match-line">
              {parts.map((part, partIndex) => (
                <span 
                  key={partIndex} 
                  className={part.isMatch ? "match-highlight" : ""}
                >
                  {part.text}
                </span>
              ))}
            </div>
          );
        })}
      </div>
    </div>
  );
};

export default MatchItem;
