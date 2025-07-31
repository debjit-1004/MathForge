# CLI module CMakeLists.txt

set(CLI_SOURCES
    application.cpp
)

set(CLI_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/cli/application.hpp
)

add_library(mathforge_cli ${CLI_SOURCES} ${CLI_HEADERS})

target_include_directories(mathforge_cli
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_cli PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_cli
    PUBLIC mathforge_core
    PRIVATE mathforge_lexer
    PRIVATE mathforge_parser
    PRIVATE mathforge_semantic
    PRIVATE mathforge_proof
    PRIVATE mathforge_codegen
)

# Set target properties
set_target_properties(mathforge_cli PROPERTIES
    OUTPUT_NAME "mathforge_cli"
    POSITION_INDEPENDENT_CODE ON
)
