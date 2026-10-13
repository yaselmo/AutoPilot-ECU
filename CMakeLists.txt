cmake_minimum_required(VERSION 3.16)

project(AutoPilotECU VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autopilot
    src/main.cpp
)

target_include_directories(autopilot PRIVATE include)

target_compile_options(autopilot PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
