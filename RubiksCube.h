#pragma once
#include <FaceColor.h>

class RubiksCube {
private:
    FaceColor faces[56];
    void setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color);
public:
    RubiksCube();
    FaceColor** getSide(const FaceColor side);
    FaceColor getColor(const FaceColor& side, const int& row, const int& clm) const;
};