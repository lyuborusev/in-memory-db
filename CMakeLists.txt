cmake_minimum_required(VERSION 3.16.3)

project(in-memory-db VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB APP_SOURCES
    "*.h"
    "*.cpp"
    "test/*.h"
    "test/*.cpp"
    "types/*.h"
    "types/*.cpp"
    "strategies/*.h"
    "strategies/*.cpp"
)
add_executable ( main ${APP_SOURCES})