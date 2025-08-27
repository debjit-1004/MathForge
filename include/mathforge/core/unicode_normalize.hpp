// ...existing code...
#pragma once
#include <string>

namespace mathforge::core {
    // Replace common Unicode math symbols with ASCII equivalents used by the lexer
    std::string normalizeUnicodeMath(const std::string& src);
} // namespace mathforge::core
// ...existing code...