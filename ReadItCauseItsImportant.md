# MathForge Project Guide

## 1. What MathForge Is
A modular C++20 compiler toolchain for a mathematical proof language (`.mf`) targeting:
1. Lexing (token stream)
2. Parsing → AST
3. Semantic analysis (symbols, types)
4. Proof verification (logic rules)
5. Code generation (LaTeX + summary)
6. Diagnostics (rich errors)
7. CLI orchestration

Goal: Author, (eventually) verify, and export formal-style mathematical proofs (not a CAS/calculator).

## 2. Current Implementation Status (Active Branch)
Component | Status | Notes
--------- | ------ | -----
CLI / Driver | Partial | Parses args, reads file, emits debug; logging temporarily bypassed.
Lexer | Implemented (baseline) | Tokens, position tracking, passes unit tests; partial Unicode handling.
Parser | Not implemented | `parse()` throws “Parser not yet implemented”.
AST | Stub | Node hierarchy & visitor not populated/used.
Semantic Analyzer | Stub | Symbol table / type checker placeholders.
Proof Verifier | Stub | No rule logic; placeholders only.
Code Generation | Stub | LaTeX generator returns static template; not wired end‑to‑end; no `.out` emission.
Diagnostics | Minimal | Plain exception messages; no source span rendering.
Tests | Partial | Core + lexer tests pass; no parser/semantic/proof/codegen tests yet.
Examples | Present | Only lexed; pipeline stops at parser stub.

## 3. What the Tool Outputs Today
Running:
```
./mathforge <file>.mf
```
Behavior:
- Reads file
- Lexes and reports token count (via debug output)
- Stops with SyntaxException from unimplemented parser
No AST, no verification, no LaTeX, no `.out` file yet.

Exit: Non‑zero (expected until parser exists).

## 4. Near-Term MVP (Minimal Parser Path)
Implement:
- Theorem + proof block grammar (ASCII first)
- Basic AST nodes (Program, Theorem, Proof, Assume, Therefore, Expr minimal)
- Simple `.out` summary (theorem name + step count)
- Optional `--latex` basic template emission

Then re-enable:
- Logger (replace debug stderr)
- `--dump-tokens` (dev aid)

## 5. Out-of-Scope (Current Phase)
- General numeric computation / imperative code (`int a=5`) — not planned
- Full symbolic algebra
- Complete Unicode normalization (after MVP)
- Advanced proof rule engine (later phase)

## 6. Suggested Issue Priorities
Order:
1. Parser MVP
2. Minimal AST + `.out` generator
3. Logging re-enable + `--log-level`
4. Token dump flag
5. LaTeX basic emission
6. Semantic no-op scaffolding tests

## 7. Contributor Prerequisite
Must understand (at least theoretically): tokens → grammar → AST → semantic pass. Practical experience preferred.

## 8. Expected “Success” (Current Build)
- Build succeeds
- Lexer tests pass
- Running any `.mf` file reaches parser stub error cleanly

## 9. Quick Commands (Fresh Setup)
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/bin/mathforge examples/pythagorean.mf
```

## 10. Testing Workflow & Single Test Folder Policy
Source tests live only in `tests/`. Generated CTest logs (`build/Testing/`) are ignored and can be removed safely; use the helper script:
```
./tools/run_tests.sh -R Lexer
```
This script:
- Configures the build (if needed)
- Rebuilds targets
- Cleans transient `Testing/` logs so contributors focus on `tests/` only

Run a subset:
```
ctest --test-dir build -R Core
```
Re-run only failed tests:
```
ctest --test-dir build --rerun-failed --output-on-failure
```

## 11. Sample Session (Current Expected Output)
```
$ ./build/bin/mathforge examples/pythagorean.mf
DEBUG: Starting application run
... (debug lines) ...
DEBUG: Tokenization complete, token count: N
ERROR: Syntax error: Parser not yet implemented
```
Exit code is non‑zero (intentional until parser exists).

## 12. Demonstrating Progress to Contributors
1. Show build & libraries: `ls build/src/*/libmathforge_*.a`
2. Show lexer test pass: `ctest --test-dir build -R Lexer`
3. Show controlled parser stub stop on any `.mf` file.

## 13. Roadmap Snapshot (Next Milestones)
1. Parser MVP (ASCII subset: theorem/proof blocks, simple statements)
2. Minimal AST & `.out` summary generator
3. Re-enable structured logging (`--log-level`, file logging)
4. `--dump-tokens` developer flag (JSON output)
5. Basic LaTeX emission (skeleton doc from AST)
6. Initial semantic scaffolding (symbol table insert/lookup)

## 14. Summary
MathForge is at the lexing stage. All downstream stages are architectural placeholders. Parser implementation is the critical next unblocker for any end‑to‑end artifact.