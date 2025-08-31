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

  // Parse match markers and highlight - handle cross-line matches
  const parseMatchLines = (lines: string[]) => {
    const processedLines: Array<Array<{text: string, isMatch: boolean}>> = [];
    
    // Find the first [MATCH_START] and last [MATCH_END] across all lines
    let firstStartLine = -1;
    let firstStartPos = -1;
    let lastEndLine = -1;
    let lastEndPos = -1;
    
    // Find first [MATCH_START]
    for (let i = 0; i < lines.length; i++) {
      const startPos = lines[i].indexOf('[MATCH_START]');
      if (startPos !== -1) {
        firstStartLine = i;
        firstStartPos = startPos;
        break;
      }
    }
    
    // Find last [MATCH_END]
    for (let i = lines.length - 1; i >= 0; i--) {
      const endPos = lines[i].indexOf('[MATCH_END]');
      if (endPos !== -1) {
        lastEndLine = i;
        lastEndPos = endPos;
        break;
      }
    }
    
    // Process each line
    lines.forEach((line, lineIndex) => {
      const parts: Array<{text: string, isMatch: boolean}> = [];
      
      if (firstStartLine === -1 || lastEndLine === -1) {
        // No markers found, return whole line as non-match
        parts.push({ text: line, isMatch: false });
      } else if (lineIndex < firstStartLine || lineIndex > lastEndLine) {
        // Line is outside the match range
        parts.push({ text: line, isMatch: false });
      } else if (lineIndex === firstStartLine && lineIndex === lastEndLine) {
        // Start and end markers are on the same line
        const beforeStart = line.slice(0, firstStartPos);
        const matchText = line.slice(firstStartPos + 13, lastEndPos);
        const afterEnd = line.slice(lastEndPos + 11);
        
        if (beforeStart) parts.push({ text: beforeStart, isMatch: false });
        if (matchText) parts.push({ text: matchText, isMatch: true });
        if (afterEnd) parts.push({ text: afterEnd, isMatch: false });
      } else if (lineIndex === firstStartLine) {
        // First line: from [MATCH_START] to end
        const beforeStart = line.slice(0, firstStartPos);
        const matchText = line.slice(firstStartPos + 13);
        
        if (beforeStart) parts.push({ text: beforeStart, isMatch: false });
        if (matchText) parts.push({ text: matchText, isMatch: true });
      } else if (lineIndex === lastEndLine) {
        // Last line: from start to [MATCH_END]
        if (lastEndPos === 0) {
          // [MATCH_END] is at the very beginning of the line, skip this line entirely
          parts.push({ text: line, isMatch: false });
        } else {
          // [MATCH_END] is somewhere in the middle or end of the line
          const matchText = line.slice(0, lastEndPos);
          const afterEnd = line.slice(lastEndPos + 11);
          
          if (matchText) parts.push({ text: matchText, isMatch: true });
          if (afterEnd) parts.push({ text: afterEnd, isMatch: false });
      }
          } else {
        // Middle lines: entire line is match
        parts.push({ text: line, isMatch: true });
      }
      
      // If no parts were created, return the whole line as non-match
      if (parts.length === 0) {
        parts.push({ text: line, isMatch: false });
      }
      
      processedLines.push(parts);
    });
    
    return processedLines;
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
        {(() => {
          // Parse match markers and highlight - handle cross-line matches
          const processedLines = parseMatchLines(lines);
          
          return processedLines.map((lineParts, i) => (
            <div key={i} className="match-line">
              {lineParts.map((part, partIndex) => (
                <span 
                  key={partIndex} 
                  className={part.isMatch ? "match-highlight" : "match-text"}
                >
                  {part.text}
                </span>
              ))}
            </div>
          ));
        })()}
      </div>
    </div>
  );
};

export default MatchItem;

