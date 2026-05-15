#include <gtest/gtest.h>
#include <RubiksCube.h>

TEST(RubiksCubeListTests, TestOrangeRotate) {
    RubiksCube cube = RubiksCube(LIST);

    cube.setCurrentFace(green);
    cube.turnBackFaceCW();
    cube.turnRightFaceCW();

    EXPECT_EQ(cube.toString(), "R W W\nR W W\nB B B\n\nY R R\nY R R\nY R R\n\nY B B\nY B B\nO B B\n\nO O O\nO O O\nW W W\n\nG G W\nG G W\nG G R\n\nG G G\nO Y Y\nO Y Y");
}

TEST(RubiksCubeListTests, SwapAndBack) {
    RubiksCube cube = RubiksCube(LIST);

    cube.setCurrentFace(blue);
    cube.turnRightFaceCCW();
    cube.turnRightFaceCCW();
    cube.turnLeftFaceCCW();
    cube.turnLeftFaceCCW();
    cube.turnUpFaceCCW();
    cube.turnUpFaceCCW();
    cube.turnDownFaceCCW();
    cube.turnDownFaceCCW();
    cube.turnFrontFaceCCW();
    cube.turnFrontFaceCCW();
    cube.turnBackFaceCCW();
    cube.turnBackFaceCCW();

    EXPECT_EQ(cube.toString(), "W Y W\nY W Y\nW Y W\n\nR O R\nO R O\nR O R\n\nB G B\nG B G\nB G B\n\nO R O\nR O R\nO R O\n\nG B G\nB G B\nG B G\n\nY W Y\nW Y W\nY W Y");

    cube.turnRightFaceCW();
    cube.turnRightFaceCW();
    cube.turnLeftFaceCW();
    cube.turnLeftFaceCW();
    cube.turnFrontFaceCW();
    cube.turnFrontFaceCW();
    cube.turnBackFaceCW();
    cube.turnBackFaceCW();
    cube.turnUpFaceCW();
    cube.turnUpFaceCW();
    cube.turnDownFaceCW();
    cube.turnDownFaceCW();

    EXPECT_EQ(cube.toString(), "W W W\nW W W\nW W W\n\nR R R\nR R R\nR R R\n\nB B B\nB B B\nB B B\n\nO O O\nO O O\nO O O\n\nG G G\nG G G\nG G G\n\nY Y Y\nY Y Y\nY Y Y");
}

TEST(RubiksCubeListTests, ExecuteScrambleSequence) {
    RubiksCube cube = RubiksCube(LIST);
    cube.setOrientation(green, white);
    
    cube.executeSequence("B2 R2 B' U2 F' R2 B' R2 U2 F2 L2 U2 L B' L B2 D L' D2 U' L");
    //                            white side            red side                blue side               orange side         green side              yellow side
    EXPECT_EQ(cube.toString(), "W O B\nY W G\nR G R\n\nY O Y\nR R R\nG B W\n\nW R G\nW B G\nY O R\n\nY W G\nB O B\nB Y B\n\nO R O\nB G Y\nO W W\n\nO O G\nY Y W\nR G B");

    RubiksCube cube2 = RubiksCube(LIST);
    cube2.setOrientation(green, white);

    cube2.executeSequence("D L D2 B' D2 B2 U2 F' L2 F2 D2 R2 D2 L' U' B2 D' B2 D R'");

    EXPECT_EQ(cube2.toString(), "Y B O\nR W B\nG W B\n\nR Y W\nG R W\nR W B\n\nY R B\nG B Y\nW Y G\n\nB Y O\nO O O\nW G O\n\nG G O\nO G B\nW R R\n\nG B Y\nW Y R\nY O R");


}