cmake_minimum_required(VERSION 3.20)
project(avanti VERSION 3.0.0 LANGUAGES C CXX)

# include(cmake/xplm.cmake)

add_definitions(-DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1 -DXPLM302=1 -DXPLM303=1 -DXPLM400=1)

if (APPLE)

elseif (WIN32)

else ()
  set(ARCH "lin64")
  add_definitions(-DAPL=0 -DIBM=0 -DLIN=1)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused -Wall -Wno-missing-field-initializsers -Wshadow -Wextra -Wno-error")
endif ()

# acfutils
option(LIBACFUTILS "${CMAKE_SOUCE_DIR}")

file(GLOB LIBACFUTILS_LIBS libacfutils/${ARCH}/lib/*.a)
if (WIN32)
  list(APPEND LIBACFUTILS_LIBS crypt32 ws2_32 gdi32 dbhelp psapi winmm)
else ()
  list(APPEND LIBACFUTILS_LIBS pthread)
endif ()


# X-Plane SDK
set(SDK_ROOT "${CMAKE_SOUCE_DIR}/SDK")

include_directories(
        "SDK/CHeaders/Widgets"
        "SDK/CHeaders/Wrappers"
        "SDK/CHeaders/XPLM"
        "libacfutils/include/"
        "libacfutils/${ARCH}/include/"
        "includes/"
)


find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

# use_static_libc()

add_library(avanti SHARED 
          #SRC FILES
          src/main.cpp    src/main.h
          src/globals.cpp src/globals.h
          src/menu.cpp    src/menu.h
          src/gui.cpp     src/gui.h
          src/image_loader.cpp src/image_loader.h
          #src/gui_debug.cpp src/gui_debug.h

          #IMGUI FILES
          imgui/imgui.cpp
          imgui/imgui_draw.cpp
          imgui/imgui_widgets.cpp
          imgui/misc/cpp/imgui_stdlib.cpp
          ImgWindow/ImgFontAtlas.cpp
          ImgWindow/ImgWindow.cpp

)

target_compile_features(avanti PUBLIC c_std_11 cxx_std_17)
target_compile_options(avanti PUBLIC -Wall -Wextra)
target_link_libraries(avanti PUBLIC ${LIBACFUTILS_LIBS} ${OPENGL_LIBRARIES})
target_include_directories(avanti PRIVATE "lib")

set_target_properties(avanti PROPERTIES LINK_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fno-stack-protector -fPIC -fvisibility=hidden -Wno-unused")

add_compile_options(-fexceptions)
add_compile_options(-fvisibility=hidden)
add_compile_options(-Wall -Wpedantic -Wshadow -Wfloat-equal -Wextra)
add_compile_options(-Wno-unused)

set(PLUGIN_BUILD_DIR "${CMAKE_SOURCE_DIR}")

set_target_properties(avanti PROPERTIES PREFIX "")
set_target_properties(avanti PROPERTIES SUFFIX "")
set_target_properties(avanti PROPERTIES SUFFIX ".xpl")
set_target_properties(avanti PROPERTIES OUTPUT_NAME "avanti")

if(WIN32)

elseif(APPLE)

elseif(UNIX)
set_target_properties(avanti PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PLUGIN_BUILD_DIR}/lin_x64")
set_target_properties(avanti PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PLUGIN_BUILD_DIR}/lin_x64")
endif()
