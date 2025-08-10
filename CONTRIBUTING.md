# Contributing to MathForge

Thanks for your interest in contributing! MathForge is a modern C++20 compiler for a mathematical proof language. We welcome contributions across documentation, tests, tooling, and core features.

## Ground rules (please read)
- GSSoC’25 project admin requirement: contributors must have at least a theoretical understanding of compiler design (lexing, parsing, ASTs, semantics). Practical experience is a plus, not mandatory.
- Be respectful, collaborative, and constructive. (A Code of Conduct will be added; please behave accordingly.)
- Keep PRs focused and small; prefer incremental changes with tests.
- Write clear commit messages and PR descriptions.

## How you can contribute
- Documentation: improve README/Guides, add examples.
- Developer tooling: CLI flags (e.g., dump tokens/AST), logs, diagnostics.
- Testing: unit tests for lexer, parser (as implemented), semantic, proof, codegen, and CLI.
- Features: parser MVP, semantic checks, proof rules, LaTeX generation.
- Issue triage: reproduce, minimize, label, propose fixes.

Check open issues and labels like `gssoc25`, `level1`, `level2`, `level3` for difficulty and scope.

## Project overview
- Language pipeline: Lexer → Parser → AST → Semantic Analysis → Proof Verification → Code Generation → CLI.
- Tech: C++20, CMake, GoogleTest, cross‑platform.

## Prerequisites
- Basic compiler theory (tokens, grammar, AST, passes) — required.
- C++20 toolchain (GCC/Clang/MSVC), CMake ≥ 3.20.
- Git and GitHub account.

## Getting started (local build)
1. Fork the repo and clone your fork.
2. Create a feature branch from `master`.
3. Configure and build (out‑of‑source):
   - `mkdir build && cd build`
   - `cmake .. -DCMAKE_BUILD_TYPE=Debug`
   - `cmake --build . -- -j`
4. Run tests: `ctest --output-on-failure`
5. Run the CLI: `./bin/mathforge --help`

> If you’re new, start with docs/tests or CLI flags before core parser work.

## Development workflow
- Pick/claim an issue (comment on it), discuss approach if non‑trivial.
- Keep changes small and scoped to one concern.
- Add/adjust tests for any behavior change.
- Update docs when adding flags or public APIs.
- Open a PR to `master`; link the issue; fill the checklist below.

## Code style & guidelines
- C++20, RAII, smart pointers; avoid raw `new/delete`.
- Header/implementation separation; minimal public headers under `include/mathforge/`.
- Prefer `std::unique_ptr` ownership in AST; pass raw pointers/references for non‑ownership.
- Use `const` and `noexcept` where appropriate.
- Logging via `Logger` (LOG_* macros) — keep messages actionable.
- Clear errors with location; throw domain exceptions (LexicalException, SyntaxException, etc.).

## Testing
- Add unit tests in `tests/` using GoogleTest.
- Include at least: happy path + 1–2 edge cases.
- Keep tests deterministic and fast; avoid filesystem/network unless needed.

## Commit messages
- Use concise, descriptive messages. Conventional commits are welcome (e.g., `feat:`, `fix:`, `test:`).
- Reference issues: `Fixes #123` or `Refs #123`.

## Pull request checklist
- [ ] Issue referenced and scope aligned
- [ ] Builds on CI (or locally) without warnings/errors
- [ ] Tests added/updated and passing
- [ ] Docs updated (README/guides/flags)
- [ ] No large unrelated refactors

## Areas and suggested first issues
- CLI: developer flags (e.g., `--dump-tokens`, `--dump-ast`).
- Logging: re‑enable and test `--log-level/--log-file` behavior.
- Lexer: Unicode→ASCII normalization (∀, →, ℝ, superscripts) behind a flag.
- Codegen: minimal `.out` summary when `--latex` is not set.
- Parser MVP: ASCII subset (theorem/proof with assume/therefore/qed).

## Design notes
- Parser is currently WIP; aim for a clear, testable grammar with precise error messages.
- AST should carry source spans for diagnostics.
- Semantic and proof passes should fail fast with actionable messages.
- LaTeX generator should escape/format identifiers and math safely.

## Reporting issues
- Include repro steps, expected vs actual behavior, platform/toolchain.
- Small input files (e.g., `.mf` snippets) help a lot.

## Licensing
- By contributing, you agree your contributions are licensed under this repository’s license (see `LICENSE`).

## Acknowledgements
- This project participates in GSSoC’25. Thanks for helping make MathForge better!
