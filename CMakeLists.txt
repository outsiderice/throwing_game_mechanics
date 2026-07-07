cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(game)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(CMAKE_CXX_STANDARD 20)
set(RAYLIB_VERSION 5.5) # on old version until all my workspaces update cmake
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()

# Our Project

# Tell Cmake where to find header files
include_directories(inc)

# Collects all source files from src directory
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)
