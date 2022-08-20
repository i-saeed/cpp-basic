cmake_minimum_required(VERSION 3.12)

project(cpp-basic VERSION 0.1 DESCRIPTION "Solving Data Structures and Algos" LANGUAGES CXX)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wpedantic -Wextra)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

add_subdirectory(src)
add_subdirectory(examples)
