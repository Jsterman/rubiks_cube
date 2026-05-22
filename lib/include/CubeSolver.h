#include <RubiksCube.h>

class CubeSolver {
private:
    bool isWhiteCrossSolved(const RubiksCube &cube);
public:
    void solveWhiteCross(RubiksCube &cube);
    void solveWhiteCorners(RubiksCube &cube);
    void solveSecondLayer(RubiksCube &cube);
    void solveYellowCross(RubiksCube &cube);
    void solveYellowCorners(RubiksCube &cube);
    void placeYellowCorners(RubiksCube &cube);
    void placeYellowCenters(RubiksCube &cube);
    void jamesMethod(RubiksCube &cube);
};