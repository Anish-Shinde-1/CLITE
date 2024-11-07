# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TextEditor VERSION 1.0)

# Enable all warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# Specify include directories for dependencies (e.g., ncurses)
include_directories(
    ${CMAKE_SOURCE_DIR}/dependencies/include
)

# Specify library directories for dependencies (e.g., ncurses)
link_directories(
    ${CMAKE_SOURCE_DIR}/dependencies/lib
)

# Use GLOB to automatically include all source and header files in the src/ directory
file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "src/*.h")

# Add the executable
add_executable(text_editor ${SOURCES} ${HEADERS})

# Link the ncurses library (both static and shared)
target_link_libraries(text_editor ncurses)
