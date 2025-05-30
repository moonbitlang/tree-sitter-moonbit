import * as TS from "web-tree-sitter";
import * as React from "react";

type TreeRowProps = {
  indent: number;
  field: string | null;
  node: TS.Node;
  highlighted: Map<number, boolean>;
};

const TreeRow: React.FC<TreeRowProps> = ({
  indent,
  field,
  node,
  highlighted,
}) => {
  let className = node.isError
    ? "node-link error"
    : node.isMissing
    ? "node-link missing"
    : node.isNamed
    ? "node-link named"
    : "node-link anonymous";
  if (highlighted.has(node.id)) {
    className += " highlighted";
  }
  const displayName = node.isMissing
    ? node.isNamed
      ? node.type
      : `"${node.type}"`
    : node.type;
  const fieldName = field ? `${field}: ` : "";
  const startPosition = node.startPosition;
  const endPosition = node.endPosition;
  const dataRange = `${startPosition.row},${startPosition.column},${endPosition.row},${endPosition.column}`;
  return (
    <div className="tree-row">
      {"  ".repeat(indent)}
      {fieldName}
      <a
        className={className}
        href="#"
        data-id={node.id}
        data-range={dataRange}
      >
        {displayName}
      </a>
      <span className="position-info">
        [{startPosition.row}, {startPosition.column}] - [{endPosition.row},{" "}
        {endPosition.column}]
      </span>
      {node.children.length > 0 &&
        node.children.map((child, index) => {
          return (
            child && (
              <TreeRow
                key={`${node.id}-${index}`}
                indent={indent + 1}
                field={node.fieldNameForChild(index)}
                node={child}
                highlighted={highlighted}
              />
            )
          );
        })}
    </div>
  );
};

export default TreeRow;
