#include <iostream>
#include <RubiksCube.h>

int main() {
    RubiksCube cube;
    for (FaceColor sideColor : iter_faces) {
        FaceColor** side = cube.getSide(sideColor);
        std::cout << "Side " << to_string(sideColor) << ":" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << to_string(side[i][j]) << " ";
            }
            std::cout << std::endl;
            delete[] side[i];
        }
        std::cout << std::endl;
        delete[] side;
    }
    return 0;
}