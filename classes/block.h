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

    protected:
        int cellSize;
        int rotationState;
        Color color;
        BlockType blockType;
};

