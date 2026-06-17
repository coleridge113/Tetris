#include "block.h"
#include "colors.h"
#include "position.h"
#include "raylib.h"
#include <vector>

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    blockType = BlockType::Default;
    color = GetCellColor(static_cast<int>(blockType));
    rowOffset = 0;
    colOffset = 0;
};

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for (auto p : tiles)
    {
        int posX = p.col * cellSize + 1;
        int posY = p.row * cellSize + 1;

        DrawRectangle(
            posX, 
            posY, 
            cellSize - 1, 
            cellSize - 1, 
            color
        );
    }
};

void Block::Rotate()
{
    rotationState = (rotationState + 1) % cells.size();
}

void Block::UndoRotate()
{
    rotationState = (rotationState + cells.size() - 1) % cells.size();
}

void Block::Move(int rows, int cols)
{
    rowOffset += rows;
    colOffset += cols;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    for (auto& t : tiles)
    {
        t.row += rowOffset;
        t.col += colOffset;
    }
    return tiles;
}
