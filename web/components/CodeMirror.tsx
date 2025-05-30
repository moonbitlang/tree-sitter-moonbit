import * as CM from "codemirror";
import * as React from "react";

type CodeMirrorProps = {
  value: string;
  onChange?: (value: string) => void;
};

const CodeMirror: React.FC<CodeMirrorProps> = ({ value, onChange }) => {
  const editorRef = React.useRef<CM.EditorView | null>(null);
  const parentRef = React.useRef<HTMLDivElement | null>(null);

  React.useEffect(() => {
    if (!editorRef.current) {
      editorRef.current = new CM.EditorView({
        doc: value,
        extensions: [
          CM.basicSetup,
          CM.EditorView.updateListener.of((update) => {
            if (update.docChanged && onChange) {
              onChange(update.state.doc.toString());
            }
          }),
        ],
        parent: parentRef.current!,
      });
      return;
    }
    if (editorRef.current) {
      editorRef.current.dispatch({
        changes: {
          from: 0,
          to: editorRef.current.state.doc.length,
          insert: value,
        },
      });
    }
  }, [value, onChange]);

  return <div ref={parentRef} />;
};

export default CodeMirror;
