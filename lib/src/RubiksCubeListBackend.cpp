#include <RubiksCubeListBackend.h>
#include <sstream>

void RubiksCubeListBackend::setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color) {
    faces[side*9+row*3+clm] = color;
}

void RubiksCubeListBackend::turnFacePiecesCW(const FaceColor &side)
{
    // Rotate corner pieces

    FaceColor topLeft = getColor(side, 0, 0);
    setColor(side, 0, 0, getColor(side, 2, 0));
    setColor(side, 2, 0, getColor(side, 2, 2));
    setColor(side, 2, 2, getColor(side, 0, 2));
    setColor(side, 0, 2, topLeft);

    // Rotate center pieces
    FaceColor topMiddle = getColor(side, 0, 1);
    setColor(side, 0, 1, getColor(side, 1, 0));
    setColor(side, 1, 0, getColor(side, 2, 1));
    setColor(side, 2, 1, getColor(side, 1, 2));
    setColor(side, 1, 2, topMiddle);
}

void RubiksCubeListBackend::turnFacePiecesCCW(const FaceColor &side)
{
    // Rotate corner pieces
    FaceColor topLeft = getColor(side, 0, 0);
    setColor(side, 0, 0, getColor(side, 0, 2));
    setColor(side, 0, 2, getColor(side, 2, 2));
    setColor(side, 2, 2, getColor(side, 2, 0));
    setColor(side, 2, 0, topLeft);

    // Rotate middle pieces
    FaceColor topMiddle = getColor(side, 0, 1);
    setColor(side, 0, 1, getColor(side, 1, 2));
    setColor(side, 1, 2, getColor(side, 2, 1));
    setColor(side, 2, 1, getColor(side, 1, 0));
    setColor(side, 1, 0, topMiddle);
}

void RubiksCubeListBackend::turnRedFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(blue, i, 2);
        setColor(blue, i, 2, getColor(white, 0, i));
        setColor(white, 0, i, getColor(green, 2-i, 0));
        setColor(green, 2-i, 0, getColor(yellow, 2, 2-i));
        setColor(yellow, 2, 2-i, current);
    }
    turnFacePiecesCW(red);
}

void RubiksCubeListBackend::turnRedFaceCCW() {
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(blue, i, 2);
        setColor(blue, i, 2, getColor(yellow, 2, 2-i));
        setColor(yellow, 2, 2-i, getColor(green, 2-i, 0));
        setColor(green, 2-i, 0, getColor(white, 0, i));
        setColor(white, 0, i, current);
    }
    turnFacePiecesCCW(red);
}

void RubiksCubeListBackend::turnBlueFaceCW() {
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(orange, i, 2);
        setColor(orange, i, 2, getColor(white, 2-i, 0));
        setColor(white, 2-i, 0, getColor(red, 2-i, 0));
        setColor(red, 2-i, 0, getColor(yellow, 2-i, 0));
        setColor(yellow, 2-i, 0, current);
    }
    turnFacePiecesCW(blue);
}

void RubiksCubeListBackend::turnBlueFaceCCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(orange, i, 2);
        setColor(orange, i, 2, getColor(yellow, 2-i, 0));
        setColor(yellow, 2-i, 0, getColor(red, 2-i, 0));
        setColor(red, 2-i, 0, getColor(white, 2-i, 0));
        setColor(white, 2-i, 0, current);
    }
    turnFacePiecesCCW(blue);
}

void RubiksCubeListBackend::turnWhiteFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, 2, i);
        setColor(red, 2, i, getColor(blue, 2, i));
        setColor(blue, 2, i, getColor(orange, 2, i));
        setColor(orange, 2, i, getColor(green, 2, i));
        setColor(green, 2, i, current);
    }
    turnFacePiecesCW(white);
}

void RubiksCubeListBackend::turnWhiteFaceCCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, 2, i);
        setColor(red, 2, i, getColor(green, 2, i));
        setColor(green, 2, i, getColor(orange, 2, i));
        setColor(orange, 2, i, getColor(blue, 2, i));
        setColor(blue, 2, i, current);
    }
    turnFacePiecesCCW(white);
}

void RubiksCubeListBackend::turnOrangeFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(green, i, 2);
        setColor(green, i, 2, getColor(white, 2, 2-i));
        setColor(white, 2, 2-i, getColor(blue, 2-i, 0));
        setColor(blue, 2-i, 0, getColor(yellow, 0, i));
        setColor(yellow, 0, i, current);
    }
    turnFacePiecesCW(orange);
}

void RubiksCubeListBackend::turnOrangeFaceCCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(green, i, 2);
        setColor(green, i, 2, getColor(yellow, 0, i));
        setColor(yellow, 0, i, getColor(blue, 2-i, 0));
        setColor(blue, 2-i, 0, getColor(white, 2, 2-i));
        setColor(white, 2, 2-i, current);
    }
    turnFacePiecesCCW(orange);
}

void RubiksCubeListBackend::turnGreenFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, i, 2);
        setColor(red, i, 2, getColor(white, i, 2));
        setColor(white, i, 2, getColor(orange, 2-i, 0));
        setColor(orange, 2-i, 0, getColor(yellow, i, 2));
        setColor(yellow, i, 2, current);
    }
    turnFacePiecesCW(green);
}

void RubiksCubeListBackend::turnGreenFaceCCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, i, 2);
        setColor(red, i, 2, getColor(yellow, i, 2));
        setColor(yellow, i, 2, getColor(orange, 2-i, 0));
        setColor(orange, 2-i, 0, getColor(white, i, 2));
        setColor(white, i, 2, current);
    }
    turnFacePiecesCCW(green);
}

void RubiksCubeListBackend::turnYellowFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, 0, i);
        setColor(red, 0, i, getColor(green, 0, i));
        setColor(green, 0, i, getColor(orange, 0, i));
        setColor(orange, 0, i, getColor(blue, 0, i));
        setColor(blue, 0, i, current);
    }
    turnFacePiecesCW(yellow);
}

void RubiksCubeListBackend::turnYellowFaceCCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(red, 0, i);
        setColor(red, 0, i, getColor(blue, 0, i));
        setColor(blue, 0, i, getColor(orange, 0, i));
        setColor(orange, 0, i, getColor(green, 0, i));
        setColor(green, 0, i, current);
    }
    turnFacePiecesCCW(yellow);
}

void RubiksCubeListBackend::turnFace(const FaceColor &side, bool turnCW)
{
    if (turnCW) {
        switch (side) {
            case white:
                turnWhiteFaceCW();
                break;
            case red:
                turnRedFaceCW();
                break;
            case blue:
                turnBlueFaceCW();
                break;
            case orange:
                turnOrangeFaceCW();
                break;
            case green:
                turnGreenFaceCW();
                break;
            case yellow:
                turnYellowFaceCW();
                break;
        }
    }
    else {
        switch (side) {
            case white:
                turnWhiteFaceCCW();
                break;
            case red:
                turnRedFaceCCW();
                break;
            case blue:
                turnBlueFaceCCW();
                break;
            case orange:
                turnOrangeFaceCCW();
                break;
            case green:
                turnGreenFaceCCW();
                break;
            case yellow:
                turnYellowFaceCCW();
                break;
        }
    }
}

FaceColor RubiksCubeListBackend::getLeftFace()
{
    return cube.getLeft();
}

FaceColor RubiksCubeListBackend::getRightFace() {
    return cube.getRight();
}

FaceColor RubiksCubeListBackend::getUpFace() {
    return cube.getTop();
}

FaceColor RubiksCubeListBackend::getDownFace() {
    return cube.getBottom();
}

FaceColor RubiksCubeListBackend::getBackFace() {
    return cube.getBack();
}

void RubiksCubeListBackend::setOrientation(const FaceColor &front, const FaceColor &top)
{
    cube.setOrientation(front, top);
}

FaceColor RubiksCubeListBackend::getColor(const FaceColor& side, const int& row, const int& clm) const {
    return faces[side*9+row*3+clm];
}

std::string RubiksCubeListBackend::toString()
{
    std::stringstream out;
    for (FaceColor s: iter_faces) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                out << to_string(getColor(s, i, j));
                if (j != 2) out << " ";
            }
            out << "\n";
        }
        out << "\n";
    }
    std::string output = out.str();
    output = output.substr(0,output.size()-2);
    return output;
}

void RubiksCubeListBackend::setCurrentFace(const FaceColor &s)
{
    cube.setFront(s);
}

void RubiksCubeListBackend::turnRightFaceCW()
{
    turnFace(getRightFace(), true);
}

void RubiksCubeListBackend::turnRightFaceCCW()
{
    turnFace(getRightFace(), false);
}

void RubiksCubeListBackend::turnLeftFaceCW()
{
    turnFace(getLeftFace(), true);
}

void RubiksCubeListBackend::turnLeftFaceCCW()
{
    turnFace(getLeftFace(), false);
}

void RubiksCubeListBackend::turnUpFaceCW()
{
    turnFace(getUpFace(), true);
}

void RubiksCubeListBackend::turnUpFaceCCW()
{
    turnFace(getUpFace(), false);
}

void RubiksCubeListBackend::turnDownFaceCW()
{
    turnFace(getDownFace(), true);
}

void RubiksCubeListBackend::turnDownFaceCCW()
{
    turnFace(getDownFace(), false);
}

void RubiksCubeListBackend::turnFrontFaceCW()
{
    turnFace(cube.getFront(), true);
}

void RubiksCubeListBackend::turnFrontFaceCCW()
{
    turnFace(cube.getFront(), false);
}

void RubiksCubeListBackend::turnBackFaceCW()
{
    turnFace(getBackFace(), true);
}

void RubiksCubeListBackend::turnBackFaceCCW()
{
    turnFace(getBackFace(), false);
}



RubiksCubeListBackend::RubiksCubeListBackend()
{
    for (FaceColor s: iter_faces) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                setColor(s, j, k, s);
            }
        }
    }
}

FaceColor **RubiksCubeListBackend::getSide(const FaceColor &side)
{
    FaceColor** colors = new FaceColor*[3];
    for (int i = 0; i < 3; i++) {
        colors[i] = new FaceColor[3];
        for (int j = 0; j < 3; j++) {
            colors[i][j] = getColor(side, i, j);
        }
    }
    return colors;
}