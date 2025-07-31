/**
 * @file lexer.cpp
 * @brief Lexer implementation (basic stub)
 */

#include "mathforge/lexer/lexer.hpp"
#include "mathforge/core/exceptions.hpp"

namespace mathforge::lexer {

Lexer::Lexer(std::string input) : input_(std::move(input)), position_(0), line_(1), column_(1) {
    indentStack_.push(0); // Initial indentation level
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (!isAtEnd()) {
        // Handle indentation at start of line
        if (column_ == 1) {
            handleIndentation(tokens);
        }
        
        // Skip whitespace
        skipWhitespace();
        
        if (isAtEnd()) break;
        
        char c = peek();
        
        // Skip comments
        if (c == '/' && peekNext() == '/') {
            skipLineComment();
            continue;
        }
        
        if (c == '/' && peekNext() == '*') {
            skipBlockComment();
            continue;
        }
        
        // Numbers
        if (isDigit(c)) {
            tokens.push_back(scanNumber());
            continue;
        }
        
        // Identifiers and keywords
        if (isAlpha(c)) {
            tokens.push_back(scanIdentifier());
            continue;
        }
        
        // String literals
        if (c == '"') {
            tokens.push_back(scanString());
            continue;
        }
        
        // Single character tokens
        switch (c) {
            case '(': tokens.push_back(makeToken(TokenType::LEFT_PAREN)); advance(); break;
            case ')': tokens.push_back(makeToken(TokenType::RIGHT_PAREN)); advance(); break;
            case '[': tokens.push_back(makeToken(TokenType::LEFT_BRACKET)); advance(); break;
            case ']': tokens.push_back(makeToken(TokenType::RIGHT_BRACKET)); advance(); break;
            case '{': tokens.push_back(makeToken(TokenType::LEFT_BRACE)); advance(); break;
            case '}': tokens.push_back(makeToken(TokenType::RIGHT_BRACE)); advance(); break;
            case ',': tokens.push_back(makeToken(TokenType::COMMA)); advance(); break;
            case ';': tokens.push_back(makeToken(TokenType::SEMICOLON)); advance(); break;
            case ':': tokens.push_back(makeToken(TokenType::COLON)); advance(); break;
            case '.': tokens.push_back(makeToken(TokenType::DOT)); advance(); break;
            case '+': tokens.push_back(makeToken(TokenType::PLUS)); advance(); break;
            case '-': tokens.push_back(makeToken(TokenType::MINUS)); advance(); break;
            case '*': tokens.push_back(makeToken(TokenType::MULTIPLY)); advance(); break;
            case '/': tokens.push_back(makeToken(TokenType::DIVIDE)); advance(); break;
            case '^': tokens.push_back(makeToken(TokenType::POWER)); advance(); break;
            case '=': tokens.push_back(makeToken(TokenType::EQUALS)); advance(); break;
            case '<':
                advance();
                if (peek() == '=') {
                    tokens.push_back(makeToken(TokenType::LESS_EQUAL));
                    advance();
                } else {
                    tokens.push_back(makeToken(TokenType::LESS_THAN));
                }
                break;
            case '>':
                advance();
                if (peek() == '=') {
                    tokens.push_back(makeToken(TokenType::GREATER_EQUAL));
                    advance();
                } else {
                    tokens.push_back(makeToken(TokenType::GREATER_THAN));
                }
                break;
            case '\n':
                tokens.push_back(makeToken(TokenType::NEWLINE));
                advance();
                line_++;
                column_ = 1;
                break;
            default:
                // Try Unicode mathematical symbols
                if (static_cast<unsigned char>(c) > 127) {
                    tokens.push_back(scanUnicodeSymbol());
                } else {
                    tokens.push_back(makeErrorToken("Unexpected character"));
                    advance();
                }
                break;
        }
    }
    
    // Add dedent tokens for remaining indentation levels
    while (indentStack_.size() > 1) {
        indentStack_.pop();
        tokens.push_back(makeToken(TokenType::DEDENT));
    }
    
    tokens.push_back(makeToken(TokenType::END_OF_FILE));
    return tokens;
}

bool Lexer::isAtEnd() const {
    return position_ >= input_.length();
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return input_[position_];
}

char Lexer::peekNext() const {
    if (position_ + 1 >= input_.length()) return '\0';
    return input_[position_ + 1];
}

char Lexer::advance() {
    if (isAtEnd()) return '\0';
    char c = input_[position_++];
    column_++;
    return c;
}

bool Lexer::match(char expected) {
    if (isAtEnd() || input_[position_] != expected) return false;
    position_++;
    column_++;
    return true;
}

void Lexer::skipWhitespace() {
    while (!isAtEnd() && isWhitespace(peek())) {
        advance();
    }
}

void Lexer::skipLineComment() {
    while (!isAtEnd() && peek() != '\n') {
        advance();
    }
}

void Lexer::skipBlockComment() {
    advance(); // Skip '/'
    advance(); // Skip '*'
    
    while (!isAtEnd()) {
        if (peek() == '*' && peekNext() == '/') {
            advance(); // Skip '*'
            advance(); // Skip '/'
            break;
        }
        if (peek() == '\n') {
            line_++;
            column_ = 0; // Will be incremented by advance()
        }
        advance();
    }
}

Token Lexer::scanNumber() {
    size_t start = position_;
    
    while (!isAtEnd() && isDigit(peek())) {
        advance();
    }
    
    // Check for decimal point
    if (!isAtEnd() && peek() == '.' && isDigit(peekNext())) {
        advance(); // Skip '.'
        while (!isAtEnd() && isDigit(peek())) {
            advance();
        }
    }
    
    std::string value = input_.substr(start, position_ - start);
    return makeToken(TokenType::NUMBER, value);
}

Token Lexer::scanIdentifier() {
    size_t start = position_;
    
    while (!isAtEnd() && isAlphaNumeric(peek())) {
        advance();
    }
    
    std::string value = input_.substr(start, position_ - start);
    TokenType type = TokenUtils::getKeywordType(value);
    return makeToken(type, value);
}

Token Lexer::scanString() {
    advance(); // Skip opening quote
    size_t start = position_;
    
    while (!isAtEnd() && peek() != '"') {
        if (peek() == '\n') {
            line_++;
            column_ = 0; // Will be incremented by advance()
        }
        advance();
    }
    
    if (isAtEnd()) {
        return makeErrorToken("Unterminated string");
    }
    
    std::string value = input_.substr(start, position_ - start);
    advance(); // Skip closing quote
    return makeToken(TokenType::STRING, value);
}

Token Lexer::scanUnicodeSymbol() {
    // Basic Unicode symbol recognition
    // This is a simplified implementation - full Unicode support would be more complex
    char c = advance();
    
    // Map common mathematical Unicode symbols
    switch (static_cast<unsigned char>(c)) {
        case 0xE2: // Multi-byte UTF-8 starting with 0xE2
            // This would need proper UTF-8 decoding
            // For now, just return as invalid
            return makeErrorToken("Unicode symbols not fully implemented");
        default:
            return makeErrorToken("Unknown Unicode character");
    }
}

void Lexer::handleIndentation(std::vector<Token>& tokens) {
    size_t indentLevel = 0;
    while (!isAtEnd() && peek() == ' ') {
        indentLevel++;
        advance();
    }
    
    // Skip empty lines
    if (!isAtEnd() && peek() == '\n') {
        return;
    }
    
    size_t currentIndent = indentStack_.top();
    
    if (indentLevel > currentIndent) {
        indentStack_.push(indentLevel);
        tokens.push_back(makeToken(TokenType::INDENT));
    } else if (indentLevel < currentIndent) {
        while (!indentStack_.empty() && indentStack_.top() > indentLevel) {
            indentStack_.pop();
            tokens.push_back(makeToken(TokenType::DEDENT));
        }
        
        if (indentStack_.empty() || indentStack_.top() != indentLevel) {
            tokens.push_back(makeErrorToken("Inconsistent indentation"));
        }
    }
}

Token Lexer::makeToken(TokenType type, std::string value) {
    return Token(type, std::move(value), line_, column_, position_);
}

Token Lexer::makeErrorToken(const std::string& message) {
    return Token(TokenType::INVALID, message, line_, column_, position_);
}

bool Lexer::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Lexer::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

bool Lexer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Lexer::isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}

} // namespace mathforge::lexer
