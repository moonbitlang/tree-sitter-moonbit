import React, { useState } from "react";
import SearchInput from "./SearchInput";
import ReplaceInput from "./ReplaceInput";
import ControlButton from "./ControlButton";

interface SearchLayer {
  id: string;
  query: string;
  enabled: boolean;
}

interface SearchReplaceGroupProps {
  searchValue: string;
  replaceValue: string;
  onSearchChange: (value: string) => void;
  onReplaceChange: (value: string) => void;
  onSearch: () => void;
  onReplaceAll?: () => void;
  searchLayers?: SearchLayer[];
  onSearchLayersChange?: (layers: SearchLayer[]) => void;
}

export const SearchReplaceGroup: React.FC<SearchReplaceGroupProps> = ({
  searchValue,
  replaceValue,
  onSearchChange,
  onReplaceChange,
  onSearch,
  onReplaceAll,
  searchLayers = [],
  onSearchLayersChange,
}) => {
  const [showReplace, setShowReplace] = useState(false);

  const toggleReplace = () => {
    setShowReplace(!showReplace);
  };



  const addSearchLayer = () => {
    const newLayer: SearchLayer = {
      id: Date.now().toString(),
      query: "",
      enabled: true,
    };
    const updatedLayers = [...searchLayers, newLayer];
    onSearchLayersChange?.(updatedLayers);
  };

  const removeSearchLayer = (id: string) => {
    const updatedLayers = searchLayers.filter(layer => layer.id !== id);
    onSearchLayersChange?.(updatedLayers);
  };



  const updateSearchLayer = (id: string, updates: Partial<SearchLayer>) => {
    const updatedLayers = searchLayers.map(layer =>
      layer.id === id ? { ...layer, ...updates } : layer
    );
    onSearchLayersChange?.(updatedLayers);
  };

  return (
    <div className="search-replace-group">
      {/* 搜索区块 */}
      <div className="search-section">
        {/* 主搜索行：+按钮 + 搜索框 */}
        <div className="search-row">
          <ControlButton
            icon="add"
            title="Add Search Layer"
            onClick={addSearchLayer}
            className="add-layer-button"
          />
          <div className="search-input-wrapper">
            <SearchInput value={searchValue} onChange={onSearchChange} onSearch={onSearch} />
          </div>
        </div>
        
        {/* 额外的搜索层 */}
        {searchLayers.map((layer, index) => (
          <div key={layer.id} className="search-layer-row">
            <ControlButton
              icon="remove"
              title="Remove Search Layer"
              onClick={() => removeSearchLayer(layer.id)}
              className="remove-layer-button"
            />
            <div className="search-input-wrapper">
              <SearchInput
                value={layer.query}
                onChange={(value) => updateSearchLayer(layer.id, { query: value })}
                onSearch={onSearch}
                placeholder={`Layer ${index + 2} query`}
              />
            </div>
          </div>
        ))}
        

      </div>
      
      {/* Replace区块 */}
      <div className="replace-section">
        <div className="replace-controls">
          <ControlButton
            icon={showReplace ? "chevron-down" : "chevron-right"}
            title="Toggle Replace"
            onClick={toggleReplace}
            className="toggle-replace-button"
          />
        </div>
        
        {showReplace && (
          <div className="replace-input-container">
            <ReplaceInput
              value={replaceValue}
              onChange={onReplaceChange}
              onSearch={onSearch}
              onReplaceAll={onReplaceAll}
            />
          </div>
        )}
      </div>
    </div>
  );
};

export default SearchReplaceGroup;
