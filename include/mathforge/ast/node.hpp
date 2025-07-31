/**
 * @file node.hpp
 * @brief AST node base class (stub)
 */

#pragma once

#include <memory>
#include <vector>

namespace mathforge::ast {

class Node {
public:
    virtual ~Node() = default;
    virtual void accept(class Visitor& visitor) = 0;
};

} // namespace mathforge::ast
