#include "game.h"
#include "blocks.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks(); 
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, blocks.size() - 1);

    int idx = distr(gen);
    Block block = blocks[idx];
    blocks.erase(blocks.begin() + idx);

    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return { LBlock(), JBlock(), SBlock(), TBlock(), ZBlock(), IBlock(), OBlock() };
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}
