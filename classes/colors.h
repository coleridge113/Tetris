#pragma once

#include "raylib.h"
#include <vector>

enum class CellType : int {
    Empty = 0,
    Green,
    Red,
    Orange,
    Yellow,
    Purple,
    Cyan,
    Blue,
    DarkBlue
};

inline Color GetCellColor(CellType type) {
    switch (type) {
        case CellType::Empty:       return Color{26, 31, 40, 255};
        case CellType::Green:       return Color{47, 230, 23, 255};
        case CellType::Red:         return Color{232, 18, 18, 255};
        case CellType::Orange:      return Color{226, 116, 17, 255};
        case CellType::Yellow:      return Color{237, 234, 4, 255};
        case CellType::Purple:      return Color{166, 0, 247, 255};
        case CellType::Cyan:        return Color{21, 204, 209, 255};
        case CellType::Blue:        return Color{13, 64, 216, 255};
        case CellType::DarkBlue:    return Color{44, 44, 127, 255};
    }
    return BLANK;
};
