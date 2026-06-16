#include "grid.h"
#include "raylib.h"
#include "colors.h"
#include <iostream>

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;

}

void Grid::Print()
{
    for (auto row = 0; row < numRows; ++row) 
    {
        for (auto col = 0; col < numCols; ++col) 
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << "\n";
    }
}

void Grid::Draw()
{
    for (auto row = 0; row < numRows; ++row) 
    {
        for (auto col = 0; col < numCols; ++col) 
        {
            int cellValue = grid[row][col];
            int posX = col * cellSize + 1;
            int posY = row * cellSize + 1;

            DrawRectangle(
                posX, 
                posY, 
                cellSize - 1, 
                cellSize - 1, 
                GetCellColor(CellType::Empty)
            );
        }
    }
}
