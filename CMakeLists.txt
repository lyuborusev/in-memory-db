cmake_minimum_required(VERSION 3.16.3)

project(in-memory-db VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB APP_SOURCES
    "*.h"
    "*.cpp"
    "base_implementation/*.h"
    "base_implementation/*.cpp"
)
add_executable ( main ${APP_SOURCES})