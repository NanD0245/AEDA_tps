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
CMAKE_SOURCE_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aeda1819_ci1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda1819_ci1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda1819_ci1.dir/flags.make

CMakeFiles/aeda1819_ci1.dir/main.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda1819_ci1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/main.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/main.cpp

CMakeFiles/aeda1819_ci1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/main.cpp > CMakeFiles/aeda1819_ci1.dir/main.cpp.i

CMakeFiles/aeda1819_ci1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/main.cpp -o CMakeFiles/aeda1819_ci1.dir/main.cpp.s

CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/tests.cpp

CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/tests.cpp > CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.i

CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/tests.cpp -o CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.s

CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o: ../Tests/Account.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Account.cpp

CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Account.cpp > CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.i

CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Account.cpp -o CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.s

CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o: ../Tests/Bank.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Bank.cpp

CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Bank.cpp > CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.i

CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/Bank.cpp -o CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.s

CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o: ../Tests/BankOfficer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/BankOfficer.cpp

CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/BankOfficer.cpp > CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.i

CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/BankOfficer.cpp -o CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.s

CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o: CMakeFiles/aeda1819_ci1.dir/flags.make
CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o: ../Tests/funcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o -c /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/funcs.cpp

CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/funcs.cpp > CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.i

CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/Tests/funcs.cpp -o CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.s

# Object files for target aeda1819_ci1
aeda1819_ci1_OBJECTS = \
"CMakeFiles/aeda1819_ci1.dir/main.cpp.o" \
"CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o" \
"CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o" \
"CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o" \
"CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o" \
"CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o"

# External object files for target aeda1819_ci1
aeda1819_ci1_EXTERNAL_OBJECTS =

aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/main.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/Tests/tests.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/Tests/Account.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/Tests/Bank.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/Tests/BankOfficer.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/Tests/funcs.cpp.o
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/build.make
aeda1819_ci1: lib/libgtestd.a
aeda1819_ci1: lib/libgtest_maind.a
aeda1819_ci1: lib/libgtestd.a
aeda1819_ci1: CMakeFiles/aeda1819_ci1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable aeda1819_ci1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aeda1819_ci1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda1819_ci1.dir/build: aeda1819_ci1

.PHONY : CMakeFiles/aeda1819_ci1.dir/build

CMakeFiles/aeda1819_ci1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aeda1819_ci1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aeda1819_ci1.dir/clean

CMakeFiles/aeda1819_ci1.dir/depend:
	cd /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug /home/mim/Documents/FEUP/2ano/Cadeiras/AEDA/Testes/aeda1819_ci1_googleTest/cmake-build-debug/CMakeFiles/aeda1819_ci1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aeda1819_ci1.dir/depend
