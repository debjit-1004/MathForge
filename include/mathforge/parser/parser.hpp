/**
 * @file parser.hpp
 * @brief Parser for MathForge language (stub)
 */

#pragma once

#include "mathforge/lexer/token.hpp"
#include "mathforge/ast/node.hpp"
#include <vector>
#include <memory>

namespace mathforge::parser {

class Parser {
public:
    explicit Parser(std::vector<lexer::Token> tokens);
    std::unique_ptr<ast::Node> parse();

private:
    std::vector<lexer::Token> tokens_;
    size_t current_;
};

} // namespace mathforge::parser
