# MathForge Developer Guide

## Architecture Overview

MathForge is designed as a modular compiler with clear separation of concerns:

```
Input (.mf) → Lexer → Parser → AST → Semantic Analysis → Proof Verification → Code Generation → Output
```

## Module Descriptions

### Core Module (`src/core/`)
- **Purpose**: Fundamental utilities used throughout the system
- **Key Components**:
  - `Logger`: Thread-safe logging system with multiple levels
  - `Version`: Version and build information
  - `Exceptions`: Custom exception hierarchy for error handling

### Lexer Module (`src/lexer/`)
- **Purpose**: Tokenization of MathForge source code
- **Key Components**:
  - `Token`: Token type definitions and utilities
  - `Lexer`: Main lexical analyzer class
- **Features**:
  - Unicode mathematical symbol support
  - Error recovery and reporting
  - Position tracking for diagnostics

### Parser Module (`src/parser/`)
- **Purpose**: Syntax analysis and AST construction
- **Key Components**:
  - `Parser`: Recursive descent parser
- **Features**:
  - Mathematical expression parsing with precedence
  - Proof structure recognition
  - Error recovery with meaningful messages

### AST Module (`src/ast/`)
- **Purpose**: Abstract syntax tree node definitions
- **Key Components**:
  - `Node`: Base AST node class
  - `Expression`: Mathematical expression nodes
  - `Statement`: Proof statement nodes
  - `Visitor`: Visitor pattern for AST traversal

### Semantic Module (`src/semantic/`)
- **Purpose**: Type checking and semantic analysis
- **Key Components**:
  - `Analyzer`: Main semantic analyzer
  - `SymbolTable`: Symbol table management
  - `TypeChecker`: Mathematical type system

### Proof Module (`src/proof/`)
- **Purpose**: Mathematical proof verification
- **Key Components**:
  - `Verifier`: Main proof verification engine
  - `ProofEngine`: Core proof logic
  - `LogicRules`: Mathematical logic rule definitions

### Code Generation Module (`src/codegen/`)
- **Purpose**: Output generation (LaTeX, reports)
- **Key Components**:
  - `LatexGenerator`: LaTeX output generation
  - `GeneratorBase`: Base class for generators

### CLI Module (`src/cli/`)
- **Purpose**: Command-line interface
- **Key Components**:
  - `Application`: Main CLI application class

## Building the Project

### Prerequisites
- CMake 3.20+
- C++20 compatible compiler
- Git

### Build Steps
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Running Tests
```bash
cd build
ctest --verbose
```

## Contributing

### Code Style
- Follow modern C++20 practices
- Use RAII for resource management
- Prefer `const` and `constexpr` where possible
- Use smart pointers for dynamic allocation

### Error Handling
- Use the custom exception hierarchy
- Provide meaningful error messages
- Include position information for user-facing errors

### Testing
- Write unit tests for all new functionality
- Use Google Test framework
- Maintain high test coverage

### Documentation
- Document all public APIs with Doxygen comments
- Update this guide when adding new modules
- Provide examples for complex features
