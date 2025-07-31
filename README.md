# MathForge
A Modern C++20 Mathematical Proof Language Compiler

[![Build Status](https://github.com/debjit-1004/MathForge/workflows/CI/badge.svg)](https://github.com/debjit-1004/MathForge/actions)
[![Coverage Status](https://codecov.io/gh/debjit-1004/MathForge/branch/master/graph/badge.svg)](https://codecov.io/gh/debjit-1004/MathForge)
[![License](https://img.shields.io/github/license/debjit-1004/MathForge)](LICENSE)

## Overview

MathForge is a compiler for a mathematical proof-oriented programming language designed to help mathematicians write, verify, and publish formal proofs. It combines the rigor of formal mathematics with modern programming language design principles.

## Features

- **Mathematical Type System**: Native support for mathematical objects (sets, functions, relations)
- **Proof Verification**: Automated proof checking with detailed error reporting
- **Unicode Support**: Full support for mathematical Unicode symbols (∀, ∃, ∈, ⊆, →, ↔)
- **LaTeX Output**: Generate publication-ready mathematical documents
- **Modern C++20**: Built with modern C++ best practices and performance in mind

## Quick Start

### Prerequisites

- CMake 3.20 or higher
- C++20 compatible compiler (GCC 10+, Clang 11+, MSVC 2019+)
- Git

### Building

```bash
git clone https://github.com/debjit-1004/MathForge.git
cd MathForge
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Running Tests

```bash
cd build
ctest --verbose
```

### Basic Usage

```bash
./mathforge input.mf --output proof.tex --verify
```

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

## Language Example

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

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## Documentation

- [Language Reference](docs/language-reference.md)
- [API Documentation](docs/api/index.html)
- [Developer Guide](docs/developer-guide.md)
- [Examples](examples/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by formal proof assistants like Coq, Lean, and Isabelle/HOL
- Built with modern C++20 features and best practices
- Special thanks to the mathematical logic and formal methods community
