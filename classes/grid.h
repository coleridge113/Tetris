#pragma once

#include "raylib.h"
#include <array>
#include <vector>

class Grid
{
    public:
        using GridMatrix = std::array<std::array<int, 10>, 20>;

        Grid();
        GridMatrix grid {};
        void Print();
        void Draw();

    private:
        std::vector<Color> GetCellColors();
        int numRows;
        int numCols;
        int cellSize;
};
