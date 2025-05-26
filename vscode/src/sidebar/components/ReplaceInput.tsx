import React from "react";
import InputBox from "./InputBox";
import ControlButton from "./ControlButton";

interface ReplaceInputProps {
  value: string;
  onChange: (value: string) => void;
  onSearch: () => void;
  onReplaceAll?: () => void;
}

export const ReplaceInput: React.FC<ReplaceInputProps> = ({
  value,
  onChange,
  onSearch,
  onReplaceAll,
}) => {
  const replaceControls = (
    <>
      <ControlButton
        id="replaceAllButton"
        icon="replace-all"
        title="Replace All"
        onClick={onReplaceAll}
      />
    </>
  );

  return (
    <InputBox
      id="replaceInput"
      placeholder="Replace"
      value={value}
      onChange={onChange}
      multiline={true}
      onSubmit={onSearch}
      className="replace"
      controls={replaceControls}
    />
  );
};

export default ReplaceInput;
