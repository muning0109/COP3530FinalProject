cmake_minimum_required(VERSION 3.17)
project(COP3530FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SFML_Process.cpp SFML_Process.h)
add_executable(COP3530FinalProject ${SOURCE_FILES})
include_directories(src/SFML-2.5.1/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(COP3530FinalProject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)