#include <vector>

enum FaceColor {
    white,
    yellow,
    red,
    orange,
    blue,
    green
};

const std::vector<FaceColor> iter_faces = {white, yellow, red, orange, blue, green};

const char* to_string(FaceColor c) {
    switch (c) {
        case (white): return "W";
        case (yellow): return "Y";
        case (red): return "R";
        case (orange): return "O";
        case (blue): return "B";
        case (green): return "G";
        default: return "U";
    }
}