/**
 * @file latex_generator.hpp
 * @brief LaTeX code generator (stub)
 */

#pragma once

#include "mathforge/ast/node.hpp"
#include <string>

namespace mathforge::codegen {

class LatexGenerator {
public:
    std::string generate(ast::Node* node);
};

} // namespace mathforge::codegen
