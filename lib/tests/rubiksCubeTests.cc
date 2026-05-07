#include <gtest/gtest.h>
#include <RubiksCubeList.h>

// Test that getting the face to the left of the current face returns the proper face
TEST(RubiksCubeListTests, GetLeftSideTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(white);
    EXPECT_EQ(cube.getLeftFace(), blue);
    cube.setCurrentFace(red);
    EXPECT_EQ(cube.getLeftFace(), blue);
    cube.setCurrentFace(blue);
    EXPECT_EQ(cube.getLeftFace(), orange);
    cube.setCurrentFace(orange);
    EXPECT_EQ(cube.getLeftFace(), green);
    cube.setCurrentFace(green);
    EXPECT_EQ(cube.getLeftFace(), red);
    cube.setCurrentFace(yellow);
    EXPECT_EQ(cube.getLeftFace(), blue);
}

TEST(RubiksCubeListTests, GetRightSideTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(white);
    EXPECT_EQ(cube.getRightFace(), green);
    cube.setCurrentFace(red);
    EXPECT_EQ(cube.getRightFace(), green);
    cube.setCurrentFace(green);
    EXPECT_EQ(cube.getRightFace(), orange);
    cube.setCurrentFace(orange);
    EXPECT_EQ(cube.getRightFace(), blue);
    cube.setCurrentFace(blue);
    EXPECT_EQ(cube.getRightFace(), red);
    cube.setCurrentFace(yellow);
    EXPECT_EQ(cube.getRightFace(), green);
}

TEST(RubiksCubeListTests, GetUpSideTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(white);
    EXPECT_EQ(cube.getUpFace(), red);
    cube.setCurrentFace(red);
    EXPECT_EQ(cube.getUpFace(), yellow);
    cube.setCurrentFace(blue);
    EXPECT_EQ(cube.getUpFace(), yellow);
    cube.setCurrentFace(orange);
    EXPECT_EQ(cube.getUpFace(), yellow);
    cube.setCurrentFace(green);
    EXPECT_EQ(cube.getUpFace(), yellow);
    cube.setCurrentFace(yellow);
    EXPECT_EQ(cube.getUpFace(), orange);
}

TEST(RubiksCubeListTests, GetDownSideTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(white);
    EXPECT_EQ(cube.getDownFace(), orange);
    cube.setCurrentFace(red);
    EXPECT_EQ(cube.getDownFace(), white);
    cube.setCurrentFace(blue);
    EXPECT_EQ(cube.getDownFace(), white);
    cube.setCurrentFace(orange);
    EXPECT_EQ(cube.getDownFace(), white);
    cube.setCurrentFace(green);
    EXPECT_EQ(cube.getDownFace(), white);
    cube.setCurrentFace(yellow);
    EXPECT_EQ(cube.getDownFace(), red);
}

TEST(RubiksCubeListTests, GetBackSideTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(white);
    EXPECT_EQ(cube.getBackFace(), yellow);
    cube.setCurrentFace(red);
    EXPECT_EQ(cube.getBackFace(), orange);
    cube.setCurrentFace(blue);
    EXPECT_EQ(cube.getBackFace(), green);
    cube.setCurrentFace(orange);
    EXPECT_EQ(cube.getBackFace(), red);
    cube.setCurrentFace(green);
    EXPECT_EQ(cube.getBackFace(), blue);
    cube.setCurrentFace(yellow);
    EXPECT_EQ(cube.getBackFace(), white);
}

TEST(RubiksCubeListTests, RotateLeftCWTest) {
    RubiksCubeList cube;
    cube.setCurrentFace(blue);
    cube.turnLeftFaceCW();
    std::string str = "W W O\
W W O\
W W O\
\
R R W\
R R W\
R R W\

Y Y R\
Y Y R\
Y Y R\
\
";

}