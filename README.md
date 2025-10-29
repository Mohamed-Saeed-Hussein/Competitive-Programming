# Competitive-Programming

A personal repository of competitive programming templates and solved problems organized by topic. This collection contains clean, well-commented C++ snippets and utility implementations I use for contests and practice.

## Contents

- Bitwise/: common bitmask and bit-manipulation snippets.
- Data Structure/: implementations for DSU, Fenwick tree, segment tree, Mo's algorithm, mex, sparse table, etc.
- Math and Number Theory/: combinatorics, FFT, modular arithmetic, matrix exponentiation, number theory helpers.
- Strings/: string algorithms such as KMP, Z-function, Aho–Corasick, rolling hash, Trie.
- Templates/: contest template files and useful utilities (policy-based data structures, fast IO snippets).

## How to use

Each file is a standalone C++ source you can compile and run. For a single-file compile with g++ (recommended for contests):

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pipe -static -s path\to\file.cpp -o file.exe
.
\# then run:
.\file.exe
```

Notes:

- Remove `-static` on platforms where static linking causes issues (Windows/msys/mingw may need different flags).
- For local testing, you can omit `-s` to keep debug symbols.

## Conventions

- Filenames are grouped by topic folders. Each file typically contains a single algorithm or data structure with a minimal main() for quick testing.
- Prefer small, well-documented functions and self-contained examples that are easy to copy into contest solutions.

## Contributing

If you want to contribute:

1. Fork the repository.
2. Add or improve an algorithm in the matching directory.
3. Keep files short and focused; include a short comment describing complexity.
4. Open a pull request explaining the change.

## License

This repo has no explicit license file. If you want to reuse code from here, ask the owner or add a license via PR.

---

If you'd like, I can also:

- add a CONTRIBUTING.md and LICENSE file,
- create a small script to compile and run a chosen file,
- or group files by difficulty/tags in the README.

Tell me which you'd prefer and I can add it.
