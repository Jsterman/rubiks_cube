#include <RubiksCubeList.h>
#include <sstream>

void RubiksCubeList::setColor(const FaceColor& side, const int& row, const int& clm, const FaceColor& color) {
    faces[side*9+row*3+clm] = color;
}

void RubiksCubeList::turnFacePiecesCW(const FaceColor &side)
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
    setColor(side, 2, 1, getColor(side, 2, 1));
    setColor(side, 2, 1, topMiddle);
}

void RubiksCubeList::turnFacePiecesCCW(const FaceColor &side)
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

void RubiksCubeList::turnRedFaceCW()
{
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(blue, i, 2);
        setColor(blue, i, 2, getColor(white, i, 2));
        setColor(white, i, 2, getColor(green, 2-i, 0));
        setColor(green, 2-i, 0, getColor(yellow, 2, 2-i));
        setColor(yellow, 2, 2-i, current);
    }
    turnFacePiecesCW(red);
}

void RubiksCubeList::turnRedFaceCCW() {
    for (int i = 0; i < 3; i++) {
        FaceColor current = getColor(blue, i, 2);
        setColor(blue, i, 2, getColor(yellow, 2, 2-i));
        setColor(yellow, 2, 2-i, getColor(green, 2-i, 0));
        setColor(green, 2-i, 0, getColor(white, i, 2));
        setColor(white, i, 2, current);
    }

    turnFacePiecesCCW(red);
}

void RubiksCubeList::turnBlueFaceCW() {
    
}

FaceColor RubiksCubeList::getLeftFace()
{
    switch (currentSide) {
        case white:
            return blue;
        case red:
            return blue;
        case blue:
            return orange;
        case orange:
            return green;
        case green:
            return red;
        case yellow:
            return blue;
        default:
            return white;
    }
}

FaceColor RubiksCubeList::getRightFace() {
    switch (currentSide) {
        case white:
            return green;
        case red:
            return green;
        case green:
            return orange;
        case orange:
            return blue;
        case blue:
            return red;
        case yellow:
            return green;
        default:
            return white;
    }
}

FaceColor RubiksCubeList::getUpFace() {
    switch (currentSide)
    {
    case white:
        return red;
    case red:
    case blue:
    case orange:
    case green:
        return yellow;
    case yellow:
        return orange;
    default:
        return white;
    }
}

FaceColor RubiksCubeList::getDownFace() {
    switch (currentSide)
    {
    case white:
        return orange;
    case red:
    case blue:
    case orange:
    case green:
        return white;
    case yellow:
        return red;
    
    default:
        return white;
    }
}

FaceColor RubiksCubeList::getBackFace() {
    switch(currentSide) {
        case white:
            return yellow;
        case red:
            return orange;
        case blue:
            return green;
        case orange:
            return red;
        case green:
            return blue;
        case yellow:
            return white;
        default:
            return white;
    }
}

FaceColor RubiksCubeList::getColor(const FaceColor& side, const int& row, const int& clm) const {
    return faces[side*9+row*3+clm];
}

std::string RubiksCubeList::toString()
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
    return out.str();
}

void RubiksCubeList::setCurrentFace(const FaceColor &s)
{
    currentSide = s;
}

void RubiksCubeList::turnRightFaceCW()
{
    switch(currentSide) {
        case blue:
            turnRedFaceCW();
            break;
    }
}

void RubiksCubeList::turnRightFaceCCW()
{
}

void RubiksCubeList::turnLeftFaceCW()
{
    
}

void RubiksCubeList::turnLeftFaceCCW()
{
}

void RubiksCubeList::turnUpFaceCW()
{
}

void RubiksCubeList::turnUpFaceCCW()
{
}

void RubiksCubeList::turnDownFaceCW()
{
}

void RubiksCubeList::turnDownFaceCCW()
{
}

void RubiksCubeList::turnFrontFaceCW()
{
}

void RubiksCubeList::turnFrontFaceCCW()
{
}

void RubiksCubeList::turnBackFaceCW()
{
}

void RubiksCubeList::turnBackFaceCCW()
{
}



RubiksCubeList::RubiksCubeList()
{
    for (FaceColor s: iter_faces) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                setColor(s, j, k, s);
            }
        }
    }
}

FaceColor **RubiksCubeList::getSide(const FaceColor side)
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