# Tests CMakeLists.txt

# Test executable for core module
add_executable(test_core
    test_main.cpp
    core/test_logger.cpp
    core/test_exceptions.cpp
    core/test_version.cpp
)

target_link_libraries(test_core
    PRIVATE mathforge_core
    PRIVATE gtest
    PRIVATE gtest_main
)

target_include_directories(test_core
    PRIVATE ${MATHFORGE_INCLUDE_DIR}
    PRIVATE $<TARGET_PROPERTY:gtest,INTERFACE_INCLUDE_DIRECTORIES>
)

# Test executable for lexer module
add_executable(test_lexer
    test_main.cpp
    lexer/test_token.cpp
    lexer/test_lexer.cpp
)

target_link_libraries(test_lexer
    PRIVATE mathforge_lexer
    PRIVATE mathforge_core
    PRIVATE gtest
    PRIVATE gtest_main
)

target_include_directories(test_lexer
    PRIVATE ${MATHFORGE_INCLUDE_DIR}
    PRIVATE $<TARGET_PROPERTY:gtest,INTERFACE_INCLUDE_DIRECTORIES>
)

# Add tests to CTest
add_test(NAME CoreTests COMMAND test_core)
add_test(NAME LexerTests COMMAND test_lexer)

# Set test properties
set_tests_properties(CoreTests LexerTests PROPERTIES
    TIMEOUT 30
)
