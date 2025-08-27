cmake_minimum_required(VERSION 3.20)

project(MathForge 
    VERSION 1.0.0 
    DESCRIPTION "Mathematical Proof Language Compiler"
    LANGUAGES CXX
)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler-specific options
if(MSVC)
    add_compile_options(/W4 /WX /utf-8)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0 --coverage)
        add_link_options(--coverage)
    endif()
endif()

# Enable testing
enable_testing()

# Find required packages
find_package(Threads REQUIRED)

# Option to build tests
option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_DOCS "Build documentation" OFF)
option(BUILD_EXAMPLES "Build examples" ON)

# Include directories
set(MATHFORGE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${MATHFORGE_INCLUDE_DIR})

# Add subdirectories for each module
add_subdirectory(src/core)
add_subdirectory(src/lexer)
add_subdirectory(src/parser)
add_subdirectory(src/ast)
add_subdirectory(src/semantic)
add_subdirectory(src/proof)
add_subdirectory(src/codegen)
add_subdirectory(src/cli)

# Main executable
add_executable(mathforge src/main.cpp)
target_link_libraries(mathforge PRIVATE
    mathforge_cli
    mathforge_codegen
    mathforge_proof
    mathforge_semantic
    mathforge_parser
    mathforge_lexer
    mathforge_ast
    mathforge_core
    Threads::Threads
)

# Set executable properties
set_target_properties(mathforge PROPERTIES
    OUTPUT_NAME "mathforge"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install targets
install(TARGETS mathforge
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)

# Add tests if enabled
if(BUILD_TESTS)
    # Try to find Google Test
    find_package(GTest QUIET)
    if(NOT GTest_FOUND)
        # Download and build Google Test
        include(FetchContent)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1
        )
        FetchContent_MakeAvailable(googletest)
    endif()
    
    add_subdirectory(tests)
endif()

# Add examples if enabled
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Documentation with Doxygen
if(BUILD_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        
        add_custom_target(docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )
    else()
        message(WARNING "Doxygen not found, cannot build documentation")
    endif()
endif()

# Print build information
message(STATUS "MathForge Build Configuration:")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ Standard: C++${CMAKE_CXX_STANDARD}")
message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Build Tests: ${BUILD_TESTS}")
message(STATUS "  Build Docs: ${BUILD_DOCS}")
message(STATUS "  Build Examples: ${BUILD_EXAMPLES}")

target_sources(mathforge_core PRIVATE src/core/unicode_normalize.cpp)