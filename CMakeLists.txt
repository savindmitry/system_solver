cmake_minimum_required(VERSION 3.21)
project(system_solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(system_solver main.cpp solver.h solver.cpp)
