#pragma once
#include <vector>

enum FaceColor {
    white,
    yellow,
    red,
    orange,
    blue,
    green
};

const std::vector<FaceColor> iter_faces = {white, red, blue, orange, green, yellow};

const char* to_string(FaceColor c);