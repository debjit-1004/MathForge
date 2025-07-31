/**
 * @file version.cpp
 * @brief Implementation of version information
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
    oss << "MathForge " << getVersionString() << "\n";
    oss << "Built with: " << __VERSION__ << "\n";
    oss << "Build date: " << __DATE__ << " " << __TIME__ << "\n";
    oss << "C++ Standard: " << __cplusplus;
    return oss.str();
}

std::string Version::getCopyright() {
    return "Copyright (c) 2025 MathForge Team. All rights reserved.";
}

} // namespace mathforge::core
