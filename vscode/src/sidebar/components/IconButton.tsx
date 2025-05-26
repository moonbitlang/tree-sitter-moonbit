import React from "react";
import Codicon from "./Codicon";

interface IconButtonProps {
  icon: string;
  title: string;
  onClick: () => void;
  id?: string;
  className?: string;
}

/**
 * A reusable icon button component with codicon support
 */
export const IconButton: React.FC<IconButtonProps> = ({
  icon,
  title,
  onClick,
  id,
  className = "",
}) => {
  return (
    <button className={`icon-button ${className}`} id={id} title={title} onClick={onClick}>
      <Codicon name={icon} />
    </button>
  );
};

export default IconButton;
