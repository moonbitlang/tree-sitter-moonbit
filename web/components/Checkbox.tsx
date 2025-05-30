import * as React from "react";

type CheckboxProps = {
  label: string;
  checked: boolean;
  onChange: (event: React.ChangeEvent<HTMLInputElement>) => void;
};

const Checkbox: React.FC<CheckboxProps> = () => {
  return (
    <div>
      <input type="checkbox" id="checkbox" />
      <label htmlFor="checkbox">Checkbox</label>
    </div>
  );
};

export default Checkbox;
