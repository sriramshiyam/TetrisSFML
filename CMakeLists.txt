cmake_minimum_required(VERSION 3.10)
project(MySFMLProject)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Set source files
# Add the executable
add_executable(tetris)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

target_include_directories(tetris PRIVATE include)
target_sources(tetris PRIVATE ${SOURCE_FILES})
# Include SFML headers
target_include_directories(tetris PRIVATE ${SFML_INCLUDE_DIRS})

target_link_libraries(tetris PRIVATE sfml-system sfml-window sfml-graphics)