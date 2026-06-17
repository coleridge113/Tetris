#pragma once

#include "block.h"
#include "grid.h"
#include <vector>

class Game
{
    public:
        Game();
        bool gameOver;
        int score;

        void Draw();
        void HandleInput();
        void MoveBlockDown();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();

        bool IsBlockOutside();
        bool BlockFits();
        void LockBlock();
        void Reset();
        void CalculateScore(const int& completedRows);
        void MoveBlockLeft();
        void MoveBlockRight();
        void RotateBlock();
        void GetNextBlock();
        Block _GetSpecificBlock(BlockType type);
};
