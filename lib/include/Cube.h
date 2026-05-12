#pragma once
#include <FaceColor.h>

struct Face {
    FaceColor front;
    Face *others[5];
    Face(FaceColor front) {
        this->front = front;
    }
};

class Cube {
private:
    Face *allFaces[6];
    Face* current;
    int top = 0;

public:
    Cube();
    ~Cube();
    void setFront(const FaceColor &current);
    void setTop(const FaceColor &top);
    void setBottom(const FaceColor &bottom);

    FaceColor getTop();
    FaceColor getRight();
    FaceColor getLeft();
    FaceColor getBottom();
    FaceColor getBack();
    FaceColor getFront();

    void rotateDown();
    void rotateRight();
    void rotateLeft();
    void rotateUp();
};