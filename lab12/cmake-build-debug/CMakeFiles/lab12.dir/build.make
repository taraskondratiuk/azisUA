# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\1PROGA\sharaga\azisUA\lab12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab12.dir/flags.make

CMakeFiles/lab12.dir/main.c.obj: CMakeFiles/lab12.dir/flags.make
CMakeFiles/lab12.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab12.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab12.dir\main.c.obj   -c F:\1PROGA\sharaga\azisUA\lab12\main.c

CMakeFiles/lab12.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab12.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\1PROGA\sharaga\azisUA\lab12\main.c > CMakeFiles\lab12.dir\main.c.i

CMakeFiles/lab12.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab12.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\1PROGA\sharaga\azisUA\lab12\main.c -o CMakeFiles\lab12.dir\main.c.s

# Object files for target lab12
lab12_OBJECTS = \
"CMakeFiles/lab12.dir/main.c.obj"

# External object files for target lab12
lab12_EXTERNAL_OBJECTS =

lab12.exe: CMakeFiles/lab12.dir/main.c.obj
lab12.exe: CMakeFiles/lab12.dir/build.make
lab12.exe: CMakeFiles/lab12.dir/linklibs.rsp
lab12.exe: CMakeFiles/lab12.dir/objects1.rsp
lab12.exe: CMakeFiles/lab12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab12.dir/build: lab12.exe

.PHONY : CMakeFiles/lab12.dir/build

CMakeFiles/lab12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab12.dir/clean

CMakeFiles/lab12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\1PROGA\sharaga\azisUA\lab12 F:\1PROGA\sharaga\azisUA\lab12 F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug F:\1PROGA\sharaga\azisUA\lab12\cmake-build-debug\CMakeFiles\lab12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab12.dir/depend

