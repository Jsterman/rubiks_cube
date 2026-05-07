#include <iostream>
#include <RubiksCubeList.h>

int main() {
    RubiksCubeList cube;
    cube.setCurrentFace(blue);
    cube.turnRightFaceCW();
    std::cout << cube.toString();
    return 0;
}