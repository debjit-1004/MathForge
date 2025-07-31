/**
 * @file parser.cpp
 * @brief Parser implementation (stub)
 */

#include "mathforge/parser/parser.hpp"
#include "mathforge/core/exceptions.hpp"

namespace mathforge::parser {

Parser::Parser(std::vector<lexer::Token> tokens) : tokens_(std::move(tokens)), current_(0) {}

std::unique_ptr<ast::Node> Parser::parse() {
    // TODO: Implement actual parsing logic
    throw core::SyntaxException("Parser not yet implemented");
}

} // namespace mathforge::parser
