/**
 * @file expression.hpp
 * @brief AST expression nodes (stub)
 */

#pragma once

#include "mathforge/ast/node.hpp"

namespace mathforge::ast {

class Expression : public Node {
public:
    virtual ~Expression() = default;
};

} // namespace mathforge::ast
