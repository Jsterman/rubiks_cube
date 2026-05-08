#include <iostream>
#include <RubiksCubeList.h>

int main() {
    RubiksCubeList cube;
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
    std::cout << cube.toString();
    return 0;
}