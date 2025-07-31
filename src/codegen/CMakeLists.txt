# Code generation module CMakeLists.txt

set(CODEGEN_SOURCES
    latex_generator.cpp
    generator_base.cpp
)

set(CODEGEN_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/codegen/latex_generator.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/codegen/generator_base.hpp
)

add_library(mathforge_codegen ${CODEGEN_SOURCES} ${CODEGEN_HEADERS})

target_include_directories(mathforge_codegen
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_codegen PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_codegen
    PUBLIC mathforge_core
    PUBLIC mathforge_ast
)

# Set target properties
set_target_properties(mathforge_codegen PROPERTIES
    OUTPUT_NAME "mathforge_codegen"
    POSITION_INDEPENDENT_CODE ON
)
