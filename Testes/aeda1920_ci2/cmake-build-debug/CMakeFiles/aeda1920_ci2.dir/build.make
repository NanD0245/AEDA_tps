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
CMAKE_SOURCE_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aeda1920_ci2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda1920_ci2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda1920_ci2.dir/flags.make

CMakeFiles/aeda1920_ci2.dir/main.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda1920_ci2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/main.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/main.cpp

CMakeFiles/aeda1920_ci2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/main.cpp > CMakeFiles/aeda1920_ci2.dir/main.cpp.i

CMakeFiles/aeda1920_ci2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/main.cpp -o CMakeFiles/aeda1920_ci2.dir/main.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/tests.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/tests.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/tests.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o: ../Tests/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Object.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Object.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Object.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o: ../Tests/WideFlatBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/WideFlatBox.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/WideFlatBox.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/WideFlatBox.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o: ../Tests/ThinTallBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/ThinTallBox.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/ThinTallBox.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/ThinTallBox.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o: ../Tests/Box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Box.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Box.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Box.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.s

CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o: CMakeFiles/aeda1920_ci2.dir/flags.make
CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o: ../Tests/Warehouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Warehouse.cpp

CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Warehouse.cpp > CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.i

CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/Tests/Warehouse.cpp -o CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.s

# Object files for target aeda1920_ci2
aeda1920_ci2_OBJECTS = \
"CMakeFiles/aeda1920_ci2.dir/main.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o" \
"CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o"

# External object files for target aeda1920_ci2
aeda1920_ci2_EXTERNAL_OBJECTS =

aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/main.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/tests.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/Object.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/WideFlatBox.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/ThinTallBox.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/Box.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/Tests/Warehouse.cpp.o
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/build.make
aeda1920_ci2: lib/libgtestd.a
aeda1920_ci2: lib/libgtest_maind.a
aeda1920_ci2: lib/libgtestd.a
aeda1920_ci2: CMakeFiles/aeda1920_ci2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable aeda1920_ci2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aeda1920_ci2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda1920_ci2.dir/build: aeda1920_ci2

.PHONY : CMakeFiles/aeda1920_ci2.dir/build

CMakeFiles/aeda1920_ci2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aeda1920_ci2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aeda1920_ci2.dir/clean

CMakeFiles/aeda1920_ci2.dir/depend:
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2 /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2 /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1920_ci2/cmake-build-debug/CMakeFiles/aeda1920_ci2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aeda1920_ci2.dir/depend

