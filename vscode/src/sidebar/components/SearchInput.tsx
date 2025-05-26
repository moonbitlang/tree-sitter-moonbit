import React from "react";
import InputBox from "./InputBox";

interface SearchInputProps {
  value: string;
  onChange: (value: string) => void;
  onSearch: () => void;
}

export const SearchInput: React.FC<SearchInputProps> = ({ value, onChange, onSearch }) => {
  return (
    <InputBox
      id="searchInput"
      placeholder="Search"
      value={value}
      onChange={onChange}
      multiline={true}
      onSubmit={onSearch}
    />
  );
};

export default SearchInput;
