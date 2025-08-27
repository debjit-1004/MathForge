/**
 * @file test_lexer.cpp
 * @brief Tests for lexer functionality
 */

#include <gtest/gtest.h>
#include "mathforge/lexer/lexer.hpp"

using namespace mathforge::lexer;

class LexerTest : public ::testing::Test {
protected:
    std::vector<Token> tokenize(const std::string& input) {
        Lexer lexer(input);
        return lexer.tokenize();
    }
};

TEST_F(LexerTest, BasicTokenization) {
    auto tokens = tokenize("theorem proof QED");
    
    ASSERT_EQ(tokens.size(), 4u); // 3 tokens + EOF
    EXPECT_EQ(tokens[0].type, TokenType::THEOREM);
    EXPECT_EQ(tokens[1].type, TokenType::PROOF);
    EXPECT_EQ(tokens[2].type, TokenType::QED);
    EXPECT_EQ(tokens[3].type, TokenType::END_OF_FILE);
}

TEST_F(LexerTest, NumberTokenization) {
    auto tokens = tokenize("123 45.67");
    
    ASSERT_EQ(tokens.size(), 3u); // 2 numbers + EOF
    EXPECT_EQ(tokens[0].type, TokenType::NUMBER);
    EXPECT_EQ(tokens[0].value, "123");
    EXPECT_EQ(tokens[1].type, TokenType::NUMBER);
    EXPECT_EQ(tokens[1].value, "45.67");
}

TEST_F(LexerTest, IdentifierTokenization) {
    auto tokens = tokenize("variable_name another_var");
    
    ASSERT_EQ(tokens.size(), 3u); // 2 identifiers + EOF
    EXPECT_EQ(tokens[0].type, TokenType::IDENTIFIER);
    EXPECT_EQ(tokens[0].value, "variable_name");
    EXPECT_EQ(tokens[1].type, TokenType::IDENTIFIER);
    EXPECT_EQ(tokens[1].value, "another_var");
}

TEST_F(LexerTest, StringTokenization) {
    auto tokens = tokenize("\"hello world\"");
    
    ASSERT_EQ(tokens.size(), 2u); // 1 string + EOF
    EXPECT_EQ(tokens[0].type, TokenType::STRING);
    EXPECT_EQ(tokens[0].value, "hello world");
}

TEST_F(LexerTest, OperatorTokenization) {
    auto tokens = tokenize("+ - * / = < > <= >=");
    
    ASSERT_GE(tokens.size(), 9u);
    EXPECT_EQ(tokens[0].type, TokenType::PLUS);
    EXPECT_EQ(tokens[1].type, TokenType::MINUS);
    EXPECT_EQ(tokens[2].type, TokenType::MULTIPLY);
    EXPECT_EQ(tokens[3].type, TokenType::DIVIDE);
    EXPECT_EQ(tokens[4].type, TokenType::EQUALS);
    EXPECT_EQ(tokens[5].type, TokenType::LESS_THAN);
    EXPECT_EQ(tokens[6].type, TokenType::GREATER_THAN);
    EXPECT_EQ(tokens[7].type, TokenType::LESS_EQUAL);
    EXPECT_EQ(tokens[8].type, TokenType::GREATER_EQUAL);
}

TEST_F(LexerTest, DelimiterTokenization) {
    auto tokens = tokenize("( ) [ ] { } , ; : .");
    
    ASSERT_GE(tokens.size(), 10u);
    EXPECT_EQ(tokens[0].type, TokenType::LEFT_PAREN);
    EXPECT_EQ(tokens[1].type, TokenType::RIGHT_PAREN);
    EXPECT_EQ(tokens[2].type, TokenType::LEFT_BRACKET);
    EXPECT_EQ(tokens[3].type, TokenType::RIGHT_BRACKET);
    EXPECT_EQ(tokens[4].type, TokenType::LEFT_BRACE);
    EXPECT_EQ(tokens[5].type, TokenType::RIGHT_BRACE);
    EXPECT_EQ(tokens[6].type, TokenType::COMMA);
    EXPECT_EQ(tokens[7].type, TokenType::SEMICOLON);
    EXPECT_EQ(tokens[8].type, TokenType::COLON);
    EXPECT_EQ(tokens[9].type, TokenType::DOT);
}

TEST_F(LexerTest, CommentSkipping) {
    auto tokens = tokenize("theorem // this is a comment\nproof");
    
    // Should skip the comment
    ASSERT_GE(tokens.size(), 3u);
    EXPECT_EQ(tokens[0].type, TokenType::THEOREM);
    // Next should be NEWLINE
    EXPECT_EQ(tokens[1].type, TokenType::NEWLINE);
    EXPECT_EQ(tokens[2].type, TokenType::PROOF);
}

TEST_F(LexerTest, ErrorHandling) {
    auto tokens = tokenize("\"unterminated string");
    
    // Should create an error token
    ASSERT_GE(tokens.size(), 1u);
    EXPECT_EQ(tokens[0].type, TokenType::INVALID);
}

TEST_F(LexerTest, PositionTracking) {
    auto tokens = tokenize("theorem\nproof");
    
    EXPECT_EQ(tokens[0].line, 1u);
    EXPECT_EQ(tokens[0].column, 1u);
    
    // Find the proof token (should be after newline)
    bool foundProof = false;
    for (const auto& token : tokens) {
        if (token.type == TokenType::PROOF) {
            EXPECT_EQ(token.line, 2u);
            foundProof = true;
            break;
        }
    }
    EXPECT_TRUE(foundProof);
}
