#include <FaceColor.h>

class RubiksCube {
private:
    FaceColor faces[56];
    void setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color);
    FaceColor getColor(const FaceColor& side, const int& row, const int& clm) const;
public:
    RubiksCube();
    FaceColor** getSide(const FaceColor side);
};