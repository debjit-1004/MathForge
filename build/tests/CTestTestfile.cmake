# CMake generated Testfile for 
# Source directory: /home/shadow/projects/MathForge/tests
# Build directory: /home/shadow/projects/MathForge/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[CoreTests]=] "/home/shadow/projects/MathForge/build/tests/test_core")
set_tests_properties([=[CoreTests]=] PROPERTIES  TIMEOUT "30" _BACKTRACE_TRIPLES "/home/shadow/projects/MathForge/tests/CMakeLists.txt;40;add_test;/home/shadow/projects/MathForge/tests/CMakeLists.txt;0;")
add_test([=[LexerTests]=] "/home/shadow/projects/MathForge/build/tests/test_lexer")
set_tests_properties([=[LexerTests]=] PROPERTIES  TIMEOUT "30" _BACKTRACE_TRIPLES "/home/shadow/projects/MathForge/tests/CMakeLists.txt;41;add_test;/home/shadow/projects/MathForge/tests/CMakeLists.txt;0;")
