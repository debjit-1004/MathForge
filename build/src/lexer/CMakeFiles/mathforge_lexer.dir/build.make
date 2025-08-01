# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shadow/projects/MathForge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shadow/projects/MathForge/build

# Include any dependencies generated for this target.
include src/lexer/CMakeFiles/mathforge_lexer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/lexer/CMakeFiles/mathforge_lexer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/lexer/CMakeFiles/mathforge_lexer.dir/progress.make

# Include the compile flags for this target's objects.
include src/lexer/CMakeFiles/mathforge_lexer.dir/flags.make

src/lexer/CMakeFiles/mathforge_lexer.dir/codegen:
.PHONY : src/lexer/CMakeFiles/mathforge_lexer.dir/codegen

src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o: src/lexer/CMakeFiles/mathforge_lexer.dir/flags.make
src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o: /home/shadow/projects/MathForge/src/lexer/token.cpp
src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o: src/lexer/CMakeFiles/mathforge_lexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o -MF CMakeFiles/mathforge_lexer.dir/token.cpp.o.d -o CMakeFiles/mathforge_lexer.dir/token.cpp.o -c /home/shadow/projects/MathForge/src/lexer/token.cpp

src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mathforge_lexer.dir/token.cpp.i"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/src/lexer/token.cpp > CMakeFiles/mathforge_lexer.dir/token.cpp.i

src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mathforge_lexer.dir/token.cpp.s"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/src/lexer/token.cpp -o CMakeFiles/mathforge_lexer.dir/token.cpp.s

src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o: src/lexer/CMakeFiles/mathforge_lexer.dir/flags.make
src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o: /home/shadow/projects/MathForge/src/lexer/lexer.cpp
src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o: src/lexer/CMakeFiles/mathforge_lexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o -MF CMakeFiles/mathforge_lexer.dir/lexer.cpp.o.d -o CMakeFiles/mathforge_lexer.dir/lexer.cpp.o -c /home/shadow/projects/MathForge/src/lexer/lexer.cpp

src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mathforge_lexer.dir/lexer.cpp.i"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/src/lexer/lexer.cpp > CMakeFiles/mathforge_lexer.dir/lexer.cpp.i

src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mathforge_lexer.dir/lexer.cpp.s"
	cd /home/shadow/projects/MathForge/build/src/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/src/lexer/lexer.cpp -o CMakeFiles/mathforge_lexer.dir/lexer.cpp.s

# Object files for target mathforge_lexer
mathforge_lexer_OBJECTS = \
"CMakeFiles/mathforge_lexer.dir/token.cpp.o" \
"CMakeFiles/mathforge_lexer.dir/lexer.cpp.o"

# External object files for target mathforge_lexer
mathforge_lexer_EXTERNAL_OBJECTS =

src/lexer/libmathforge_lexer.a: src/lexer/CMakeFiles/mathforge_lexer.dir/token.cpp.o
src/lexer/libmathforge_lexer.a: src/lexer/CMakeFiles/mathforge_lexer.dir/lexer.cpp.o
src/lexer/libmathforge_lexer.a: src/lexer/CMakeFiles/mathforge_lexer.dir/build.make
src/lexer/libmathforge_lexer.a: src/lexer/CMakeFiles/mathforge_lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmathforge_lexer.a"
	cd /home/shadow/projects/MathForge/build/src/lexer && $(CMAKE_COMMAND) -P CMakeFiles/mathforge_lexer.dir/cmake_clean_target.cmake
	cd /home/shadow/projects/MathForge/build/src/lexer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mathforge_lexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lexer/CMakeFiles/mathforge_lexer.dir/build: src/lexer/libmathforge_lexer.a
.PHONY : src/lexer/CMakeFiles/mathforge_lexer.dir/build

src/lexer/CMakeFiles/mathforge_lexer.dir/clean:
	cd /home/shadow/projects/MathForge/build/src/lexer && $(CMAKE_COMMAND) -P CMakeFiles/mathforge_lexer.dir/cmake_clean.cmake
.PHONY : src/lexer/CMakeFiles/mathforge_lexer.dir/clean

src/lexer/CMakeFiles/mathforge_lexer.dir/depend:
	cd /home/shadow/projects/MathForge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shadow/projects/MathForge /home/shadow/projects/MathForge/src/lexer /home/shadow/projects/MathForge/build /home/shadow/projects/MathForge/build/src/lexer /home/shadow/projects/MathForge/build/src/lexer/CMakeFiles/mathforge_lexer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/lexer/CMakeFiles/mathforge_lexer.dir/depend

