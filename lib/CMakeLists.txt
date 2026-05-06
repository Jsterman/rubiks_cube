add_library(RubiksCube)

target_sources(RubiksCube
    PRIVATE
        src/RubiksCubeList.cpp
        src/FaceColor.cpp
        src/RubiksCubePhy.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/RubiksCubeList.h
            include/RubiksCubePhy.h
            include/RubiksCubeInterface.h
            include/FaceColor.h
)

# Include items for Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add the executable with the tests
add_executable(rubiksCubeTests
  tests/rubiksCubeTests.cc
)

# Link the Google Test library to the tests executable
target_link_libraries(rubiksCubeTests
  GTest::gtest_main
  RubiksCube
)

include(GoogleTest)
gtest_discover_tests(rubiksCubeTests)
