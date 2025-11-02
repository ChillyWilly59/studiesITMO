cmake_minimum_required(VERSION 4.0)
project(exercise_15)

set(CMAKE_CXX_STANDARD 20)

add_executable(exercise_15 main.cpp
        person.h
        address_book.h
        person_factory.h
        ui_interface.h
        person.cpp
        address_book.cpp
        person_factory.cpp
        ui_interface.cpp)
