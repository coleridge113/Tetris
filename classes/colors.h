#pragma once

#include "raylib.h"
#include <vector>

enum class CellType : int 
{
    Empty = 0,
    Green,
    Red,
    Orange,
    Yellow,
    Purple,
    Cyan,
    Blue,
    DarkBlue,
    LightBlue
};

inline Color GetCellColor(int value) {
    switch (value) {
        case 0: return Color{26, 31, 40, 255};
        case 1: return Color{47, 230, 23, 255};
        case 2: return Color{232, 18, 18, 255};
        case 3: return Color{226, 116, 17, 255};
        case 4: return Color{237, 234, 4, 255};
        case 5: return Color{166, 0, 247, 255};
        case 6: return Color{21, 204, 209, 255};
        case 7: return Color{13, 64, 216, 255};
        case 8: return Color{44, 44, 127, 255};
        case 9: return Color{59, 85, 162, 255};
    }
    return BLANK;
};
