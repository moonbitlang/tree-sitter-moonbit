#!/usr/bin/env python3

import subprocess
import json
from pathlib import Path


def main():
    tree_sitter = json.loads((Path(".") / "tree-sitter.json").read_text())

    processes = []
    for grammar in tree_sitter["grammars"]:
        process = subprocess.Popen(["tree-sitter", "test"], cwd=grammar["path"])
        processes.append(process)

    for process in processes:
        process.wait()


if __name__ == "__main__":
    main()
