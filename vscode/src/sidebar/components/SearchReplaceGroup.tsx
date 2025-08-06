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
  const [showReplace, setShowReplace] = useState(true);
  const [showLayers, setShowLayers] = useState(false);

  const toggleReplace = () => {
    setShowReplace(!showReplace);
  };

  const toggleLayers = () => {
    setShowLayers(!showLayers);
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
      <div className="search-controls">
      <ControlButton
        icon={showReplace ? "chevron-down" : "chevron-right"}
        title="Toggle Replace"
        onClick={toggleReplace}
        className="toggle-replace-button"
      />
        <ControlButton
          icon={showLayers ? "chevron-down" : "chevron-right"}
          title="Toggle Search Layers"
          onClick={toggleLayers}
          className="toggle-layers-button"
        />
      </div>
      <div className="search-input-container">
        <SearchInput value={searchValue} onChange={onSearchChange} onSearch={onSearch} />
        {showReplace && (
          <ReplaceInput
            value={replaceValue}
            onChange={onReplaceChange}
            onSearch={onSearch}
            onReplaceAll={onReplaceAll}
          />
        )}
        {showLayers && (
          <div className="search-layers-container">
            <div className="search-layers-header">
              <h4>Search Layers</h4>
              <ControlButton
                icon="add"
                title="Add Search Layer"
                onClick={addSearchLayer}
                className="add-layer-button"
              />
            </div>
            <div className="search-layers-list">
              {searchLayers.map((layer, index) => (
                <div key={layer.id} className="search-layer-item">
                  <div className="search-layer-header">
                    <span className="search-layer-label">Layer {index + 1}</span>
                    <div className="search-layer-controls">
                      <ControlButton
                        icon={layer.enabled ? "eye" : "eye-closed"}
                        title={layer.enabled ? "Disable Layer" : "Enable Layer"}
                        onClick={() => updateSearchLayer(layer.id, { enabled: !layer.enabled })}
                        className="toggle-layer-button"
                      />
                      <ControlButton
                        icon="trash"
                        title="Remove Layer"
                        onClick={() => removeSearchLayer(layer.id)}
                        className="remove-layer-button"
                      />
                    </div>
                  </div>
                  <SearchInput
                    value={layer.query}
                    onChange={(value) => updateSearchLayer(layer.id, { query: value })}
                    onSearch={onSearch}
                    placeholder={`Layer ${index + 1} query`}
                  />
                </div>
              ))}
              {searchLayers.length === 0 && (
                <div className="no-layers-message">
                  <p>No search layers yet. Click the + button to add one.</p>
                </div>
              )}
            </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default SearchReplaceGroup;
