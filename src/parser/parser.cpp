/**
 * @file parser.cpp
 * @brief Parser implementation
 */

#include "mathforge/parser/parser.hpp"
#include "mathforge/core/exceptions.hpp"

#include <sstream>
#include <utility>
#include <string>
#include <initializer_list>
#include <memory>

namespace mathforge::ast
{
    // Minimal parser-local AST node implementations that inherit from the project's
    // public Node base so other modules can consume them if needed.

    class Visitor; // forward (node.hpp used a Visitor in Node)

    struct Expr : public Node
    {
        ~Expr() override = default;
    };

    struct LiteralExpr : public Expr
    {
        std::string value;
        explicit LiteralExpr(std::string v) : value(std::move(v)) {}
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

    struct IdentifierExpr : public Expr
    {
        std::string name;
        explicit IdentifierExpr(std::string n) : name(std::move(n)) {}
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

    struct UnaryExpr : public Expr
    {
        lexer::Token op;
        std::unique_ptr<Expr> right;
        UnaryExpr(lexer::Token o, std::unique_ptr<Expr> r) : op(std::move(o)), right(std::move(r)) {}
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

    struct BinaryExpr : public Expr
    {
        std::unique_ptr<Expr> left;
        lexer::Token op;
        std::unique_ptr<Expr> right;
        BinaryExpr(std::unique_ptr<Expr> l, lexer::Token o, std::unique_ptr<Expr> r)
            : left(std::move(l)), op(std::move(o)), right(std::move(r)) {}
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

    struct Root : public Node
    {
        std::vector<std::unique_ptr<Node>> statements;
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

    // Minimal top-level statement node (placeholder)
    struct Statement : public Node
    {
        lexer::TokenType kind;
        std::string name;
        std::unique_ptr<Node> body;
        Statement(lexer::TokenType k, std::string n, std::unique_ptr<Node> b)
            : kind(k), name(std::move(n)), body(std::move(b)) {}
        void accept(Visitor & /*visitor*/) override { /* no-op for now */ }
    };

} // namespace mathforge::ast

// (parser implementation continues here...)
