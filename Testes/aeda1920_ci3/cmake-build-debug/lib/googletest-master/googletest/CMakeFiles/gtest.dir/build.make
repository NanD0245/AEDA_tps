# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mim/Documents/CLion/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mim/Documents/CLion/clion-2020.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug

# Include any dependencies generated for this target.
include lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-master/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make

lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: lib/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make
lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/lib/googletest-master/googletest/src/gtest-all.cc

lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/lib/googletest-master/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/lib/googletest-master/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: lib/googletest-master/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: lib/googletest-master/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../libgtestd.a"
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-master/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a

.PHONY : lib/googletest-master/googletest/CMakeFiles/gtest.dir/build

lib/googletest-master/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : lib/googletest-master/googletest/CMakeFiles/gtest.dir/clean

lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3 /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/lib/googletest-master/googletest /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest /home/mim/Documents/FEUP/2ano/Cadeiras/1Semestre/AEDA/Testes/aeda1920_ci3/cmake-build-debug/lib/googletest-master/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend

