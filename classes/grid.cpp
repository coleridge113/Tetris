#include "grid.h"
#include "raylib.h"
#include "colors.h"
#include <iostream>


Grid::Grid(){}

void Grid::Print() const
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

void Grid::Draw() const
{
    for (auto row = 0; row < numRows; ++row) 
    {
        for (auto col = 0; col < numCols; ++col) 
        {
            const int cellValue = grid[row][col];
            const int posX = col * cellSize + 11;
            const int posY = row * cellSize + 11;

            DrawRectangle(
                posX, 
                posY, 
                cellSize - 1, 
                cellSize - 1, 
                GetCellColor(cellValue)
            );
        }
    }
}

bool Grid::IsCellOutside(int row, int col) const noexcept
{
    return !(row >= 0 && row < numRows && col >= 0 && col < numCols);
}

bool Grid::IsCellEmpty(int row, int col) const noexcept
{
    return grid[row][col] == 0;
}

bool Grid::IsRowFull(int row) const noexcept
{
    for (int col = 0; col < numCols; ++col)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }

    return true;
}

void Grid::ClearRow(int row)
{
    for (int col = 0; col < numCols; ++col)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int col = 0; col < numCols; ++col)
    {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; --row)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            ++completed;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }

    return completed;
}
