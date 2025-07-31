# AST module CMakeLists.txt

set(AST_SOURCES
    node.cpp
    expression.cpp
    statement.cpp
    visitor.cpp
)

set(AST_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/ast/node.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/ast/expression.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/ast/statement.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/ast/visitor.hpp
)

add_library(mathforge_ast ${AST_SOURCES} ${AST_HEADERS})

target_include_directories(mathforge_ast
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_ast PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_ast
    PUBLIC mathforge_core
)

# Set target properties
set_target_properties(mathforge_ast PROPERTIES
    OUTPUT_NAME "mathforge_ast"
    POSITION_INDEPENDENT_CODE ON
)
