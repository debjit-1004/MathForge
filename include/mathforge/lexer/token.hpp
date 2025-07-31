/**
 * @file token.hpp
 * @brief Token definitions for the MathForge lexer
 */

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace mathforge::lexer {

/**
 * @brief Token types for mathematical expressions and proof constructs
 */
enum class TokenType {
    // Literals
    IDENTIFIER,
    NUMBER,
    STRING,
    
    // Mathematical operators
    PLUS,           // +
    MINUS,          // -
    MULTIPLY,       // *
    DIVIDE,         // /
    POWER,          // ^
    EQUALS,         // =
    NOT_EQUALS,     // ≠
    LESS_THAN,      // <
    GREATER_THAN,   // >
    LESS_EQUAL,     // ≤
    GREATER_EQUAL,  // ≥
    
    // Logical operators
    AND,            // ∧
    OR,             // ∨
    NOT,            // ¬
    IMPLIES,        // →
    IFF,            // ↔
    
    // Set operations
    ELEMENT_OF,     // ∈
    NOT_ELEMENT_OF, // ∉
    SUBSET,         // ⊆
    PROPER_SUBSET,  // ⊂
    SUPERSET,       // ⊇
    UNION,          // ∪
    INTERSECTION,   // ∩
    SET_MINUS,      // \ (set difference)
    
    // Quantifiers
    FORALL,         // ∀
    EXISTS,         // ∃
    
    // Delimiters
    LEFT_PAREN,     // (
    RIGHT_PAREN,    // )
    LEFT_BRACKET,   // [
    RIGHT_BRACKET,  // ]
    LEFT_BRACE,     // {
    RIGHT_BRACE,    // }
    
    // Punctuation
    COMMA,          // ,
    SEMICOLON,      // ;
    COLON,          // :
    DOT,            // .
    
    // Keywords
    THEOREM,
    LEMMA,
    PROOF,
    QED,
    ASSUME,
    LET,
    BY,
    THEREFORE,
    HENCE,
    SINCE,
    GIVEN,
    IF,
    THEN,
    ELSE,
    CASE,
    INDUCTION,
    BASE,
    STEP,
    
    // Type keywords
    SET,
    FUNCTION,
    RELATION,
    REAL,
    INTEGER,
    NATURAL,
    RATIONAL,
    
    // Special
    NEWLINE,
    INDENT,
    DEDENT,
    END_OF_FILE,
    INVALID
};

/**
 * @brief Token structure containing type, value, and position information
 */
struct Token {
    TokenType type;
    std::string value;
    size_t line;
    size_t column;
    size_t position;
    
    Token(TokenType t, std::string v, size_t l, size_t c, size_t p)
        : type(t), value(std::move(v)), line(l), column(c), position(p) {}
};

/**
 * @brief Token utility functions
 */
class TokenUtils {
public:
    /**
     * @brief Convert token type to string representation
     * @param type Token type to convert
     * @return String representation of the token type
     */
    static std::string tokenTypeToString(TokenType type);
    
    /**
     * @brief Check if a token type is a mathematical operator
     * @param type Token type to check
     * @return True if the token is a mathematical operator
     */
    static bool isMathOperator(TokenType type);
    
    /**
     * @brief Check if a token type is a logical operator
     * @param type Token type to check
     * @return True if the token is a logical operator
     */
    static bool isLogicalOperator(TokenType type);
    
    /**
     * @brief Check if a token type is a set operator
     * @param type Token type to check
     * @return True if the token is a set operator
     */
    static bool isSetOperator(TokenType type);
    
    /**
     * @brief Check if a token type is a quantifier
     * @param type Token type to check
     * @return True if the token is a quantifier
     */
    static bool isQuantifier(TokenType type);
    
    /**
     * @brief Check if a token type is a keyword
     * @param type Token type to check
     * @return True if the token is a keyword
     */
    static bool isKeyword(TokenType type);
    
    /**
     * @brief Get keyword token type from string
     * @param word String to check
     * @return Token type if it's a keyword, IDENTIFIER otherwise
     */
    static TokenType getKeywordType(const std::string& word);
    
    /**
     * @brief Get operator precedence
     * @param type Token type
     * @return Precedence level (higher number = higher precedence)
     */
    static int getOperatorPrecedence(TokenType type);

private:
    static const std::unordered_map<std::string, TokenType> keywords_;
    static const std::unordered_map<TokenType, int> precedence_;
};

} // namespace mathforge::lexer
