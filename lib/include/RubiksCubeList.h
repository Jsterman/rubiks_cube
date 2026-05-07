#pragma once
#include <RubiksCubeInterface.h>
#include <string>

class RubiksCubeList : public RubiksCubeInterface {
private:
    FaceColor currentSide = white;
    FaceColor faces[56];
    void setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color);
    void turnRedFaceCW();
    void turnRedFaceCCW();
public:
    RubiksCubeList();
    FaceColor** getSide(const FaceColor side);
    FaceColor getColor(const FaceColor& side, const int& row, const int& clm) const;
    std::string toString();

    void setCurrentFace(const FaceColor&);
    void turnRightFaceCW();
    void turnRightFaceCCW();
    void turnLeftFaceCW();
    void turnLeftFaceCCW();
    void turnUpFaceCW();
    void turnUpFaceCCW();
    void turnDownFaceCW();
    void turnDownFaceCCW();
    void turnFrontFaceCW();
    void turnFrontFaceCCW();
    void turnBackFaceCW();
    void turnBackFaceCCW();

    FaceColor getLeftFace();
    FaceColor getRightFace();
    FaceColor getUpFace();
    FaceColor getDownFace();
    FaceColor getBackFace();
};