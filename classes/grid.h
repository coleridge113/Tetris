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
        bool IsCellOutside(int row, int col);
        bool IsCellEmpty(int row, int col);
        int ClearFullRows();

    private:
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
};
