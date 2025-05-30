import * as React from "react";

type LanguageSelectProps = {
  languages: string[];
  onChange?: (language: string) => void;
};

const LanguageSelect: React.FC<LanguageSelectProps> = ({
  languages,
  onChange,
}) => {
  return (
    <select onChange={(e) => onChange?.(e.target.value)}>
      {languages.map((language) => (
        <option key={language} value={language}>
          {language}
        </option>
      ))}
    </select>
  );
};

export default LanguageSelect;
