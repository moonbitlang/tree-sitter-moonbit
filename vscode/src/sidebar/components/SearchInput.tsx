import React from "react";
import InputBox from "./InputBox";

interface SearchInputProps {
  value: string;
  onChange: (value: string) => void;
  onSearch: () => void;
  placeholder?: string;
}

export const SearchInput: React.FC<SearchInputProps> = ({ value, onChange, onSearch, placeholder = "Search (Press Enter to search)" }) => {
  return (
    <InputBox
      id="searchInput"
      placeholder={placeholder}
      value={value}
      onChange={onChange}
      multiline={true}
      onSubmit={onSearch}
    />
  );
};

export default SearchInput;
