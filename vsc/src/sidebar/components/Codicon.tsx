import React from "react";

interface CodiconProps {
  name: string;
  className?: string;
}

/**
 * A reusable component for rendering VSCode codicons
 */
export const Codicon: React.FC<CodiconProps> = ({ name, className = "" }) => {
  return <i className={`codicon codicon-${name} ${className}`}></i>;
};

export default Codicon;
