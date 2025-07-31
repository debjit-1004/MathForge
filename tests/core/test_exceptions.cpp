/**
 * @file test_exceptions.cpp
 * @brief Tests for exception hierarchy
 */

#include <gtest/gtest.h>
#include "mathforge/core/exceptions.hpp"

using namespace mathforge::core;

TEST(ExceptionsTest, BaseException) {
    try {
        throw MathForgeException("Test message");
    } catch (const MathForgeException& e) {
        EXPECT_STREQ(e.what(), "Test message");
        EXPECT_FALSE(e.getMessage().empty());
    }
}

TEST(ExceptionsTest, LexicalException) {
    try {
        throw LexicalException("Token error", 5, 10);
    } catch (const LexicalException& e) {
        EXPECT_EQ(e.getLine(), 5u);
        EXPECT_EQ(e.getColumn(), 10u);
        EXPECT_NE(std::string(e.what()).find("Lexical error"), std::string::npos);
    }
}

TEST(ExceptionsTest, SyntaxException) {
    try {
        throw SyntaxException("Parse error", 3, 7);
    } catch (const SyntaxException& e) {
        EXPECT_EQ(e.getLine(), 3u);
        EXPECT_EQ(e.getColumn(), 7u);
        EXPECT_NE(std::string(e.what()).find("Syntax error"), std::string::npos);
    }
}
