#pragma once
#include <string>
#include <FaceColor.h>
#include <RubiksCubeBackendFactory.h>

class RubiksCube {
protected:
    std::unique_ptr<RubiksCubeBackendInterface> backend;
public:
    RubiksCube(const BackendType &type=LIST);
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

    void executeSequence(std::string);
    void setOrientation(const FaceColor& front, const FaceColor &top);
};