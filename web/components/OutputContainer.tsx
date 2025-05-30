import * as Clusterize from "clusterize.js";
import * as React from "react";

type OutputContainerProps = {
  rows: string[];
};

const OutputContainer: React.FC<OutputContainerProps> = ({ rows }) => {
  const contentRef = React.useRef<HTMLPreElement>(null);
  const scrollRef = React.useRef<HTMLDivElement>(null);
  const clusterRef = React.useRef<Clusterize>(
    new Clusterize({
      rows,
      scrollElem: scrollRef.current!,
      contentElem: contentRef.current!,
    })
  );

  React.useEffect(() => {
    if (clusterRef.current) {
      clusterRef.current.update(rows);
    }
  }, [rows]);

  return (
    <div ref={scrollRef}>
      <div className="panel-header">Tree</div>
      <pre ref={contentRef} className="highlight"></pre>
    </div>
  );
};

export default OutputContainer;
