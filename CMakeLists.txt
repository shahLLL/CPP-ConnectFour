cmake_minimum_required(VERSION 3.12)
project(shapes LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect main.cpp and all C++ files in the src/ directory
file(GLOB SOURCES "main.cpp" "src/*.cpp")

# Define the executable target
add_executable(connect4 ${SOURCES})

# Apply compiler warning flags
target_compile_options(connect4 PRIVATE -Wall -Wextra)