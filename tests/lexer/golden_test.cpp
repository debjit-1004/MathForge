#include <gtest/gtest.h>
#include "mathforge/lexer/lexer.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// ...existing code...

// Helper function to read a file's content into a string
std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// The core function for running a golden test
void runGoldenTest(const std::string& testName) {
    const std::string inputPath = "golden_files/" + testName + ".txt";
    const std::string goldenPath = "golden_files/" + testName + ".golden";

    std::string input = readFile(inputPath);
    std::string golden = readFile(goldenPath);

    mathforge::lexer::Lexer lexer(input);
    std::stringstream actualOutput;
    auto tokens = lexer.tokenize();
    for (const auto& token : tokens) {
        if (token.type == mathforge::lexer::TokenType::END_OF_FILE) break;
        actualOutput << "Type: " << static_cast<int>(token.type) << ", Value: '" << token.value << "'\n";
    }

    ASSERT_EQ(actualOutput.str(), golden);
}

// Test cases for each of the required scenarios
TEST(LexerGoldenTest, Identifiers) {
    runGoldenTest("identifiers");
}

TEST(LexerGoldenTest, Numbers) {
    runGoldenTest("numbers");
}

TEST(LexerGoldenTest, Operators) {
    runGoldenTest("operators");
}

TEST(LexerGoldenTest, Indentation) {
    runGoldenTest("indentation");
}

TEST(LexerGoldenTest, Comments) {
    runGoldenTest("comments");
}

TEST(LexerGoldenTest, Error) {
    runGoldenTest("error");
}