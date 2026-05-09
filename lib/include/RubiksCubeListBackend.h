#pragma once
#include <RubiksCubeBackendInterface.h>
#include <string>

class RubiksCubeListBackend : public RubiksCubeBackendInterface {
private:
    FaceColor currentSide = white;
    FaceColor faces[56];
    void setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color);
    void turnFacePiecesCW(const FaceColor& side);
    void turnFacePiecesCCW(const FaceColor& side);
    void turnRedFaceCW();
    void turnRedFaceCCW();
    void turnBlueFaceCW();
    void turnBlueFaceCCW();
    void turnWhiteFaceCW();
    void turnWhiteFaceCCW();
    void turnOrangeFaceCW();
    void turnOrangeFaceCCW();
    void turnGreenFaceCW();
    void turnGreenFaceCCW();
    void turnYellowFaceCW();
    void turnYellowFaceCCW();
    void turnFace(const FaceColor& side, bool turnCW);
public:
    RubiksCubeListBackend();
    FaceColor** getSide(const FaceColor &side);
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