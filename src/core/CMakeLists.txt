# Core module CMakeLists.txt

set(CORE_SOURCES
    version_impl.cpp
    logger.cpp
    exceptions.cpp
)

set(CORE_HEADERS
    ${MATHFORGE_INCLUDE_DIR}/mathforge/core/version.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/core/logger.hpp
    ${MATHFORGE_INCLUDE_DIR}/mathforge/core/exceptions.hpp
)

add_library(mathforge_core ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(mathforge_core
    PUBLIC ${MATHFORGE_INCLUDE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(mathforge_core PUBLIC cxx_std_20)

# Link required libraries
target_link_libraries(mathforge_core
    PUBLIC Threads::Threads
)

# Set target properties
set_target_properties(mathforge_core PROPERTIES
    OUTPUT_NAME "mathforge_core"
    POSITION_INDEPENDENT_CODE ON
)

# Export target
target_include_directories(mathforge_core
    INTERFACE
    $<BUILD_INTERFACE:${MATHFORGE_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)
