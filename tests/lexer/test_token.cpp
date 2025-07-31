/**
 * @file test_token.cpp
 * @brief Tests for token functionality
 */

#include <gtest/gtest.h>
#include "mathforge/lexer/token.hpp"

using namespace mathforge::lexer;

TEST(TokenTest, TokenTypeToString) {
    EXPECT_EQ(TokenUtils::tokenTypeToString(TokenType::IDENTIFIER), "IDENTIFIER");
    EXPECT_EQ(TokenUtils::tokenTypeToString(TokenType::NUMBER), "NUMBER");
    EXPECT_EQ(TokenUtils::tokenTypeToString(TokenType::THEOREM), "THEOREM");
    EXPECT_EQ(TokenUtils::tokenTypeToString(TokenType::FORALL), "FORALL");
}

TEST(TokenTest, OperatorClassification) {
    EXPECT_TRUE(TokenUtils::isMathOperator(TokenType::PLUS));
    EXPECT_TRUE(TokenUtils::isMathOperator(TokenType::EQUALS));
    EXPECT_FALSE(TokenUtils::isMathOperator(TokenType::THEOREM));
    
    EXPECT_TRUE(TokenUtils::isLogicalOperator(TokenType::AND));
    EXPECT_TRUE(TokenUtils::isLogicalOperator(TokenType::IMPLIES));
    EXPECT_FALSE(TokenUtils::isLogicalOperator(TokenType::PLUS));
    
    EXPECT_TRUE(TokenUtils::isSetOperator(TokenType::ELEMENT_OF));
    EXPECT_TRUE(TokenUtils::isSetOperator(TokenType::UNION));
    EXPECT_FALSE(TokenUtils::isSetOperator(TokenType::AND));
    
    EXPECT_TRUE(TokenUtils::isQuantifier(TokenType::FORALL));
    EXPECT_TRUE(TokenUtils::isQuantifier(TokenType::EXISTS));
    EXPECT_FALSE(TokenUtils::isQuantifier(TokenType::AND));
}

TEST(TokenTest, KeywordRecognition) {
    EXPECT_EQ(TokenUtils::getKeywordType("theorem"), TokenType::THEOREM);
    EXPECT_EQ(TokenUtils::getKeywordType("proof"), TokenType::PROOF);
    EXPECT_EQ(TokenUtils::getKeywordType("QED"), TokenType::QED);
    EXPECT_EQ(TokenUtils::getKeywordType("unknown"), TokenType::IDENTIFIER);
}

TEST(TokenTest, OperatorPrecedence) {
    EXPECT_GT(TokenUtils::getOperatorPrecedence(TokenType::MULTIPLY), 
              TokenUtils::getOperatorPrecedence(TokenType::PLUS));
    EXPECT_GT(TokenUtils::getOperatorPrecedence(TokenType::POWER), 
              TokenUtils::getOperatorPrecedence(TokenType::MULTIPLY));
    EXPECT_EQ(TokenUtils::getOperatorPrecedence(TokenType::THEOREM), 0);
}

TEST(TokenTest, TokenConstruction) {
    Token token(TokenType::IDENTIFIER, "test", 1, 5, 10);
    EXPECT_EQ(token.type, TokenType::IDENTIFIER);
    EXPECT_EQ(token.value, "test");
    EXPECT_EQ(token.line, 1u);
    EXPECT_EQ(token.column, 5u);
    EXPECT_EQ(token.position, 10u);
}
