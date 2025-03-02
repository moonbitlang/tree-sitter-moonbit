import sys
from pathlib import Path
import re

include_directories = [
    '.',
    '../../src',
]


already_included = set()


def try_include(file_dir: Path, include_path : str) -> list[str]:
    for include_dir in include_directories:
        include_file = file_dir / include_dir / include_path
        if include_file.exists():
            if include_file in already_included:
                return []
            print(f"Including {include_path}")
            already_included.add(include_file)
            return include_file.read_text().splitlines()
    print(f"Warning: Included file {include_path} not found.")
    return []


def expand_includes(file_path: Path) -> list[str]:
    include_pattern = re.compile(r'#\s*include\s+"([^"]+)"')
    file_dir = Path(file_path).parent

    def read_file(file: Path) -> list[str]:
        return file.read_text().splitlines()

    def process_file(lines: list[str]):
        expanded_lines: list[str] = []
        for line in lines:
            match = include_pattern.match(line)
            if match:
                included_lines = try_include(file_dir, match.group(1))
                expanded_lines.extend(process_file(included_lines))
            else:
                expanded_lines.append(line)
        return expanded_lines

    original_lines = read_file(file_path)
    return process_file(original_lines)

def main():
    preprocess_lines = expand_includes(Path(sys.argv[1]));
    preprocess_text = "\n".join(preprocess_lines)
    Path(sys.argv[2]).write_text(preprocess_text)

if __name__ == "__main__":
    main()
