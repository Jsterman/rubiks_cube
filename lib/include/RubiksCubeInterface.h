#pragma once
#include <FaceColor.h>
#include <string>

class RubiksCubeInterface {
protected:
    virtual void setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color) = 0;

public:
    virtual FaceColor** getSide(const FaceColor& side) = 0;
    virtual FaceColor getColor(const FaceColor& side, const int& row, const int& clm) const = 0;
    virtual std::string toString() = 0;

    virtual void setCurrentFace(const FaceColor&) = 0;
    virtual void turnRightFaceCW() = 0;
    virtual void turnRightFaceCCW() = 0;
    virtual void turnLeftFaceCW() = 0;
    virtual void turnLeftFaceCCW() = 0;
    virtual void turnUpFaceCW() = 0;
    virtual void turnUpFaceCCW() = 0;
    virtual void turnDownFaceCW() = 0;
    virtual void turnDownFaceCCW() = 0;
    virtual void turnFrontFaceCW() = 0;
    virtual void turnFrontFaceCCW() = 0;
    virtual void turnBackFaceCW() = 0;
    virtual void turnBackFaceCCW() = 0;
};