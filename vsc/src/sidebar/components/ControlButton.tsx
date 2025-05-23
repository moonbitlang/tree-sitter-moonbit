import React from "react";
import Codicon from "./Codicon";

interface ControlButtonProps {
  icon: string;
  title: string;
  onClick?: () => void;
  active?: boolean;
  id?: string;
  className?: string;
}

/**
 * A reusable control button component with codicon support
 */
export const ControlButton: React.FC<ControlButtonProps> = ({
  icon,
  title,
  onClick,
  active = false,
  id,
  className = "",
}) => {
  return (
    <button
      className={`control-button ${active ? "active" : ""} ${className}`}
      id={id}
      title={title}
      onClick={onClick}
    >
      <Codicon name={icon} />
    </button>
  );
};

export default ControlButton;
