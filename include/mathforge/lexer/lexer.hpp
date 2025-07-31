/**
 * @file lexer.hpp
 * @brief Lexical analyzer for MathForge language
 */

#pragma once

#include "mathforge/lexer/token.hpp"
#include <string>
#include <vector>
#include <memory>
#include <stack>

namespace mathforge::lexer {

/**
 * @brief Lexical analyzer for MathForge mathematical proof language
 */
class Lexer {
public:
    /**
     * @brief Construct a lexer with input text
     * @param input The input text to tokenize
     */
    explicit Lexer(std::string input);
    
    /**
     * @brief Tokenize the input text
     * @return Vector of tokens
     */
    std::vector<Token> tokenize();
    
    /**
     * @brief Get current line number
     * @return Current line number (1-based)
     */
    size_t getCurrentLine() const { return line_; }
    
    /**
     * @brief Get current column number
     * @return Current column number (1-based)
     */
    size_t getCurrentColumn() const { return column_; }
    
    /**
     * @brief Get current position in input
     * @return Current position (0-based)
     */
    size_t getCurrentPosition() const { return position_; }

private:
    std::string input_;
    size_t position_;
    size_t line_;
    size_t column_;
    std::stack<size_t> indentStack_;
    
    /**
     * @brief Check if we're at the end of input
     * @return True if at end of input
     */
    bool isAtEnd() const;
    
    /**
     * @brief Get current character without advancing
     * @return Current character
     */
    char peek() const;
    
    /**
     * @brief Get next character without advancing
     * @return Next character
     */
    char peekNext() const;
    
    /**
     * @brief Advance to next character
     * @return Previous character
     */
    char advance();
    
    /**
     * @brief Check if current character matches expected
     * @param expected Expected character
     * @return True if matches and advances, false otherwise
     */
    bool match(char expected);
    
    /**
     * @brief Skip whitespace characters
     */
    void skipWhitespace();
    
    /**
     * @brief Skip single-line comment
     */
    void skipLineComment();
    
    /**
     * @brief Skip multi-line comment
     */
    void skipBlockComment();
    
    /**
     * @brief Scan a number token
     * @return Number token
     */
    Token scanNumber();
    
    /**
     * @brief Scan an identifier or keyword token
     * @return Identifier or keyword token
     */
    Token scanIdentifier();
    
    /**
     * @brief Scan a string literal token
     * @return String token
     */
    Token scanString();
    
    /**
     * @brief Scan a Unicode mathematical symbol
     * @return Appropriate token for the symbol
     */
    Token scanUnicodeSymbol();
    
    /**
     * @brief Handle indentation for Python-like syntax
     * @param tokens Vector to add indent/dedent tokens to
     */
    void handleIndentation(std::vector<Token>& tokens);
    
    /**
     * @brief Create a token with current position information
     * @param type Token type
     * @param value Token value
     * @return Token with position info
     */
    Token makeToken(TokenType type, std::string value = "");
    
    /**
     * @brief Create an error token
     * @param message Error message
     * @return Error token
     */
    Token makeErrorToken(const std::string& message);
    
    /**
     * @brief Check if character is alphabetic or underscore
     * @param c Character to check
     * @return True if alphabetic or underscore
     */
    static bool isAlpha(char c);
    
    /**
     * @brief Check if character is alphanumeric or underscore
     * @param c Character to check
     * @return True if alphanumeric or underscore
     */
    static bool isAlphaNumeric(char c);
    
    /**
     * @brief Check if character is a digit
     * @param c Character to check
     * @return True if digit
     */
    static bool isDigit(char c);
    
    /**
     * @brief Check if character is whitespace (excluding newline)
     * @param c Character to check
     * @return True if whitespace
     */
    static bool isWhitespace(char c);
};

} // namespace mathforge::lexer
