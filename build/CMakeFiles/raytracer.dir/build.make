# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /nfs/encs/ArchDep/x86_64.EL7/pkg/cmake-3.26.4/root/bin/cmake

# The command to remove a file.
RM = /nfs/encs/ArchDep/x86_64.EL7/pkg/cmake-3.26.4/root/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raytracer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/main.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/main.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/main.cpp
CMakeFiles/raytracer.dir/main.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/main.cpp.o -MF CMakeFiles/raytracer.dir/main.cpp.o.d -o CMakeFiles/raytracer.dir/main.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/main.cpp

CMakeFiles/raytracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/main.cpp > CMakeFiles/raytracer.dir/main.cpp.i

CMakeFiles/raytracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/main.cpp -o CMakeFiles/raytracer.dir/main.cpp.s

CMakeFiles/raytracer.dir/external/simpleppm.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/external/simpleppm.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/simpleppm.cpp
CMakeFiles/raytracer.dir/external/simpleppm.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/external/simpleppm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/external/simpleppm.cpp.o -MF CMakeFiles/raytracer.dir/external/simpleppm.cpp.o.d -o CMakeFiles/raytracer.dir/external/simpleppm.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/simpleppm.cpp

CMakeFiles/raytracer.dir/external/simpleppm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/external/simpleppm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/simpleppm.cpp > CMakeFiles/raytracer.dir/external/simpleppm.cpp.i

CMakeFiles/raytracer.dir/external/simpleppm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/external/simpleppm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/simpleppm.cpp -o CMakeFiles/raytracer.dir/external/simpleppm.cpp.s

CMakeFiles/raytracer.dir/external/test_eigen.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/external/test_eigen.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_eigen.cpp
CMakeFiles/raytracer.dir/external/test_eigen.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raytracer.dir/external/test_eigen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/external/test_eigen.cpp.o -MF CMakeFiles/raytracer.dir/external/test_eigen.cpp.o.d -o CMakeFiles/raytracer.dir/external/test_eigen.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_eigen.cpp

CMakeFiles/raytracer.dir/external/test_eigen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/external/test_eigen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_eigen.cpp > CMakeFiles/raytracer.dir/external/test_eigen.cpp.i

CMakeFiles/raytracer.dir/external/test_eigen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/external/test_eigen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_eigen.cpp -o CMakeFiles/raytracer.dir/external/test_eigen.cpp.s

CMakeFiles/raytracer.dir/external/test_json.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/external/test_json.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_json.cpp
CMakeFiles/raytracer.dir/external/test_json.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/raytracer.dir/external/test_json.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/external/test_json.cpp.o -MF CMakeFiles/raytracer.dir/external/test_json.cpp.o.d -o CMakeFiles/raytracer.dir/external/test_json.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_json.cpp

CMakeFiles/raytracer.dir/external/test_json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/external/test_json.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_json.cpp > CMakeFiles/raytracer.dir/external/test_json.cpp.i

CMakeFiles/raytracer.dir/external/test_json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/external/test_json.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_json.cpp -o CMakeFiles/raytracer.dir/external/test_json.cpp.s

CMakeFiles/raytracer.dir/external/test_ppm.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/external/test_ppm.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_ppm.cpp
CMakeFiles/raytracer.dir/external/test_ppm.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/raytracer.dir/external/test_ppm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/external/test_ppm.cpp.o -MF CMakeFiles/raytracer.dir/external/test_ppm.cpp.o.d -o CMakeFiles/raytracer.dir/external/test_ppm.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_ppm.cpp

CMakeFiles/raytracer.dir/external/test_ppm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/external/test_ppm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_ppm.cpp > CMakeFiles/raytracer.dir/external/test_ppm.cpp.i

CMakeFiles/raytracer.dir/external/test_ppm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/external/test_ppm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/external/test_ppm.cpp -o CMakeFiles/raytracer.dir/external/test_ppm.cpp.s

CMakeFiles/raytracer.dir/src/RayTracer.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/RayTracer.cpp.o: /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/src/RayTracer.cpp
CMakeFiles/raytracer.dir/src/RayTracer.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/raytracer.dir/src/RayTracer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/src/RayTracer.cpp.o -MF CMakeFiles/raytracer.dir/src/RayTracer.cpp.o.d -o CMakeFiles/raytracer.dir/src/RayTracer.cpp.o -c /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/src/RayTracer.cpp

CMakeFiles/raytracer.dir/src/RayTracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/RayTracer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/src/RayTracer.cpp > CMakeFiles/raytracer.dir/src/RayTracer.cpp.i

CMakeFiles/raytracer.dir/src/RayTracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/RayTracer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/src/RayTracer.cpp -o CMakeFiles/raytracer.dir/src/RayTracer.cpp.s

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/main.cpp.o" \
"CMakeFiles/raytracer.dir/external/simpleppm.cpp.o" \
"CMakeFiles/raytracer.dir/external/test_eigen.cpp.o" \
"CMakeFiles/raytracer.dir/external/test_json.cpp.o" \
"CMakeFiles/raytracer.dir/external/test_ppm.cpp.o" \
"CMakeFiles/raytracer.dir/src/RayTracer.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/main.cpp.o
raytracer: CMakeFiles/raytracer.dir/external/simpleppm.cpp.o
raytracer: CMakeFiles/raytracer.dir/external/test_eigen.cpp.o
raytracer: CMakeFiles/raytracer.dir/external/test_json.cpp.o
raytracer: CMakeFiles/raytracer.dir/external/test_ppm.cpp.o
raytracer: CMakeFiles/raytracer.dir/src/RayTracer.cpp.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer
.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build /home/s/s_cetini/COMP_371/COMP371_all/COMP371_RaytracerBase/code/build/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracer.dir/depend

