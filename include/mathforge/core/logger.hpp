/**
 * @file logger.hpp
 * @brief Logging system for MathForge
 */

#pragma once

#include <string>
#include <memory>
#include <sstream>
#include <iostream>
#include <fstream>
#include <mutex>
#include <chrono>

namespace mathforge::core {

/**
 * @brief Log levels for the logging system
 */
enum class LogLevel {
    TRACE = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
};

/**
 * @brief Thread-safe logging system
 */
class Logger {
public:
    /**
     * @brief Initialize the logging system
     * @param level Minimum log level to output
     * @param filename Optional log file (empty for console only)
     */
    static void initialize(LogLevel level = LogLevel::INFO, const std::string& filename = "");
    
    /**
     * @brief Log a message
     * @param level Log level
     * @param message Message to log
     * @param file Source file (automatically filled by macro)
     * @param line Source line (automatically filled by macro)
     */
    static void log(LogLevel level, const std::string& message, 
                   const char* file = "", int line = 0);
    
    /**
     * @brief Set the minimum log level
     * @param level New minimum log level
     */
    static void setLevel(LogLevel level);
    
    /**
     * @brief Get the current log level
     * @return Current minimum log level
     */
    static LogLevel getLevel();
    
    /**
     * @brief Check if a log level is enabled
     * @param level Log level to check
     * @return True if the level is enabled
     */
    static bool isLevelEnabled(LogLevel level);

private:
    static std::unique_ptr<Logger> instance_;
    static std::mutex mutex_;
    
    LogLevel level_;
    std::unique_ptr<std::ofstream> file_;
    
    Logger(LogLevel level, const std::string& filename);
    
    void writeLog(LogLevel level, const std::string& message, 
                 const char* file, int line);
    
    std::string formatMessage(LogLevel level, const std::string& message, 
                            const char* file, int line);
    
    std::string levelToString(LogLevel level);
    std::string getCurrentTime();
};

} // namespace mathforge::core

// Convenience macros for logging
#define LOG_TRACE(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::TRACE, msg, __FILE__, __LINE__)
#define LOG_DEBUG(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::DEBUG, msg, __FILE__, __LINE__)
#define LOG_INFO(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::INFO, msg, __FILE__, __LINE__)
#define LOG_WARN(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::WARN, msg, __FILE__, __LINE__)
#define LOG_ERROR(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::ERROR, msg, __FILE__, __LINE__)
#define LOG_FATAL(msg) mathforge::core::Logger::log(mathforge::core::LogLevel::FATAL, msg, __FILE__, __LINE__)
