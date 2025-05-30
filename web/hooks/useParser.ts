import * as TS from "web-tree-sitter";
import * as React from "react";

export default function useParser() {
  return React.useRef(new TS.Parser());
}
