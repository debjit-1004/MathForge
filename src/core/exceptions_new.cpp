/**
 * @file exceptions.cpp
 * @brief Implementation of exception hierarchy
 */

#include "mathforge/core/exceptions.hpp"

namespace mathforge::core {

MathForgeException::MathForgeException(const std::string& message)
    : message_(message) {
}

const char* MathForgeException::what() const noexcept {
    return message_.c_str();
}

const std::string& MathForgeException::getMessage() const noexcept {
    return message_;
}

LexicalException::LexicalException(const std::string& message, size_t line, size_t column)
    : MathForgeException("Lexical error: " + message), line_(line), column_(column) {
}

SyntaxException::SyntaxException(const std::string& message, size_t line, size_t column)
    : MathForgeException("Syntax error: " + message), line_(line), column_(column) {
}

SemanticException::SemanticException(const std::string& message)
    : MathForgeException("Semantic error: " + message) {
}

ProofException::ProofException(const std::string& message)
    : MathForgeException("Proof error: " + message) {
}

CodeGenException::CodeGenException(const std::string& message)
    : MathForgeException("Code generation error: " + message) {
}

IOException::IOException(const std::string& message)
    : MathForgeException("I/O error: " + message) {
}

} // namespace mathforge::core
