/**
 * @file version.hpp
 * @brief Version information for MathForge
 */

#pragma once

#include <string>

namespace mathforge::core {

/**
 * @brief Version information container
 */
class Version {
public:
    static constexpr int MAJOR = 1;
    static constexpr int MINOR = 0;
    static constexpr int PATCH = 0;
    static constexpr const char* SUFFIX = "";
    
    /**
     * @brief Get the full version string
     * @return Version string in format "MAJOR.MINOR.PATCH[-SUFFIX]"
     */
    static std::string getVersionString();
    
    /**
     * @brief Get the build information
     * @return Build information string
     */
    static std::string getBuildInfo();
    
    /**
     * @brief Get the copyright notice
     * @return Copyright notice
     */
    static std::string getCopyright();
};

} // namespace mathforge::core
