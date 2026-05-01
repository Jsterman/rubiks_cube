#include <RubiksCube.h>


void RubiksCube::setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color) {
    faces[side*6+row*3+clm] = color;
}

FaceColor RubiksCube::getColor(const FaceColor& side, const int& row, const int& clm) const {
    return faces[side*6+row*3+clm];
}

RubiksCube::RubiksCube()
{
    for (FaceColor s: iter_faces) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                setColor(s, j, k, s);
            }
        }
    }
}

FaceColor **RubiksCube::getSide(const FaceColor side)
{
    FaceColor** colors = new FaceColor*[3];
    for (int i = 0; i < 3; i++) {
        colors[i] = new FaceColor[3];
        for (int j = 0; j < 3; j++) {
            colors[i][j] = getColor(side, i, j);
        }
    }
}