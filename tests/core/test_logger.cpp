/**
 * @file test_logger.cpp
 * @brief Tests for logging functionality
 */

#include <gtest/gtest.h>
#include "mathforge/core/logger.hpp"
#include <sstream>

using namespace mathforge::core;

class LoggerTest : public ::testing::Test {
protected:
    void SetUp() override {
        Logger::initialize(LogLevel::DEBUG);
    }
};

TEST_F(LoggerTest, LogLevels) {
    EXPECT_TRUE(Logger::isLevelEnabled(LogLevel::ERROR));
    EXPECT_TRUE(Logger::isLevelEnabled(LogLevel::DEBUG));
    
    Logger::setLevel(LogLevel::ERROR);
    EXPECT_TRUE(Logger::isLevelEnabled(LogLevel::ERROR));
    EXPECT_FALSE(Logger::isLevelEnabled(LogLevel::DEBUG));
}

TEST_F(LoggerTest, BasicLogging) {
    // Test that logging doesn't crash
    LOG_INFO("Test message");
    LOG_DEBUG("Debug message");
    LOG_ERROR("Error message");
    
    // If we get here, logging worked
    SUCCEED();
}
