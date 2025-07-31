/**
 * @file application.cpp
 * @brief Implementation of CLI application
 */

#include "mathforge/cli/application.hpp"
#include "mathforge/core/version.hpp"
#include "mathforge/core/logger.hpp"
#include "mathforge/core/exceptions.hpp"
#include "mathforge/lexer/lexer.hpp"
#include "mathforge/parser/parser.hpp"
#include "mathforge/semantic/analyzer.hpp"
#include "mathforge/proof/verifier.hpp"
#include "mathforge/codegen/latex_generator.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

namespace mathforge::cli {

Application::Application() = default;

int Application::run(int argc, char* argv[]) {
    try {
        std::cerr << "DEBUG: Starting application run" << std::endl;
        
        // Parse command line arguments
        if (!parseArguments(argc, argv)) {
            return 1;
        }
        
        std::cerr << "DEBUG: Arguments parsed successfully" << std::endl;
        
        // Handle special options
        if (options_.showHelp) {
            showHelp(argv[0]);
            return 0;
        }
        
        if (options_.showVersion) {
            showVersion();
            return 0;
        }
        
        std::cerr << "DEBUG: Special options handled" << std::endl;
        
        // Validate options
        if (!validateOptions()) {
            return 1;
        }
        
        std::cerr << "DEBUG: Options validated" << std::endl;
        
        // Setup logging
        // setupLogging(); // Comment out to debug hanging issue
        std::cerr << "DEBUG: Skipped setupLogging()" << std::endl;
        
        // LOG_INFO("Starting MathForge compiler");
        // LOG_INFO("Input file: " + options_.inputFile);
        std::cerr << "DEBUG: Starting MathForge compiler" << std::endl;
        std::cerr << "DEBUG: Input file: " << options_.inputFile << std::endl;
        
        // Process the input file
        std::cerr << "DEBUG: About to call processFile()" << std::endl;
        return processFile();
        
    } catch (const core::MathForgeException& e) {
        std::cerr << "Error: " << e.getMessage() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 2;
    }
}

bool Application::parseArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            options_.showHelp = true;
        } else if (arg == "-v" || arg == "--version") {
            options_.showVersion = true;
        } else if (arg == "--verbose") {
            options_.verbose = true;
            options_.logLevel = "debug";
        } else if (arg == "--no-verify") {
            options_.verify = false;
        } else if (arg == "--latex") {
            options_.generateLatex = true;
        } else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                options_.outputFile = argv[++i];
            } else {
                std::cerr << "Error: " << arg << " requires an argument" << std::endl;
                return false;
            }
        } else if (arg == "--log-level") {
            if (i + 1 < argc) {
                options_.logLevel = argv[++i];
                std::transform(options_.logLevel.begin(), options_.logLevel.end(),
                             options_.logLevel.begin(), ::tolower);
            } else {
                std::cerr << "Error: " << arg << " requires an argument" << std::endl;
                return false;
            }
        } else if (arg == "--log-file") {
            if (i + 1 < argc) {
                options_.logFile = argv[++i];
            } else {
                std::cerr << "Error: " << arg << " requires an argument" << std::endl;
                return false;
            }
        } else if (!arg.empty() && arg[0] == '-') {
            std::cerr << "Error: Unknown option " << arg << std::endl;
            return false;
        } else {
            // Input file
            if (options_.inputFile.empty()) {
                options_.inputFile = arg;
            } else {
                std::cerr << "Error: Multiple input files specified" << std::endl;
                return false;
            }
        }
    }
    
    return true;
}

void Application::showHelp(const std::string& programName) const {
    std::cout << "MathForge - Mathematical Proof Language Compiler\n\n";
    std::cout << "USAGE:\n";
    std::cout << "    " << fs::path(programName).filename().string() << " [OPTIONS] <input-file>\n\n";
    std::cout << "OPTIONS:\n";
    std::cout << "    -h, --help           Show this help message\n";
    std::cout << "    -v, --version        Show version information\n";
    std::cout << "    -o, --output <file>  Specify output file\n";
    std::cout << "    --verbose            Enable verbose output\n";
    std::cout << "    --no-verify          Skip proof verification\n";
    std::cout << "    --latex              Generate LaTeX output\n";
    std::cout << "    --log-level <level>  Set log level (trace, debug, info, warn, error, fatal)\n";
    std::cout << "    --log-file <file>    Write logs to file\n\n";
    std::cout << "EXAMPLES:\n";
    std::cout << "    " << fs::path(programName).filename().string() << " theorem.mf\n";
    std::cout << "    " << fs::path(programName).filename().string() << " --latex -o proof.tex theorem.mf\n";
    std::cout << "    " << fs::path(programName).filename().string() << " --verbose --log-file compile.log theorem.mf\n";
}

void Application::showVersion() const {
    std::cout << core::Version::getBuildInfo() << std::endl;
    std::cout << core::Version::getCopyright() << std::endl;
}

bool Application::validateOptions() {
    // Input file is required unless showing help/version
    if (options_.inputFile.empty()) {
        std::cerr << "Error: No input file specified. Use --help for usage information." << std::endl;
        return false;
    }
    
    // Check if input file exists
    if (!fs::exists(options_.inputFile)) {
        std::cerr << "Error: Input file does not exist: " << options_.inputFile << std::endl;
        return false;
    }
    
    // Validate log level
    const std::vector<std::string> validLevels = {"trace", "debug", "info", "warn", "error", "fatal"};
    if (std::find(validLevels.begin(), validLevels.end(), options_.logLevel) == validLevels.end()) {
        std::cerr << "Error: Invalid log level: " << options_.logLevel << std::endl;
        return false;
    }
    
    // Set default output file if not specified
    if (options_.outputFile.empty()) {
        if (options_.generateLatex) {
            options_.outputFile = fs::path(options_.inputFile).stem().string() + ".tex";
        } else {
            options_.outputFile = fs::path(options_.inputFile).stem().string() + ".out";
        }
    }
    
    return true;
}

void Application::setupLogging() {
    // Convert string log level to enum
    core::LogLevel level = core::LogLevel::INFO;
    if (options_.logLevel == "trace") level = core::LogLevel::TRACE;
    else if (options_.logLevel == "debug") level = core::LogLevel::DEBUG;
    else if (options_.logLevel == "info") level = core::LogLevel::INFO;
    else if (options_.logLevel == "warn") level = core::LogLevel::WARN;
    else if (options_.logLevel == "error") level = core::LogLevel::ERROR;
    else if (options_.logLevel == "fatal") level = core::LogLevel::FATAL;
    
    // Initialize logger
    core::Logger::initialize(level, options_.logFile);
}

int Application::processFile() {
    try {
        std::cerr << "DEBUG: Starting processFile()" << std::endl;
        
        // Skip logging for now - might be causing the hang
        // LOG_INFO("Reading input file: " + options_.inputFile);
        std::cerr << "DEBUG: Reading input file: " << options_.inputFile << std::endl;
        
        // Read input file
        std::ifstream file(options_.inputFile);
        if (!file.is_open()) {
            throw core::IOException("Cannot open input file: " + options_.inputFile);
        }
        
        std::cerr << "DEBUG: File opened successfully" << std::endl;
        
        std::string content((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
        file.close();
        
        std::cerr << "DEBUG: File read, content length: " << content.length() << std::endl;
        std::cerr << "DEBUG: File read, content length: " << content.length() << std::endl;
        
        // Skip logging for now
        // LOG_INFO("Starting lexical analysis");
        std::cerr << "DEBUG: Starting lexical analysis" << std::endl;
        
        // Lexical analysis
        auto lexer = std::make_unique<lexer::Lexer>(content);
        std::cerr << "DEBUG: Lexer created" << std::endl;
        
        auto tokens = lexer->tokenize();
        std::cerr << "DEBUG: Tokenization complete, token count: " << tokens.size() << std::endl;
        
        // LOG_INFO("Found " + std::to_string(tokens.size()) + " tokens");
        std::cerr << "DEBUG: Found " << tokens.size() << " tokens" << std::endl;
        
        if (options_.verbose) {
            // LOG_DEBUG("Starting syntax analysis");
            std::cerr << "DEBUG: Starting syntax analysis" << std::endl;
        }
        
        // Syntax analysis
        std::cerr << "DEBUG: About to create parser" << std::endl;
        auto parser = std::make_unique<parser::Parser>(std::move(tokens));
        std::cerr << "DEBUG: Parser created" << std::endl;
        
        std::cerr << "DEBUG: About to call parser->parse()" << std::endl;
        auto ast = parser->parse();
        std::cerr << "DEBUG: AST parsing completed" << std::endl;
        
        // LOG_INFO("AST generated successfully");
        std::cerr << "DEBUG: AST generated successfully" << std::endl;
        
        if (options_.verbose) {
            // LOG_DEBUG("Starting semantic analysis");
            std::cerr << "DEBUG: Starting semantic analysis" << std::endl;
        }
        
        // Semantic analysis
        auto analyzer = std::make_unique<semantic::Analyzer>();
        analyzer->analyze(ast.get());
        
        // LOG_INFO("Semantic analysis completed");
        std::cerr << "DEBUG: Semantic analysis completed" << std::endl;
        
        // Proof verification (if enabled)
        if (options_.verify) {
            if (options_.verbose) {
                // LOG_DEBUG("Starting proof verification");
                std::cerr << "DEBUG: Starting proof verification" << std::endl;
            }
            
            auto verifier = std::make_unique<proof::Verifier>();
            bool verified = verifier->verify(ast.get());
            
            if (verified) {
                // LOG_INFO("Proof verification successful");
                std::cerr << "DEBUG: Proof verification successful" << std::endl;
            } else {
                // LOG_ERROR("Proof verification failed");
                std::cerr << "ERROR: Proof verification failed" << std::endl;
                return 3;
            }
        }
        
        // Code generation
        if (options_.generateLatex) {
            if (options_.verbose) {
                // LOG_DEBUG("Generating LaTeX output");
                std::cerr << "DEBUG: Generating LaTeX output" << std::endl;
            }
            
            auto generator = std::make_unique<codegen::LatexGenerator>();
            std::string output = generator->generate(ast.get());
            
            // Write output file
            std::ofstream outFile(options_.outputFile);
            if (!outFile.is_open()) {
                throw core::IOException("Cannot create output file: " + options_.outputFile);
            }
            
            outFile << output;
            outFile.close();
            
            // LOG_INFO("LaTeX output written to: " + options_.outputFile);
            std::cerr << "DEBUG: LaTeX output written to: " << options_.outputFile << std::endl;
        }
        
        // LOG_INFO("Compilation completed successfully");
        std::cerr << "DEBUG: Compilation completed successfully" << std::endl;
        return 0;
        
    } catch (const core::LexicalException& e) {
        // LOG_ERROR("Lexical error at line " + std::to_string(e.getLine()) + 
        //          ", column " + std::to_string(e.getColumn()) + ": " + e.what());
        std::cerr << "ERROR: Lexical error at line " << e.getLine() << 
                     ", column " << e.getColumn() << ": " << e.what() << std::endl;
        return 10;
        
    } catch (const core::SyntaxException& e) {
        // LOG_ERROR("Syntax error at line " + std::to_string(e.getLine()) + 
        //          ", column " + std::to_string(e.getColumn()) + ": " + e.what());
        std::cerr << "ERROR: Syntax error at line " << e.getLine() << 
                     ", column " << e.getColumn() << ": " << e.what() << std::endl;
        return 11;
        
    } catch (const core::SemanticException& e) {
        // LOG_ERROR("Semantic error: " + std::string(e.what()));
        std::cerr << "ERROR: Semantic error: " << e.what() << std::endl;
        return 12;
        
    } catch (const core::ProofException& e) {
        // LOG_ERROR("Proof error: " + std::string(e.what()));
        std::cerr << "ERROR: Proof error: " << e.what() << std::endl;
        return 13;
        
    } catch (const core::CodeGenException& e) {
        // LOG_ERROR("Code generation error: " + std::string(e.what()));
        std::cerr << "ERROR: Code generation error: " << e.what() << std::endl;
        return 14;
    }
}

} // namespace mathforge::cli
