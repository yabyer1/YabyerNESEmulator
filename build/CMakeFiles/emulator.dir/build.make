# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build

# Include any dependencies generated for this target.
include CMakeFiles/emulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/emulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/emulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/emulator.dir/flags.make

CMakeFiles/emulator.dir/cpu.cpp.o: CMakeFiles/emulator.dir/flags.make
CMakeFiles/emulator.dir/cpu.cpp.o: /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/cpu.cpp
CMakeFiles/emulator.dir/cpu.cpp.o: CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/emulator.dir/cpu.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emulator.dir/cpu.cpp.o -MF CMakeFiles/emulator.dir/cpu.cpp.o.d -o CMakeFiles/emulator.dir/cpu.cpp.o -c /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/cpu.cpp

CMakeFiles/emulator.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/cpu.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/cpu.cpp > CMakeFiles/emulator.dir/cpu.cpp.i

CMakeFiles/emulator.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/cpu.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/cpu.cpp -o CMakeFiles/emulator.dir/cpu.cpp.s

CMakeFiles/emulator.dir/instructions/LDA.cpp.o: CMakeFiles/emulator.dir/flags.make
CMakeFiles/emulator.dir/instructions/LDA.cpp.o: /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/LDA.cpp
CMakeFiles/emulator.dir/instructions/LDA.cpp.o: CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/emulator.dir/instructions/LDA.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emulator.dir/instructions/LDA.cpp.o -MF CMakeFiles/emulator.dir/instructions/LDA.cpp.o.d -o CMakeFiles/emulator.dir/instructions/LDA.cpp.o -c /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/LDA.cpp

CMakeFiles/emulator.dir/instructions/LDA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/instructions/LDA.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/LDA.cpp > CMakeFiles/emulator.dir/instructions/LDA.cpp.i

CMakeFiles/emulator.dir/instructions/LDA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/instructions/LDA.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/LDA.cpp -o CMakeFiles/emulator.dir/instructions/LDA.cpp.s

CMakeFiles/emulator.dir/instructions/ADC.cpp.o: CMakeFiles/emulator.dir/flags.make
CMakeFiles/emulator.dir/instructions/ADC.cpp.o: /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/ADC.cpp
CMakeFiles/emulator.dir/instructions/ADC.cpp.o: CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/emulator.dir/instructions/ADC.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emulator.dir/instructions/ADC.cpp.o -MF CMakeFiles/emulator.dir/instructions/ADC.cpp.o.d -o CMakeFiles/emulator.dir/instructions/ADC.cpp.o -c /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/ADC.cpp

CMakeFiles/emulator.dir/instructions/ADC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/instructions/ADC.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/ADC.cpp > CMakeFiles/emulator.dir/instructions/ADC.cpp.i

CMakeFiles/emulator.dir/instructions/ADC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/instructions/ADC.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/instructions/ADC.cpp -o CMakeFiles/emulator.dir/instructions/ADC.cpp.s

# Object files for target emulator
emulator_OBJECTS = \
"CMakeFiles/emulator.dir/cpu.cpp.o" \
"CMakeFiles/emulator.dir/instructions/LDA.cpp.o" \
"CMakeFiles/emulator.dir/instructions/ADC.cpp.o"

# External object files for target emulator
emulator_EXTERNAL_OBJECTS =

emulator: CMakeFiles/emulator.dir/cpu.cpp.o
emulator: CMakeFiles/emulator.dir/instructions/LDA.cpp.o
emulator: CMakeFiles/emulator.dir/instructions/ADC.cpp.o
emulator: CMakeFiles/emulator.dir/build.make
emulator: CMakeFiles/emulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable emulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/emulator.dir/build: emulator
.PHONY : CMakeFiles/emulator.dir/build

CMakeFiles/emulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/emulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/emulator.dir/clean

CMakeFiles/emulator.dir/depend:
	cd /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build /Users/ganapathynagasubramaniam/Desktop/YabyerEmulation/build/CMakeFiles/emulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/emulator.dir/depend
