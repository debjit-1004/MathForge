/**
 * @file main.cpp
 * @brief Main entry point for the MathForge compiler
 * @author MathForge Team
 * @date 2025
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <filesystem>

#include "mathforge/cli/application.hpp"
#include "mathforge/core/logger.hpp"
#include "mathforge/core/version.hpp"

namespace fs = std::filesystem;

/**
 * @brief Main function for MathForge compiler
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return Exit code (0 for success, non-zero for error)
 */
int main(int argc, char* argv[]) {
    try {
        // Initialize logging system
        mathforge::core::Logger::initialize();
        
        // Create CLI application
        auto app = std::make_unique<mathforge::cli::Application>();
        
        // Parse command line arguments and run
        return app->run(argc, argv);
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown fatal error occurred" << std::endl;
        return 2;
    }
}
