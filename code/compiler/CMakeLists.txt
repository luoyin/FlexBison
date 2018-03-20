cmake_minimum_required(VERSION 2.6)
project(compiler)

add_executable(compiler main.cpp)

install(TARGETS compiler RUNTIME DESTINATION bin)

add_subdirectory(armas)