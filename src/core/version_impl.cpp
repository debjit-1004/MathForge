/**
 * @file version.cpp
 * @brief Version implementation
 */

#include "mathforge/core/version.hpp"
#include <sstream>
#include <cstring>

namespace mathforge::core {

std::string Version::getVersionString() {
    std::ostringstream oss;
    oss << MAJOR << "." << MINOR << "." << PATCH;
    if (strlen(SUFFIX) > 0) {
        oss << "-" << SUFFIX;
    }
    return oss.str();
}

std::string Version::getBuildInfo() {
    std::ostringstream oss;
    oss << "MathForge " << getVersionString();
    oss << " (Built on " << __DATE__ << " " << __TIME__ << ")";
    return oss.str();
}

std::string Version::getCopyright() {
    return "Copyright (c) 2025 MathForge Team. All rights reserved.";
}

} // namespace mathforge::core
