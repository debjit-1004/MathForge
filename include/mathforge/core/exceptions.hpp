/**
 * @file exceptions.hpp
 * @brief Exception hierarchy for MathForge
 */

#pragma once

#include <stdexcept>
#include <string>

namespace mathforge::core {

/**
 * @brief Base exception class for all MathForge exceptions
 */
class MathForgeException : public std::exception {
public:
    explicit MathForgeException(const std::string& message);
    
    const char* what() const noexcept override;
    
    /**
     * @brief Get formatted error message
     * @return Formatted error message
     */
    const std::string& getMessage() const noexcept;

private:
    std::string message_;
};

/**
 * @brief Exception for lexical analysis errors
 */
class LexicalException : public MathForgeException {
public:
    explicit LexicalException(const std::string& message, size_t line = 0, size_t column = 0);
    
    size_t getLine() const noexcept { return line_; }
    size_t getColumn() const noexcept { return column_; }

private:
    size_t line_;
    size_t column_;
};

/**
 * @brief Exception for syntax analysis errors
 */
class SyntaxException : public MathForgeException {
public:
    explicit SyntaxException(const std::string& message, size_t line = 0, size_t column = 0);
    
    size_t getLine() const noexcept { return line_; }
    size_t getColumn() const noexcept { return column_; }

private:
    size_t line_;
    size_t column_;
};

/**
 * @brief Exception for semantic analysis errors
 */
class SemanticException : public MathForgeException {
public:
    explicit SemanticException(const std::string& message);
};

/**
 * @brief Exception for proof verification errors
 */
class ProofException : public MathForgeException {
public:
    explicit ProofException(const std::string& message);
};

/**
 * @brief Exception for code generation errors
 */
class CodeGenException : public MathForgeException {
public:
    explicit CodeGenException(const std::string& message);
};

/**
 * @brief Exception for I/O related errors
 */
class IOException : public MathForgeException {
public:
    explicit IOException(const std::string& message);
};

} // namespace mathforge::core
