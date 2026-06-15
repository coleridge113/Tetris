#pragma once

#include "raylib.h"
#include <vector>
class Grid
{
    public:
        Grid();
        int grid[20][10];
        void Print();
        void Initialize();
        void Draw();

    private:
        std::vector<Color> GetCellColors();
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};
