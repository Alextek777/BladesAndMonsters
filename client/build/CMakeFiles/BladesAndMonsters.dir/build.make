# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/kalex/projects/BladesAndMonsters/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kalex/projects/BladesAndMonsters/client/build

# Include any dependencies generated for this target.
include CMakeFiles/BladesAndMonsters.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BladesAndMonsters.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BladesAndMonsters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BladesAndMonsters.dir/flags.make

CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o: CMakeFiles/BladesAndMonsters.dir/flags.make
CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o: /home/kalex/projects/BladesAndMonsters/client/src/engine/engine.cpp
CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o: CMakeFiles/BladesAndMonsters.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/projects/BladesAndMonsters/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o -MF CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o.d -o CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o -c /home/kalex/projects/BladesAndMonsters/client/src/engine/engine.cpp

CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/projects/BladesAndMonsters/client/src/engine/engine.cpp > CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.i

CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/projects/BladesAndMonsters/client/src/engine/engine.cpp -o CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.s

CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o: CMakeFiles/BladesAndMonsters.dir/flags.make
CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o: /home/kalex/projects/BladesAndMonsters/client/src/main.cpp
CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o: CMakeFiles/BladesAndMonsters.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/projects/BladesAndMonsters/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o -MF CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o.d -o CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o -c /home/kalex/projects/BladesAndMonsters/client/src/main.cpp

CMakeFiles/BladesAndMonsters.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BladesAndMonsters.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/projects/BladesAndMonsters/client/src/main.cpp > CMakeFiles/BladesAndMonsters.dir/src/main.cpp.i

CMakeFiles/BladesAndMonsters.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BladesAndMonsters.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/projects/BladesAndMonsters/client/src/main.cpp -o CMakeFiles/BladesAndMonsters.dir/src/main.cpp.s

CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o: CMakeFiles/BladesAndMonsters.dir/flags.make
CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o: /home/kalex/projects/BladesAndMonsters/client/src/maps/cMap.cpp
CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o: CMakeFiles/BladesAndMonsters.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/projects/BladesAndMonsters/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o -MF CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o.d -o CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o -c /home/kalex/projects/BladesAndMonsters/client/src/maps/cMap.cpp

CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/projects/BladesAndMonsters/client/src/maps/cMap.cpp > CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.i

CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/projects/BladesAndMonsters/client/src/maps/cMap.cpp -o CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.s

# Object files for target BladesAndMonsters
BladesAndMonsters_OBJECTS = \
"CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o" \
"CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o" \
"CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o"

# External object files for target BladesAndMonsters
BladesAndMonsters_EXTERNAL_OBJECTS =

bin/BladesAndMonsters: CMakeFiles/BladesAndMonsters.dir/src/engine/engine.cpp.o
bin/BladesAndMonsters: CMakeFiles/BladesAndMonsters.dir/src/main.cpp.o
bin/BladesAndMonsters: CMakeFiles/BladesAndMonsters.dir/src/maps/cMap.cpp.o
bin/BladesAndMonsters: CMakeFiles/BladesAndMonsters.dir/build.make
bin/BladesAndMonsters: CMakeFiles/BladesAndMonsters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kalex/projects/BladesAndMonsters/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/BladesAndMonsters"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BladesAndMonsters.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BladesAndMonsters.dir/build: bin/BladesAndMonsters
.PHONY : CMakeFiles/BladesAndMonsters.dir/build

CMakeFiles/BladesAndMonsters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BladesAndMonsters.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BladesAndMonsters.dir/clean

CMakeFiles/BladesAndMonsters.dir/depend:
	cd /home/kalex/projects/BladesAndMonsters/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kalex/projects/BladesAndMonsters/client /home/kalex/projects/BladesAndMonsters/client /home/kalex/projects/BladesAndMonsters/client/build /home/kalex/projects/BladesAndMonsters/client/build /home/kalex/projects/BladesAndMonsters/client/build/CMakeFiles/BladesAndMonsters.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BladesAndMonsters.dir/depend

