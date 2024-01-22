# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/harry/Coding/C_Programs/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harry/Coding/C_Programs/raytracer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/harry/Coding/C_Programs/raytracer/CMakeFiles /home/harry/Coding/C_Programs/raytracer//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/harry/Coding/C_Programs/raytracer/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.c.s
.PHONY : main.c.s

src/hitrecord.o: src/hitrecord.c.o
.PHONY : src/hitrecord.o

# target to build an object file
src/hitrecord.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hitrecord.c.o
.PHONY : src/hitrecord.c.o

src/hitrecord.i: src/hitrecord.c.i
.PHONY : src/hitrecord.i

# target to preprocess a source file
src/hitrecord.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hitrecord.c.i
.PHONY : src/hitrecord.c.i

src/hitrecord.s: src/hitrecord.c.s
.PHONY : src/hitrecord.s

# target to generate assembly for a file
src/hitrecord.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hitrecord.c.s
.PHONY : src/hitrecord.c.s

src/hittables_list.o: src/hittables_list.c.o
.PHONY : src/hittables_list.o

# target to build an object file
src/hittables_list.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hittables_list.c.o
.PHONY : src/hittables_list.c.o

src/hittables_list.i: src/hittables_list.c.i
.PHONY : src/hittables_list.i

# target to preprocess a source file
src/hittables_list.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hittables_list.c.i
.PHONY : src/hittables_list.c.i

src/hittables_list.s: src/hittables_list.c.s
.PHONY : src/hittables_list.s

# target to generate assembly for a file
src/hittables_list.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/hittables_list.c.s
.PHONY : src/hittables_list.c.s

src/ray.o: src/ray.c.o
.PHONY : src/ray.o

# target to build an object file
src/ray.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ray.c.o
.PHONY : src/ray.c.o

src/ray.i: src/ray.c.i
.PHONY : src/ray.i

# target to preprocess a source file
src/ray.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ray.c.i
.PHONY : src/ray.c.i

src/ray.s: src/ray.c.s
.PHONY : src/ray.s

# target to generate assembly for a file
src/ray.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ray.c.s
.PHONY : src/ray.c.s

src/sphere.o: src/sphere.c.o
.PHONY : src/sphere.o

# target to build an object file
src/sphere.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/sphere.c.o
.PHONY : src/sphere.c.o

src/sphere.i: src/sphere.c.i
.PHONY : src/sphere.i

# target to preprocess a source file
src/sphere.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/sphere.c.i
.PHONY : src/sphere.c.i

src/sphere.s: src/sphere.c.s
.PHONY : src/sphere.s

# target to generate assembly for a file
src/sphere.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/sphere.c.s
.PHONY : src/sphere.c.s

src/vec3.o: src/vec3.c.o
.PHONY : src/vec3.o

# target to build an object file
src/vec3.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vec3.c.o
.PHONY : src/vec3.c.o

src/vec3.i: src/vec3.c.i
.PHONY : src/vec3.i

# target to preprocess a source file
src/vec3.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vec3.c.i
.PHONY : src/vec3.c.i

src/vec3.s: src/vec3.c.s
.PHONY : src/vec3.s

# target to generate assembly for a file
src/vec3.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vec3.c.s
.PHONY : src/vec3.c.s

src/vector.o: src/vector.c.o
.PHONY : src/vector.o

# target to build an object file
src/vector.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vector.c.o
.PHONY : src/vector.c.o

src/vector.i: src/vector.c.i
.PHONY : src/vector.i

# target to preprocess a source file
src/vector.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vector.c.i
.PHONY : src/vector.c.i

src/vector.s: src/vector.c.s
.PHONY : src/vector.s

# target to generate assembly for a file
src/vector.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/vector.c.s
.PHONY : src/vector.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/hitrecord.o"
	@echo "... src/hitrecord.i"
	@echo "... src/hitrecord.s"
	@echo "... src/hittables_list.o"
	@echo "... src/hittables_list.i"
	@echo "... src/hittables_list.s"
	@echo "... src/ray.o"
	@echo "... src/ray.i"
	@echo "... src/ray.s"
	@echo "... src/sphere.o"
	@echo "... src/sphere.i"
	@echo "... src/sphere.s"
	@echo "... src/vec3.o"
	@echo "... src/vec3.i"
	@echo "... src/vec3.s"
	@echo "... src/vector.o"
	@echo "... src/vector.i"
	@echo "... src/vector.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

