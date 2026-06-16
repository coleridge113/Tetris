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
    color = GetCellColor(CellType::Empty);
};

void Block::Draw()
{
    std::vector<Position> tiles = cells[rotationState];
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
    if (rotationState < 3) {
        ++rotationState;
    } else {
        rotationState = 0;
    }
}
