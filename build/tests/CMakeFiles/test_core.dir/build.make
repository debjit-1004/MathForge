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
include tests/CMakeFiles/test_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_core.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_core.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_core.dir/flags.make

tests/CMakeFiles/test_core.dir/codegen:
.PHONY : tests/CMakeFiles/test_core.dir/codegen

tests/CMakeFiles/test_core.dir/test_main.cpp.o: tests/CMakeFiles/test_core.dir/flags.make
tests/CMakeFiles/test_core.dir/test_main.cpp.o: /home/shadow/projects/MathForge/tests/test_main.cpp
tests/CMakeFiles/test_core.dir/test_main.cpp.o: tests/CMakeFiles/test_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_core.dir/test_main.cpp.o"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_core.dir/test_main.cpp.o -MF CMakeFiles/test_core.dir/test_main.cpp.o.d -o CMakeFiles/test_core.dir/test_main.cpp.o -c /home/shadow/projects/MathForge/tests/test_main.cpp

tests/CMakeFiles/test_core.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_core.dir/test_main.cpp.i"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/tests/test_main.cpp > CMakeFiles/test_core.dir/test_main.cpp.i

tests/CMakeFiles/test_core.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_core.dir/test_main.cpp.s"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/tests/test_main.cpp -o CMakeFiles/test_core.dir/test_main.cpp.s

tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o: tests/CMakeFiles/test_core.dir/flags.make
tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o: /home/shadow/projects/MathForge/tests/core/test_logger.cpp
tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o: tests/CMakeFiles/test_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o -MF CMakeFiles/test_core.dir/core/test_logger.cpp.o.d -o CMakeFiles/test_core.dir/core/test_logger.cpp.o -c /home/shadow/projects/MathForge/tests/core/test_logger.cpp

tests/CMakeFiles/test_core.dir/core/test_logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_core.dir/core/test_logger.cpp.i"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/tests/core/test_logger.cpp > CMakeFiles/test_core.dir/core/test_logger.cpp.i

tests/CMakeFiles/test_core.dir/core/test_logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_core.dir/core/test_logger.cpp.s"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/tests/core/test_logger.cpp -o CMakeFiles/test_core.dir/core/test_logger.cpp.s

tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o: tests/CMakeFiles/test_core.dir/flags.make
tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o: /home/shadow/projects/MathForge/tests/core/test_exceptions.cpp
tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o: tests/CMakeFiles/test_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o -MF CMakeFiles/test_core.dir/core/test_exceptions.cpp.o.d -o CMakeFiles/test_core.dir/core/test_exceptions.cpp.o -c /home/shadow/projects/MathForge/tests/core/test_exceptions.cpp

tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_core.dir/core/test_exceptions.cpp.i"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/tests/core/test_exceptions.cpp > CMakeFiles/test_core.dir/core/test_exceptions.cpp.i

tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_core.dir/core/test_exceptions.cpp.s"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/tests/core/test_exceptions.cpp -o CMakeFiles/test_core.dir/core/test_exceptions.cpp.s

tests/CMakeFiles/test_core.dir/core/test_version.cpp.o: tests/CMakeFiles/test_core.dir/flags.make
tests/CMakeFiles/test_core.dir/core/test_version.cpp.o: /home/shadow/projects/MathForge/tests/core/test_version.cpp
tests/CMakeFiles/test_core.dir/core/test_version.cpp.o: tests/CMakeFiles/test_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/test_core.dir/core/test_version.cpp.o"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_core.dir/core/test_version.cpp.o -MF CMakeFiles/test_core.dir/core/test_version.cpp.o.d -o CMakeFiles/test_core.dir/core/test_version.cpp.o -c /home/shadow/projects/MathForge/tests/core/test_version.cpp

tests/CMakeFiles/test_core.dir/core/test_version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_core.dir/core/test_version.cpp.i"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow/projects/MathForge/tests/core/test_version.cpp > CMakeFiles/test_core.dir/core/test_version.cpp.i

tests/CMakeFiles/test_core.dir/core/test_version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_core.dir/core/test_version.cpp.s"
	cd /home/shadow/projects/MathForge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow/projects/MathForge/tests/core/test_version.cpp -o CMakeFiles/test_core.dir/core/test_version.cpp.s

# Object files for target test_core
test_core_OBJECTS = \
"CMakeFiles/test_core.dir/test_main.cpp.o" \
"CMakeFiles/test_core.dir/core/test_logger.cpp.o" \
"CMakeFiles/test_core.dir/core/test_exceptions.cpp.o" \
"CMakeFiles/test_core.dir/core/test_version.cpp.o"

# External object files for target test_core
test_core_EXTERNAL_OBJECTS =

tests/test_core: tests/CMakeFiles/test_core.dir/test_main.cpp.o
tests/test_core: tests/CMakeFiles/test_core.dir/core/test_logger.cpp.o
tests/test_core: tests/CMakeFiles/test_core.dir/core/test_exceptions.cpp.o
tests/test_core: tests/CMakeFiles/test_core.dir/core/test_version.cpp.o
tests/test_core: tests/CMakeFiles/test_core.dir/build.make
tests/test_core: tests/CMakeFiles/test_core.dir/compiler_depend.ts
tests/test_core: src/core/libmathforge_core.a
tests/test_core: tests/CMakeFiles/test_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/shadow/projects/MathForge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test_core"
	cd /home/shadow/projects/MathForge/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_core.dir/build: tests/test_core
.PHONY : tests/CMakeFiles/test_core.dir/build

tests/CMakeFiles/test_core.dir/clean:
	cd /home/shadow/projects/MathForge/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_core.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_core.dir/clean

tests/CMakeFiles/test_core.dir/depend:
	cd /home/shadow/projects/MathForge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shadow/projects/MathForge /home/shadow/projects/MathForge/tests /home/shadow/projects/MathForge/build /home/shadow/projects/MathForge/build/tests /home/shadow/projects/MathForge/build/tests/CMakeFiles/test_core.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_core.dir/depend

