cmake_minimum_required(VERSION 3.10)
project(MySFMLProject)
set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(tetris ${SOURCES})

target_link_libraries(tetris sfml-system sfml-window sfml-graphics)