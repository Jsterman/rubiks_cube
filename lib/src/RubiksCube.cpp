#include "RubiksCube.h"

RubiksCube::RubiksCube(const BackendType &type)
{
    RubiksCubeBackendFactory factory;
    backend = factory.getBackend(type);
}

FaceColor RubiksCube::getColor(const FaceColor &side, const int &row, const int &clm) const
{
    return backend->getColor(side, row, clm);
}

std::string RubiksCube::toString()
{
    return backend->toString();
}

void RubiksCube::setCurrentFace(const FaceColor &face)
{
    backend->setCurrentFace(face);
}

void RubiksCube::turnRightFaceCW()
{
    backend->turnRightFaceCW();
}

void RubiksCube::turnRightFaceCCW()
{
    backend->turnRightFaceCCW();
}

void RubiksCube::turnLeftFaceCW()
{
    backend->turnLeftFaceCW();
}

void RubiksCube::turnLeftFaceCCW()
{
    backend->turnLeftFaceCCW();
}

void RubiksCube::turnUpFaceCW()
{
    backend->turnUpFaceCW();
}

void RubiksCube::turnUpFaceCCW()
{
    backend->turnUpFaceCCW();
}

void RubiksCube::turnDownFaceCW()
{
    backend->turnDownFaceCW();
}

void RubiksCube::turnDownFaceCCW()
{
    backend->turnDownFaceCCW();
}

void RubiksCube::turnFrontFaceCW()
{
    backend->turnFrontFaceCW();
}

void RubiksCube::turnFrontFaceCCW()
{
    backend->turnFrontFaceCCW();
}

void RubiksCube::turnBackFaceCW()
{
    backend->turnBackFaceCW();
}

void RubiksCube::turnBackFaceCCW()
{
    backend->turnBackFaceCCW();
}

void RubiksCube::executeSequence(std::string seq)
{
    std::string command;
    while (seq.size() > 0) {
        if (seq[0] == ' ') {
            seq = seq.substr(1);
        }
        if (seq.size() > 1) {
            command = seq.substr(0,2);
            seq = seq.substr(2);
        }
        else {
            command = seq[0] + ' ';
            seq = "";
        }

        if (command == "R ") {
            turnRightFaceCW();
        }
        else if (command == "R'") {
            turnRightFaceCCW();
        }
        else if (command == "R2") {
            turnRightFaceCW();
            turnRightFaceCW();
        }
        else if (command == "L ") {
            turnLeftFaceCW();
        }
        else if (command == "L'") {
            turnLeftFaceCCW();
        }
        else if (command == "L2") {
            turnLeftFaceCW();
            turnLeftFaceCW();
        }
        else if (command == "U ") {
            turnUpFaceCW();
        }
        else if (command == "U'") {
            turnUpFaceCCW();
        }
        else if (command == "U2") {
            turnUpFaceCW();
            turnUpFaceCW();
        }
        else if (command == "D ") {
            turnDownFaceCW();
        }
        else if (command == "D'") {
            turnDownFaceCCW();
        }
        else if (command == "D2") {
            turnDownFaceCW();
            turnDownFaceCW();
        }
        else if (command == "F ") {
            turnFrontFaceCW();
        }
        else if (command == "F'") {
            turnFrontFaceCCW();
        }
        else if (command == "F2") {
            turnFrontFaceCW();
            turnFrontFaceCW();
        }
        else if (command == "B ") {
            turnBackFaceCW();
        }
        else if (command == "B'") {
            turnBackFaceCCW();
        }
        else if (command == "B2") {
            turnBackFaceCW();
            turnBackFaceCW();
        }
    }

}
