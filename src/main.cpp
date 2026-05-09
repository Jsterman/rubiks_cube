#include <iostream>
#include <RubiksCube.h>

int main() {
    RubiksCube cube;
    cube.setCurrentFace(green);
    cube.executeSequence("B2 R2");
    std::cout << cube.toString() << std::endl;
    return 0;
}