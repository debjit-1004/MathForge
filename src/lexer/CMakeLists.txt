# Lexer module CMakeLists.txt

set(LEXER_SOURCES
    token.cpp
    lexer.cpp
)

set(LEXER_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/lexer/token.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/lexer/lexer.hpp
)

add_library(mathforge_lexer ${LEXER_SOURCES} ${LEXER_HEADERS})

target_include_directories(mathforge_lexer
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_lexer PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_lexer
    PUBLIC mathforge_core
)

# Set target properties
set_target_properties(mathforge_lexer PROPERTIES
    OUTPUT_NAME "mathforge_lexer"
    POSITION_INDEPENDENT_CODE ON
)
