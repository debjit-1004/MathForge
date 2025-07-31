# Proof module CMakeLists.txt

set(PROOF_SOURCES
    verifier.cpp
    proof_engine.cpp
    logic_rules.cpp
)

set(PROOF_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/proof/verifier.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/proof/proof_engine.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/proof/logic_rules.hpp
)

add_library(mathforge_proof ${PROOF_SOURCES} ${PROOF_HEADERS})

target_include_directories(mathforge_proof
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_proof PUBLIC cxx_std_20)

# Link dependencies
target_link_libraries(mathforge_proof
    PUBLIC mathforge_core
    PUBLIC mathforge_ast
    PUBLIC mathforge_semantic
)

# Set target properties
set_target_properties(mathforge_proof PROPERTIES
    OUTPUT_NAME "mathforge_proof"
    POSITION_INDEPENDENT_CODE ON
)
