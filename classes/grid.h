#pragma once

#include "raylib.h"
#include <array>
#include <vector>

class Grid
{
    public:
        Grid();

        static constexpr int numRows = 20;
        static constexpr int numCols = 10;
        static constexpr int cellSize = 30;

        using GridMatrix = std::array<std::array<int, numCols>, numRows>;

        GridMatrix grid {};
        void Print() const;
        void Draw() const;
        bool IsCellOutside(int row, int col) const noexcept;
        bool IsCellEmpty(int row, int col);
        int ClearFullRows();

    private:
        bool IsRowFull(int row) const;
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
};
