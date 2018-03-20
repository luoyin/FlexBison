cmake_minimum_required(VERSION 2.6)
project(book)

add_executable(book main.cpp)

install(TARGETS book RUNTIME DESTINATION bin)

add_subdirectory(chapter1)
add_subdirectory(chapter3)