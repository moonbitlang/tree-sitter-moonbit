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

    exit_code = 0
    for process in processes:
        return_code = process.wait()
        # Wait for every grammar, but preserve the first child failure for CI.
        if return_code != 0 and exit_code == 0:
            exit_code = return_code

    return exit_code


if __name__ == "__main__":
    raise SystemExit(main())
