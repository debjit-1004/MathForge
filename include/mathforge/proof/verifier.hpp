/**
 * @file verifier.hpp
 * @brief Proof verifier (stub)
 */

#pragma once

#include "mathforge/ast/node.hpp"

namespace mathforge::proof {

class Verifier {
public:
    bool verify(ast::Node* node);
};

} // namespace mathforge::proof
