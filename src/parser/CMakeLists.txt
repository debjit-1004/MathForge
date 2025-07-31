# Parser module CMakeLists.txt

set(PARSER_SOURCES
    parser.cpp
)

set(PARSER_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/parser/parser.hpp
)

add_library(mathforge_parser ${PARSER_SOURCES} ${PARSER_HEADERS})

target_include_directories(mathforge_parser
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_parser PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_parser
    PUBLIC mathforge_core
    PUBLIC mathforge_lexer
    PUBLIC mathforge_ast
)

# Set target properties
set_target_properties(mathforge_parser PROPERTIES
    OUTPUT_NAME "mathforge_parser"
    POSITION_INDEPENDENT_CODE ON
)
