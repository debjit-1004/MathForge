# Semantic module CMakeLists.txt

set(SEMANTIC_SOURCES
    analyzer.cpp
    symbol_table.cpp
    type_checker.cpp
)

set(SEMANTIC_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/semantic/analyzer.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/semantic/symbol_table.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/semantic/type_checker.hpp
)

add_library(mathforge_semantic ${SEMANTIC_SOURCES} ${SEMANTIC_HEADERS})

target_include_directories(mathforge_semantic
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_semantic PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_semantic
    PUBLIC mathforge_core
    PUBLIC mathforge_ast
)

# Set target properties
set_target_properties(mathforge_semantic PROPERTIES
    OUTPUT_NAME "mathforge_semantic"
    POSITION_INDEPENDENT_CODE ON
)
