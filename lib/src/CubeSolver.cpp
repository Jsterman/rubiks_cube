#include "CubeSolver.h"

bool CubeSolver::isWhiteCrossSolved(const RubiksCube &cube)
{
    bool solved = (cube.getColor(white, 1, 0) == white) && (cube.getColor(white, 0, 1) == white) && (cube.getColor(white, 2, 1) == white) && (cube.getColor(white, 1, 2) == white);
    solved = solved && (cube.getColor(red, 2, 1) == red) && (cube.getColor(blue, 2, 1) == blue) && (cube.getColor(orange, 2, 1) == orange) && (cube.getColor(green, 2, 1) == green);
}

void CubeSolver::solveWhiteCross(RubiksCube &cube)
{
    cube.setCurrentFace(yellow);
    if (cube.getColor(yellow, 0, 1) == white) {

        FaceColor otherSide = cube.getColor(orange, 0, 1);
        if (otherSide == red) {
            cube.turnFrontFaceCW();
            cube.turnFrontFaceCW();
        }
    }
    
}

void CubeSolver::solveWhiteCorners(RubiksCube &cube)
{
}

void CubeSolver::solveSecondLayer(RubiksCube &cube)
{
}

void CubeSolver::solveYellowCross(RubiksCube &cube)
{
}

void CubeSolver::solveYellowCorners(RubiksCube &cube)
{
}

void CubeSolver::placeYellowCorners(RubiksCube &cube)
{
}

void CubeSolver::placeYellowCenters(RubiksCube &cube)
{
}

void CubeSolver::jamesMethod(RubiksCube &cube)
{
    solveWhiteCross(cube);
    solveWhiteCorners(cube);
    solveSecondLayer(cube);
    solveYellowCross(cube);
    solveYellowCorners(cube);
    placeYellowCorners(cube);
    placeYellowCenters(cube);
}
