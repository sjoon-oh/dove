# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/msra-vectordb-small/dove

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oslab/sjoon/msra-workspace/dataset-small/dove

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/oslab/sjoon/msra-workspace/dataset-small/dove/CMakeFiles /home/oslab/sjoon/msra-workspace/dataset-small/dove//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/oslab/sjoon/msra-workspace/dataset-small/dove/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -P /home/oslab/sjoon/msra-workspace/dataset-small/dove/CMakeFiles/VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named dove

# Build rule for target.
dove: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dove
.PHONY : dove

# fast build rule for target.
dove/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/build
.PHONY : dove/fast

#=============================================================================
# Target rules for targets named dove-testbin

# Build rule for target.
dove-testbin: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dove-testbin
.PHONY : dove-testbin

# fast build rule for target.
dove-testbin/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-testbin.dir/build.make CMakeFiles/dove-testbin.dir/build
.PHONY : dove-testbin/fast

#=============================================================================
# Target rules for targets named dove-generator

# Build rule for target.
dove-generator: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dove-generator
.PHONY : dove-generator

# fast build rule for target.
dove-generator/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-generator.dir/build.make CMakeFiles/dove-generator.dir/build
.PHONY : dove-generator/fast

#=============================================================================
# Target rules for targets named dove-reader

# Build rule for target.
dove-reader: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dove-reader
.PHONY : dove-reader

# fast build rule for target.
dove-reader/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-reader.dir/build.make CMakeFiles/dove-reader.dir/build
.PHONY : dove-reader/fast

src/DoveFileGenerator.o: src/DoveFileGenerator.cc.o
.PHONY : src/DoveFileGenerator.o

# target to build an object file
src/DoveFileGenerator.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileGenerator.cc.o
.PHONY : src/DoveFileGenerator.cc.o

src/DoveFileGenerator.i: src/DoveFileGenerator.cc.i
.PHONY : src/DoveFileGenerator.i

# target to preprocess a source file
src/DoveFileGenerator.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileGenerator.cc.i
.PHONY : src/DoveFileGenerator.cc.i

src/DoveFileGenerator.s: src/DoveFileGenerator.cc.s
.PHONY : src/DoveFileGenerator.s

# target to generate assembly for a file
src/DoveFileGenerator.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileGenerator.cc.s
.PHONY : src/DoveFileGenerator.cc.s

src/DoveFileReader.o: src/DoveFileReader.cc.o
.PHONY : src/DoveFileReader.o

# target to build an object file
src/DoveFileReader.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileReader.cc.o
.PHONY : src/DoveFileReader.cc.o

src/DoveFileReader.i: src/DoveFileReader.cc.i
.PHONY : src/DoveFileReader.i

# target to preprocess a source file
src/DoveFileReader.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileReader.cc.i
.PHONY : src/DoveFileReader.cc.i

src/DoveFileReader.s: src/DoveFileReader.cc.s
.PHONY : src/DoveFileReader.s

# target to generate assembly for a file
src/DoveFileReader.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveFileReader.cc.s
.PHONY : src/DoveFileReader.cc.s

src/DoveLogger.o: src/DoveLogger.cc.o
.PHONY : src/DoveLogger.o

# target to build an object file
src/DoveLogger.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveLogger.cc.o
.PHONY : src/DoveLogger.cc.o

src/DoveLogger.i: src/DoveLogger.cc.i
.PHONY : src/DoveLogger.i

# target to preprocess a source file
src/DoveLogger.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveLogger.cc.i
.PHONY : src/DoveLogger.cc.i

src/DoveLogger.s: src/DoveLogger.cc.s
.PHONY : src/DoveLogger.s

# target to generate assembly for a file
src/DoveLogger.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveLogger.cc.s
.PHONY : src/DoveLogger.cc.s

src/DoveStopWatch.o: src/DoveStopWatch.cc.o
.PHONY : src/DoveStopWatch.o

# target to build an object file
src/DoveStopWatch.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveStopWatch.cc.o
.PHONY : src/DoveStopWatch.cc.o

src/DoveStopWatch.i: src/DoveStopWatch.cc.i
.PHONY : src/DoveStopWatch.i

# target to preprocess a source file
src/DoveStopWatch.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveStopWatch.cc.i
.PHONY : src/DoveStopWatch.cc.i

src/DoveStopWatch.s: src/DoveStopWatch.cc.s
.PHONY : src/DoveStopWatch.s

# target to generate assembly for a file
src/DoveStopWatch.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove.dir/build.make CMakeFiles/dove.dir/src/DoveStopWatch.cc.s
.PHONY : src/DoveStopWatch.cc.s

src/tests/dove-generate.o: src/tests/dove-generate.cc.o
.PHONY : src/tests/dove-generate.o

# target to build an object file
src/tests/dove-generate.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-generator.dir/build.make CMakeFiles/dove-generator.dir/src/tests/dove-generate.cc.o
.PHONY : src/tests/dove-generate.cc.o

src/tests/dove-generate.i: src/tests/dove-generate.cc.i
.PHONY : src/tests/dove-generate.i

# target to preprocess a source file
src/tests/dove-generate.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-generator.dir/build.make CMakeFiles/dove-generator.dir/src/tests/dove-generate.cc.i
.PHONY : src/tests/dove-generate.cc.i

src/tests/dove-generate.s: src/tests/dove-generate.cc.s
.PHONY : src/tests/dove-generate.s

# target to generate assembly for a file
src/tests/dove-generate.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-generator.dir/build.make CMakeFiles/dove-generator.dir/src/tests/dove-generate.cc.s
.PHONY : src/tests/dove-generate.cc.s

src/tests/dove-reader.o: src/tests/dove-reader.cc.o
.PHONY : src/tests/dove-reader.o

# target to build an object file
src/tests/dove-reader.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-reader.dir/build.make CMakeFiles/dove-reader.dir/src/tests/dove-reader.cc.o
.PHONY : src/tests/dove-reader.cc.o

src/tests/dove-reader.i: src/tests/dove-reader.cc.i
.PHONY : src/tests/dove-reader.i

# target to preprocess a source file
src/tests/dove-reader.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-reader.dir/build.make CMakeFiles/dove-reader.dir/src/tests/dove-reader.cc.i
.PHONY : src/tests/dove-reader.cc.i

src/tests/dove-reader.s: src/tests/dove-reader.cc.s
.PHONY : src/tests/dove-reader.s

# target to generate assembly for a file
src/tests/dove-reader.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-reader.dir/build.make CMakeFiles/dove-reader.dir/src/tests/dove-reader.cc.s
.PHONY : src/tests/dove-reader.cc.s

src/tests/dove-test.o: src/tests/dove-test.cc.o
.PHONY : src/tests/dove-test.o

# target to build an object file
src/tests/dove-test.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-testbin.dir/build.make CMakeFiles/dove-testbin.dir/src/tests/dove-test.cc.o
.PHONY : src/tests/dove-test.cc.o

src/tests/dove-test.i: src/tests/dove-test.cc.i
.PHONY : src/tests/dove-test.i

# target to preprocess a source file
src/tests/dove-test.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-testbin.dir/build.make CMakeFiles/dove-testbin.dir/src/tests/dove-test.cc.i
.PHONY : src/tests/dove-test.cc.i

src/tests/dove-test.s: src/tests/dove-test.cc.s
.PHONY : src/tests/dove-test.s

# target to generate assembly for a file
src/tests/dove-test.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dove-testbin.dir/build.make CMakeFiles/dove-testbin.dir/src/tests/dove-test.cc.s
.PHONY : src/tests/dove-test.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... dove"
	@echo "... dove-generator"
	@echo "... dove-reader"
	@echo "... dove-testbin"
	@echo "... src/DoveFileGenerator.o"
	@echo "... src/DoveFileGenerator.i"
	@echo "... src/DoveFileGenerator.s"
	@echo "... src/DoveFileReader.o"
	@echo "... src/DoveFileReader.i"
	@echo "... src/DoveFileReader.s"
	@echo "... src/DoveLogger.o"
	@echo "... src/DoveLogger.i"
	@echo "... src/DoveLogger.s"
	@echo "... src/DoveStopWatch.o"
	@echo "... src/DoveStopWatch.i"
	@echo "... src/DoveStopWatch.s"
	@echo "... src/tests/dove-generate.o"
	@echo "... src/tests/dove-generate.i"
	@echo "... src/tests/dove-generate.s"
	@echo "... src/tests/dove-reader.o"
	@echo "... src/tests/dove-reader.i"
	@echo "... src/tests/dove-reader.s"
	@echo "... src/tests/dove-test.o"
	@echo "... src/tests/dove-test.i"
	@echo "... src/tests/dove-test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -P /home/oslab/sjoon/msra-workspace/dataset-small/dove/CMakeFiles/VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

