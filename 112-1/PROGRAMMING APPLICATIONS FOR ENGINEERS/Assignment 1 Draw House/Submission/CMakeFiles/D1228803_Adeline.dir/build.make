# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission"

# Include any dependencies generated for this target.
include CMakeFiles/D1228803_Adeline.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/D1228803_Adeline.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/D1228803_Adeline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D1228803_Adeline.dir/flags.make

CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj: CMakeFiles/D1228803_Adeline.dir/flags.make
CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj: D1228803_Adeline/assgn1_D1228803.c
CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj: CMakeFiles/D1228803_Adeline.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj -MF CMakeFiles\D1228803_Adeline.dir\D1228803_Adeline\assgn1_D1228803.c.obj.d -o CMakeFiles\D1228803_Adeline.dir\D1228803_Adeline\assgn1_D1228803.c.obj -c "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\D1228803_Adeline\assgn1_D1228803.c"

CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\D1228803_Adeline\assgn1_D1228803.c" > CMakeFiles\D1228803_Adeline.dir\D1228803_Adeline\assgn1_D1228803.c.i

CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\D1228803_Adeline\assgn1_D1228803.c" -o CMakeFiles\D1228803_Adeline.dir\D1228803_Adeline\assgn1_D1228803.c.s

# Object files for target D1228803_Adeline
D1228803_Adeline_OBJECTS = \
"CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj"

# External object files for target D1228803_Adeline
D1228803_Adeline_EXTERNAL_OBJECTS =

D1228803_Adeline/D1228803_Adeline.exe: CMakeFiles/D1228803_Adeline.dir/D1228803_Adeline/assgn1_D1228803.c.obj
D1228803_Adeline/D1228803_Adeline.exe: CMakeFiles/D1228803_Adeline.dir/build.make
D1228803_Adeline/D1228803_Adeline.exe: CMakeFiles/D1228803_Adeline.dir/linklibs.rsp
D1228803_Adeline/D1228803_Adeline.exe: CMakeFiles/D1228803_Adeline.dir/objects1.rsp
D1228803_Adeline/D1228803_Adeline.exe: CMakeFiles/D1228803_Adeline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable D1228803_Adeline\D1228803_Adeline.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\D1228803_Adeline.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D1228803_Adeline.dir/build: D1228803_Adeline/D1228803_Adeline.exe
.PHONY : CMakeFiles/D1228803_Adeline.dir/build

CMakeFiles/D1228803_Adeline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D1228803_Adeline.dir\cmake_clean.cmake
.PHONY : CMakeFiles/D1228803_Adeline.dir/clean

CMakeFiles/D1228803_Adeline.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission" "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission" "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission" "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission" "D:\GitHub\FCU\112-1\PROGRAMMING APPLICATIONS FOR ENGINEERS\Assignment 1 Draw House\Submission\CMakeFiles\D1228803_Adeline.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/D1228803_Adeline.dir/depend

