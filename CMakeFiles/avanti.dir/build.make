# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti"

# Include any dependencies generated for this target.
include CMakeFiles/avanti.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/avanti.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/avanti.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avanti.dir/flags.make

CMakeFiles/avanti.dir/src/main.c.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/src/main.c.o: src/main.c
CMakeFiles/avanti.dir/src/main.c.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/avanti.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/avanti.dir/src/main.c.o -MF CMakeFiles/avanti.dir/src/main.c.o.d -o CMakeFiles/avanti.dir/src/main.c.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/main.c"

CMakeFiles/avanti.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/avanti.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/main.c" > CMakeFiles/avanti.dir/src/main.c.i

CMakeFiles/avanti.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/avanti.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/main.c" -o CMakeFiles/avanti.dir/src/main.c.s

CMakeFiles/avanti.dir/src/menu.c.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/src/menu.c.o: src/menu.c
CMakeFiles/avanti.dir/src/menu.c.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/avanti.dir/src/menu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/avanti.dir/src/menu.c.o -MF CMakeFiles/avanti.dir/src/menu.c.o.d -o CMakeFiles/avanti.dir/src/menu.c.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/menu.c"

CMakeFiles/avanti.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/avanti.dir/src/menu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/menu.c" > CMakeFiles/avanti.dir/src/menu.c.i

CMakeFiles/avanti.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/avanti.dir/src/menu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/menu.c" -o CMakeFiles/avanti.dir/src/menu.c.s

CMakeFiles/avanti.dir/src/gui.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/src/gui.cpp.o: src/gui.cpp
CMakeFiles/avanti.dir/src/gui.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/avanti.dir/src/gui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/src/gui.cpp.o -MF CMakeFiles/avanti.dir/src/gui.cpp.o.d -o CMakeFiles/avanti.dir/src/gui.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/gui.cpp"

CMakeFiles/avanti.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/src/gui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/gui.cpp" > CMakeFiles/avanti.dir/src/gui.cpp.i

CMakeFiles/avanti.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/src/gui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/src/gui.cpp" -o CMakeFiles/avanti.dir/src/gui.cpp.s

CMakeFiles/avanti.dir/imgui/imgui.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/imgui/imgui.cpp.o: imgui/imgui.cpp
CMakeFiles/avanti.dir/imgui/imgui.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/avanti.dir/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/imgui/imgui.cpp.o -MF CMakeFiles/avanti.dir/imgui/imgui.cpp.o.d -o CMakeFiles/avanti.dir/imgui/imgui.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui.cpp"

CMakeFiles/avanti.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui.cpp" > CMakeFiles/avanti.dir/imgui/imgui.cpp.i

CMakeFiles/avanti.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui.cpp" -o CMakeFiles/avanti.dir/imgui/imgui.cpp.s

CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o: imgui/imgui_draw.cpp
CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_draw.cpp"

CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_draw.cpp" > CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.i

CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_draw.cpp" -o CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.s

CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o: imgui/imgui_widgets.cpp
CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_widgets.cpp"

CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_widgets.cpp" > CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/imgui_widgets.cpp" -o CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: imgui/misc/cpp/imgui_stdlib.cpp
CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o -MF CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o.d -o CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/misc/cpp/imgui_stdlib.cpp"

CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/misc/cpp/imgui_stdlib.cpp" > CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.i

CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/imgui/misc/cpp/imgui_stdlib.cpp" -o CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.s

CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o: ImgWindow/ImgFontAtlas.cpp
CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o -MF CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o.d -o CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgFontAtlas.cpp"

CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgFontAtlas.cpp" > CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.i

CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgFontAtlas.cpp" -o CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.s

CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o: CMakeFiles/avanti.dir/flags.make
CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o: ImgWindow/ImgWindow.cpp
CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o: CMakeFiles/avanti.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o -MF CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o.d -o CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o -c "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgWindow.cpp"

CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgWindow.cpp" > CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.i

CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/ImgWindow/ImgWindow.cpp" -o CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.s

# Object files for target avanti
avanti_OBJECTS = \
"CMakeFiles/avanti.dir/src/main.c.o" \
"CMakeFiles/avanti.dir/src/menu.c.o" \
"CMakeFiles/avanti.dir/src/gui.cpp.o" \
"CMakeFiles/avanti.dir/imgui/imgui.cpp.o" \
"CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o" \
"CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o" \
"CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o"

# External object files for target avanti
avanti_EXTERNAL_OBJECTS =

lin_x64/avanti.xpl: CMakeFiles/avanti.dir/src/main.c.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/src/menu.c.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/src/gui.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/imgui/imgui.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/imgui/imgui_draw.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/imgui/imgui_widgets.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/imgui/misc/cpp/imgui_stdlib.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/ImgWindow/ImgFontAtlas.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/ImgWindow/ImgWindow.cpp.o
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/build.make
lin_x64/avanti.xpl: libacfutils/lin64/lib/libGLEWmx.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libacfutils.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libcairo.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libcharset.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libcrypto.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libcurl.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libfreetype.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libiconv.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/liblzma.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libogg.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libopus.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libopusfile.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libopusurl.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libpcre2-8.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libpixman-1.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libpng16.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libproj.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libshp.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libssl.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libxml2.a
lin_x64/avanti.xpl: libacfutils/lin64/lib/libz.a
lin_x64/avanti.xpl: /usr/lib/x86_64-linux-gnu/libOpenGL.so
lin_x64/avanti.xpl: /usr/lib/x86_64-linux-gnu/libGLX.so
lin_x64/avanti.xpl: /usr/lib/x86_64-linux-gnu/libGLU.so
lin_x64/avanti.xpl: CMakeFiles/avanti.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library lin_x64/avanti.xpl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avanti.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avanti.dir/build: lin_x64/avanti.xpl
.PHONY : CMakeFiles/avanti.dir/build

CMakeFiles/avanti.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avanti.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avanti.dir/clean

CMakeFiles/avanti.dir/depend:
	cd "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/CMakeFiles/avanti.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/avanti.dir/depend

