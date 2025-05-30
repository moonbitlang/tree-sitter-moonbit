import CodeMirror from "./CodeMirror.tsx";
import * as TS from "web-tree-sitter";
import * as React from "react";

type QueryContainerProps = {
  parser: TS.Parser;
};

const QueryContainer: React.FC<QueryContainerProps> = ({ parser }) => {
  const [, setQuery] = React.useState<TS.Query | null>(null);

  const handleQueryChange = (value: string) => {
    if (parser.language) {
      setQuery(new TS.Query(parser.language, value));
    }
  };

  return (
    <div
      id="query-container"
      style={{ visibility: "hidden", position: "absolute" }}
    >
      <div className="panel-header">Query</div>
      <CodeMirror value="" onChange={handleQueryChange} />
    </div>
  );
};

export default QueryContainer;
