cmake_minimum_required(VERSION 3.23)

project(rubiks_cube)
add_executable(rubiks_cube)
target_sources(rubiks_cube
    PRIVATE
    main.cpp
)

add_library(RubiksCube)

target_sources(RubiksCube
    PRIVATE
        RubiksCube.cpp
        FaceColor.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            RubiksCube.h
            FaceColor.h
)

target_link_libraries(rubiks_cube
    PRIVATE
        RubiksCube
)