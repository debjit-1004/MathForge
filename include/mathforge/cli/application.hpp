/**
 * @file application.hpp
 * @brief Main CLI application class
 */

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace mathforge::cli {

/**
 * @brief Command line options structure
 */
struct Options {
    std::string inputFile;
    std::string outputFile;
    bool verbose = false;
    bool verify = true;
    bool generateLatex = false;
    bool showHelp = false;
    bool showVersion = false;
    std::string logLevel = "info";
    std::string logFile;
};

/**
 * @brief Main CLI application class
 */
class Application {
public:
    Application();
    ~Application() = default;
    
    /**
     * @brief Run the application with command line arguments
     * @param argc Number of arguments
     * @param argv Array of arguments
     * @return Exit code
     */
    int run(int argc, char* argv[]);

private:
    Options options_;
    
    /**
     * @brief Parse command line arguments
     * @param argc Number of arguments
     * @param argv Array of arguments
     * @return True if parsing succeeded
     */
    bool parseArguments(int argc, char* argv[]);
    
    /**
     * @brief Show help message
     */
    void showHelp(const std::string& programName) const;
    
    /**
     * @brief Show version information
     */
    void showVersion() const;
    
    /**
     * @brief Process the input file
     * @return Exit code
     */
    int processFile();
    
    /**
     * @brief Setup logging based on options
     */
    void setupLogging();
    
    /**
     * @brief Validate the parsed options
     * @return True if options are valid
     */
    bool validateOptions();
};

} // namespace mathforge::cli
