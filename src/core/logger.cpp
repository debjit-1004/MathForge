/**
 * @file logger.cpp
 * @brief Implementation of the logging system
 */

#include "mathforge/core/logger.hpp"
#include <iomanip>
#include <filesystem>

namespace mathforge::core {

std::unique_ptr<Logger> Logger::instance_ = nullptr;
std::mutex Logger::mutex_;

void Logger::initialize(LogLevel level, const std::string& filename) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!instance_) {
        instance_ = std::unique_ptr<Logger>(new Logger(level, filename));
    }
}

void Logger::log(LogLevel level, const std::string& message, const char* file, int line) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ && instance_->isLevelEnabled(level)) {
        instance_->writeLog(level, message, file, line);
    }
}

void Logger::setLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_) {
        instance_->level_ = level;
    }
}

LogLevel Logger::getLevel() {
    std::lock_guard<std::mutex> lock(mutex_);
    return instance_ ? instance_->level_ : LogLevel::INFO;
}

bool Logger::isLevelEnabled(LogLevel level) {
    return static_cast<int>(level) >= static_cast<int>(getLevel());
}

Logger::Logger(LogLevel level, const std::string& filename) : level_(level) {
    if (!filename.empty()) {
        // Create directory if it doesn't exist
        std::filesystem::path filepath(filename);
        if (filepath.has_parent_path()) {
            std::filesystem::create_directories(filepath.parent_path());
        }
        
        file_ = std::make_unique<std::ofstream>(filename, std::ios::app);
        if (!file_->is_open()) {
            throw std::runtime_error("Failed to open log file: " + filename);
        }
    }
}

void Logger::writeLog(LogLevel level, const std::string& message, 
                     const char* file, int line) {
    std::string formatted = formatMessage(level, message, file, line);
    
    // Always output to console
    if (level >= LogLevel::ERROR) {
        std::cerr << formatted << std::endl;
    } else {
        std::cout << formatted << std::endl;
    }
    
    // Also output to file if available
    if (file_ && file_->is_open()) {
        *file_ << formatted << std::endl;
        file_->flush();
    }
}

std::string Logger::formatMessage(LogLevel level, const std::string& message, 
                                const char* file, int line) {
    std::ostringstream oss;
    
    // Timestamp
    oss << "[" << getCurrentTime() << "] ";
    
    // Log level
    oss << "[" << std::setw(5) << levelToString(level) << "] ";
    
    // Source location (if provided)
    if (file && strlen(file) > 0 && line > 0) {
        std::filesystem::path filepath(file);
        oss << filepath.filename().string() << ":" << line << " ";
    }
    
    // Message
    oss << message;
    
    return oss.str();
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::TRACE: return "TRACE";
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO:  return "INFO";
        case LogLevel::WARN:  return "WARN";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default: return "UNKNOWN";
    }
}

std::string Logger::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    oss << "." << std::setfill('0') << std::setw(3) << ms.count();
    
    return oss.str();
}

} // namespace mathforge::core
