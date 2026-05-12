#include "Cube.h"

Cube::Cube()
{
    Face* whiteFace = new Face(white);
    Face* redFace = new Face(red);
    Face* blueFace = new Face(blue);
    Face* orangeFace = new Face(orange);
    Face* greenFace = new Face(green);
    Face* yellowFace = new Face(yellow);
    
    Face *faces[] = {whiteFace, redFace, blueFace, orangeFace, greenFace, yellowFace};
    std::copy(std::begin(faces), std::end(faces), std::begin(allFaces));

    whiteFace->others[0] = redFace;
    whiteFace->others[1] = greenFace;
    whiteFace->others[2] = orangeFace;
    whiteFace->others[3] = blueFace;
    whiteFace->others[4] = yellowFace;

    for (int i = 1; i < 5; i++) {
        Face* curF = faces[i];
        curF->others[0] = yellowFace;
        int prev = i-1;
        if (prev == 0) prev = 4;
        curF->others[1] = faces[prev];
        curF->others[2] = whiteFace;
        curF->others[3] = faces[(i%4)+1];
    }

    Face* curF = faces[5];
    curF->others[0] = orangeFace;
    curF->others[1] = greenFace;
    curF->others[2] = redFace;
    curF->others[3] = blueFace;
    curF->others[4] = whiteFace;

    current = whiteFace;
}

Cube::~Cube()
{
    for (int i = 0; i < 6; i++) {
        delete allFaces[i];
        allFaces[i] = nullptr;
    }
}

// Sets the front side of the cube to the newFront value if it is valid
void Cube::setFront(const FaceColor &newFront)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (allFaces[i]->front == newFront) {
            break;
        }
    }
    if (i != 6) {
        current = allFaces[i];
        i = 0;
    }
}

// Sets the orientation of the cube so that the color top is at the top of the cube if top is adjacent to the front face
void Cube::setTop(const FaceColor &top)
{
    int i = 0;
    for (i = 0; i < 4; i++) {
        if (current->others[i]->front == top) {
            break;
        }
    }
    if (i != 4) {
        this->top = i;
    }
}

void Cube::setBottom(const FaceColor &bottom)
{
    int i = 0;
    for (i = 0; i < 4; i++) {
        if (current->others[i]->front == bottom) break;
    }
    if (i != 4) {
        top = (i+2)%4;
    }
}

FaceColor Cube::getTop()
{
    return current->others[top]->front;
}

FaceColor Cube::getRight()
{
    return current->others[(top+1)%4]->front;
}

FaceColor Cube::getLeft()
{
    return current->others[(top+3)%4]->front;
}

FaceColor Cube::getBottom()
{
    return current->others[(top+2)%4]->front;
}

FaceColor Cube::getBack()
{
    return current->others[4]->front;
}

FaceColor Cube::getFront()
{
    return current->front;
}

void Cube::rotateDown()
{
    FaceColor curC = getFront();
    FaceColor bot = getBottom();
    setFront(bot);
    setTop(curC);
}

void Cube::rotateRight()
{
    FaceColor top = getTop();
    FaceColor newFront = getRight();
    setFront(newFront);
    setTop(top);
}

void Cube::rotateLeft()
{
    FaceColor top = getTop();
    FaceColor newFront = getLeft();
    setFront(newFront);
    setTop(top);
}

void Cube::rotateUp()
{
    FaceColor newBot = getFront();
    FaceColor newC = getTop();
    setFront(newC);
    setBottom(newBot);
}
