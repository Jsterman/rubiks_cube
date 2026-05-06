cmake_minimum_required(VERSION 3.23)

project(rubiks_cube)
add_executable(rubiks_cube)
target_sources(rubiks_cube
    PRIVATE
    src/main.cpp
)

target_link_libraries(rubiks_cube
    PRIVATE
        RubiksCube
)

add_subdirectory(lib)