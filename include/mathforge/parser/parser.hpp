/**
 * @file parser.hpp
 * @brief Parser for MathForge language (stub)
 */

#pragma once

#include "mathforge/lexer/token.hpp"
#include "mathforge/ast/node.hpp"
#include <vector>
#include <memory>
#include <string>
#include <initializer_list>

namespace mathforge::ast
{
    struct Expr; // forward-declare expression node used by parser
}

namespace mathforge::parser
{

    class Parser
    {
    public:
        explicit Parser(std::vector<lexer::Token> tokens);
        std::unique_ptr<ast::Node> parse();

    private:
        std::vector<lexer::Token> tokens_;
        size_t current_;

        // helper accessors
        bool isAtEnd() const;
        const lexer::Token &peek() const;
        const lexer::Token &previous() const;
        const lexer::Token &advance();
        bool check(lexer::TokenType type) const;
        bool match(const std::initializer_list<lexer::TokenType> &types);

        [[noreturn]] void errorAtToken(const lexer::Token &token, const std::string &message) const;
        const lexer::Token &consume(lexer::TokenType type, const std::string &message);
        const lexer::Token &errorConsume(const std::string &message);

        // parsing helpers (expression precedence)
        std::unique_ptr<ast::Node> parseExpression();
        // parse top-level statements like THEOREM, LEMMA, PROOF, etc.
        std::unique_ptr<ast::Node> parseStatement();
        std::unique_ptr<ast::Expr> parseEquality();
        std::unique_ptr<ast::Expr> parseComparison();
        std::unique_ptr<ast::Expr> parseTerm();
        std::unique_ptr<ast::Expr> parseFactor();
        std::unique_ptr<ast::Expr> parsePower();
        std::unique_ptr<ast::Expr> parseUnary();
        std::unique_ptr<ast::Expr> parsePrimary();
    };

} // namespace mathforge::parser
