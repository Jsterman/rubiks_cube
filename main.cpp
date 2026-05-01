#include <iostream>
#include <RubiksCube.h>

int main() {
    RubiksCube cube;

    FaceColor** side = cube.getSide(white);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << to_string(side[i][j]) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}