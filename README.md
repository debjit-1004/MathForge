# MathForge
A Modern C++20 Mathematical Proof Language Compiler

[![Build Status](https://github.com/debjit-1004/MathForge/workflows/CI/badge.svg)](https://github.com/debjit-1004/MathForge/actions)
[![Coverage Status](https://codecov.io/gh/debjit-1004/MathForge/branch/master/graph/badge.svg)](https://codecov.io/gh/debjit-1004/MathForge)
[![License](https://img.shields.io/github/license/debjit-1004/MathForge)](LICENSE)

## Overview

MathForge is a compiler for a mathematical proof-oriented programming language designed to help mathematicians write, verify, and publish formal proofs. It combines the rigor of formal mathematics with modern programming language design principles.

## Feature Status (Current vs Planned)

Implemented (early skeleton):
- CLI driver (argument parsing, file loading, debug output)
- Lexer with baseline tokenization (keywords, identifiers, numbers, operators, delimiters, NEWLINE / INDENT / DEDENT, partial Unicode placeholder handling)
- Core utilities (version, exception types)
- Unit tests for core + lexer (position tracking, keywords, operators)

Not Yet Implemented (planned / roadmap):
- Parser (currently `parse()` throws "Parser not yet implemented")
- AST node hierarchy usage
- Semantic analysis (symbol table, type system)
- Proof verification engine
- LaTeX / other code generation (only stubs exist)
- Rich diagnostics (source spans, colored errors)
- Full Unicode math symbol normalization

The original vision includes: mathematical type system, proof verification, Unicode math, and LaTeX output. These are planned but not functional yet—this repository is presently at the lexing stage.

## Quick Start

### Prerequisites

- CMake 3.20 or higher
- C++20 compatible compiler (GCC 10+, Clang 11+, MSVC 2019+)
- Git

### Building (Out-of-Source)

```bash
git clone https://github.com/debjit-1004/MathForge.git
cd MathForge
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
```

Why Debug first? Easier for early development & test diagnostics. Use `-DCMAKE_BUILD_TYPE=Release` later for performance.

### Running Tests

From the repository root:
```bash
ctest --test-dir build --output-on-failure
```

Run only lexer tests:
```bash
ctest --test-dir build -R Lexer
```

We provide a helper script that also cleans transient CTest logs:
```bash
./tools/run_tests.sh -R Lexer
```

### Basic Usage (Current Behavior)

Current pipeline stops after lexing because the parser is not yet implemented:
```bash
./build/bin/mathforge examples/pythagorean.mf
```
Expected (for now): debug lines ending with a syntax error like:
```
ERROR: Syntax error: Parser not yet implemented
```
This is the intentional failure point until the Parser MVP lands.

## Project Structure

```
MathForge/
├── src/                    # Source code
│   ├── core/              # Core utilities and base classes
│   ├── lexer/             # Tokenization and lexical analysis
│   ├── parser/            # Syntax analysis and AST generation
│   ├── ast/               # Abstract syntax tree definitions
│   ├── semantic/          # Semantic analysis and type checking
│   ├── proof/             # Proof verification engine
│   ├── codegen/           # Code generation (LaTeX, etc.)
│   └── cli/               # Command-line interface
├── include/               # Public header files
├── tests/                 # Unit and integration tests
├── docs/                  # Documentation
├── examples/              # Example MathForge programs
└── tools/                 # Development tools and scripts
```

## Language Example (Design Goal)

```mathforge
theorem pythagorean_theorem:
  ∀ a, b, c : ℝ⁺, (right_triangle(a, b, c) → a² + b² = c²)

proof:
  assume a, b, c : ℝ⁺
  assume right_triangle(a, b, c)
  
  by geometric_construction:
    let square_c := square(c)
    let square_a := square(a)
    let square_b := square(b)
    
  by area_calculation:
    area(square_c) = area(square_a) + area(square_b) + 4 * area(triangle(a, b))
    
  simplifying:
    c² = a² + b² + 4 * (½ * a * b)
    c² = a² + b² + 2ab
    
  by construction_constraint:
    area(square_c) = area(square_a) + area(square_b)
    
  therefore:
    c² = a² + b²
QED
```

## Showing Project Progress Right Now

To demonstrate tangible progress even at the lexer-only stage:

1. Build succeeds & modular libraries exist:
  ```bash
  ls build/src/*/libmathforge_*.a
  ```
2. Lexer processes files and reports token count:
  ```bash
  echo "theorem t: proof: assume x = x therefore x = x qed" > simple.mf
  ./build/bin/mathforge simple.mf
  ```
  Output ends with parser stub error (expected).
3. Unit tests pass for implemented components:
  ```bash
  ctest --test-dir build -R Lexer --output-on-failure
  ```
4. Intentional, controlled stop at parser stage communicates the next milestone clearly.

Want a richer artifact now? See the open issue to add a `--dump-tokens` development flag.

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines, and consult `ReadItCauseItsImportant.md` for an up-to-date status snapshot & roadmap.

## Documentation

- Status & roadmap: `ReadItCauseItsImportant.md`
- Language Reference (planned): `docs/language-reference.md`
- Developer Guide: `docs/developer-guide.md`
- Examples: `examples/`

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by formal proof assistants like Coq, Lean, and Isabelle/HOL
- Built with modern C++20 features and best practices
- Special thanks to the mathematical logic and formal methods community
