cmake_minimum_required(VERSION 3.15)
project(exercise_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

find_package(fmt CONFIG REQUIRED)

add_executable(exercise_1 main.cpp)

target_link_libraries(exercise_1 PRIVATE fmt::fmt)
