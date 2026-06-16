#pragma once

#include "position.h"
#include "raylib.h"
#include <map>
#include <vector>

enum class BlockType 
{
    Default = 0,
    LBlock,
    JBlock,
    SBlock,
    TBlock,
    ZBlock,
    IBlock,
    OBlock
};

inline int GetBlockId(BlockType type)
{
    return static_cast<int>(type);
};

class Block 
{
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
        void Draw();
        void Rotate();
        void Move(int row, int col);
        std::vector<Position> GetCellPositions();

    protected:
        Color color;
        BlockType blockType;
        int cellSize;
        int rotationState;
        int rowOffset;
        int colOffset;
};

