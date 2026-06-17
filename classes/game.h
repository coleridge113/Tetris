#pragma once

#include "block.h"
#include "grid.h"
#include <vector>

class Game
{
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        bool gameOver;
        int score;

        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void RotateBlock();
        void GetNextBlock();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

        bool IsBlockOutside();
        bool BlockFits();
        void LockBlock();
        void Reset();
        void CalculateScore(const int& completedRows);
};
