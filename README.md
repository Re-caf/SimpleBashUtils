# Project Overview

## Part 1: cat Utility
- **Task**: Develop a `cat` utility supporting all standard and GNU flags.
- **Requirements**:
  - Source/header/build files in `src/cat/`.
  - Output executable: `src/cat/s21_cat`.

## Part 2: grep Utility (Core)
- **Task**: Implement `grep` with flags: `-e`, `-i`, `-v`, `-c`, `-l`, `-n`.
- **Constraints**:
  - Regex via `pcre` or `regex` only.
  - Files in `src/grep/`.
  - Executable: `src/grep/s21_grep`.

## Part 3: grep Extended Flags (Bonus)
- **Task**: Add support for `-h`, `-s`, `-f`, `-o`.
- **Constraints**:
  - Same regex libraries.
  - Files/output location unchanged.

## Part 4: grep Flag Combinations (Bonus)
- **Task**: Handle paired flags (e.g., `-iv`, `-in`).
- **Constraints**:
  - Maintain regex/library rules.
  - Same file structure.
