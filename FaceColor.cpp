#include <FaceColor.h>
const char *to_string(FaceColor c) {
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