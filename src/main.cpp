#include <iostream>
#include <RubiksCube.h>

int main() {
    Cube regCube;
    std::cout << "Setting orientation to green front, white top" << std::endl;
    regCube.setOrientation(green, white);
    std::cout << "Color at front: " << to_string(regCube.getFront()) << std::endl;
    std::cout << "Color at top: " << to_string(regCube.getTop()) << std::endl;
    std::cout << "Color at back: " << to_string(regCube.getBack()) << std::endl << std::endl;
    RubiksCube cube;
    cube.setOrientation(green, white);
    cube.executeSequence("B2 R2 B' U2 F' R2 B' R2 U2 F2 L2");// U2 L B' L B2 D L' D2 U' L");
    // cube.setCurrentFace(green);
    // cube.executeSequence("B2 R2");
    std::cout << cube.toString() << std::endl;
    return 0;
}