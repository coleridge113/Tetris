#include "game.h"
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
    grid.Print();
    GetNextBlock();
    grid.ClearFullRows();
}

void Game::Reset()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;

}
