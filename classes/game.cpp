#include "game.h"
#include "block.h"
#include "blocks.h"
#include "raylib.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
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
    currentBlock.Draw(11, 11);
    switch (nextBlock.blockType)
    {
        case BlockType::IBlock:
            nextBlock.Draw(256, 258);
            break;

        case BlockType::OBlock:
            nextBlock.Draw(255, 247);
            break;

        case BlockType::ZBlock:
            nextBlock.Draw(272, 250);
            break;

        case BlockType::SBlock:
            nextBlock.Draw(272, 250);
            break;

        default:
            nextBlock.Draw(272, 240);
            break;
    }
}

void Game::HandleInput()
{
    const int keyPressed = GetKeyPressed();
    
    if (gameOver && keyPressed != 0)
    {
        Reset();
    }

    switch (keyPressed)
    {
        case KEY_LEFT: 
            MoveBlockLeft();
            break;
        case KEY_RIGHT: 
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
        case KEY_N:
            GetNextBlock();
            break;
    }
}

void Game::MoveBlockLeft()
{
    if (gameOver) return;

    currentBlock.Move(0, -1);
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    if (gameOver) return;

    currentBlock.Move(0, 1);
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    if (gameOver) return; 

    currentBlock.Move(1, 0);
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

void Game::RotateBlock()
{
    if (gameOver) return;

    currentBlock.Rotate();
    if (IsBlockOutside()) {
        currentBlock.UndoRotate();
    }
}

void Game::GetNextBlock()
{
    if (gameOver) return;

    currentBlock = nextBlock;
    if (!BlockFits())
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
}

bool Game::IsBlockOutside()
{
    const auto& tiles = currentBlock.GetCellPositions();
    for (const auto& item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}

bool Game::BlockFits()
{
    const auto& tiles = currentBlock.GetCellPositions();
    for (const auto& item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.col) == false)
        {
            return false;
        }
    }
    return true;

}

void Game::LockBlock() 
{
    const auto& cells = currentBlock.GetCellPositions();
    for (const auto& cell : cells)
    {
        grid.grid[cell.row][cell.col] = currentBlock.id;
    }
    GetNextBlock();
    int completed = grid.ClearFullRows();
    if (completed > 0) CalculateScore(completed);
}

void Game::Reset()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;

}

void Game::CalculateScore(const int& completedRows)
{
    score += 100 + 200 * (completedRows - 1);;
}

Block Game::_GetSpecificBlock(BlockType type)
{
    switch (type) {
        case BlockType::OBlock: return OBlock();
        case BlockType::IBlock: return IBlock();
        case BlockType::JBlock: return JBlock();
        case BlockType::LBlock: return LBlock();
        case BlockType::TBlock: return TBlock();
        case BlockType::SBlock: return SBlock();
        default:                return ZBlock();
    }

}
