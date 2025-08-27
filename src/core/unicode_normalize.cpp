#include "mathforge/core/unicode_normalize.hpp"

#include <vector>
#include <utility>
#include <string>

namespace mathforge::core
{

    std::string normalizeUnicodeMath(const std::string &src)
    {
        std::string out = src;

        // Use explicit UTF-8 byte sequences to avoid source-encoding issues with the compiler.
        const std::vector<std::pair<std::string, std::string>> repl = {
            // ∀ U+2200
            {std::string("\xE2\x88\x80", 3), "forall"},
            // → U+2192
            {std::string("\xE2\x86\x92", 3), "->"},
            // ℝ⁺ (U+211D U+207A) and fallback ℝ
            {std::string("\xE2\x84\x9D\xE2\x81\xBA", 6), "R+"},
            {std::string("\xE2\x84\x9D", 3), "R"},
            // ½ U+00BD
            {std::string("\xC2\xBD", 2), "1/2"},
            // superscripts ², ³
            {std::string("\xC2\xB2", 2), "^2"},
            {std::string("\xC2\xB3", 2), "^3"},
            // unicode minus U+2212
            {std::string("\xE2\x88\x92", 3), "-"},
            // middle dot · U+00B7
            {std::string("\xC2\xB7", 2), "*"},
            // logical and/or ∧ U+2227, ∨ U+2228
            {std::string("\xE2\x88\xA7", 3), "and"},
            {std::string("\xE2\x88\xA8", 3), "or"}};

        for (const auto &p : repl)
        {
            size_t pos = 0;
            while ((pos = out.find(p.first, pos)) != std::string::npos)
            {
                out.replace(pos, p.first.size(), p.second);
                pos += p.second.size();
            }
        }

        return out;
    }

} // namespace mathforge::core