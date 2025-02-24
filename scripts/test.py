import subprocess
from pathlib import Path
import sys


def parse_file(path: Path):
    try:
        subprocess.run(
            ["pnpm", "exec", "tree-sitter", "parse", path],
            capture_output=True,
            check=True,
            text=True,
        )
        print(f"[ OK ] {path}")
    except subprocess.CalledProcessError as e:
        print(f"[Fail] {path}")
        print("==== stderr ====")
        print(f"{e.stderr}")
        print("==== stdout ====")
        print(e.stdout)
        sys.exit(1)


def parse_directory(directory: Path):
    for file in directory.iterdir():
        if file.is_dir():
            parse_directory(file)
            continue
        if file.suffix == ".mbt":
            parse_file(file)
            continue


def main():
    parse_directory(Path(sys.argv[1]))


if __name__ == "__main__":
    main()
