/**
 * @file statement.hpp
 * @brief AST statement nodes (stub)
 */

#pragma once

#include "mathforge/ast/node.hpp"

namespace mathforge::ast {

class Statement : public Node {
public:
    virtual ~Statement() = default;
};

} // namespace mathforge::ast
