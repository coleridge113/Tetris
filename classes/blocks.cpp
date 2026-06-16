#include "blocks.h"
#include "colors.h"

LBlock::LBlock()
{
    id = GetBlockId(BlockType::LBlock);
    color = GetCellColor(CellType::Orange);

    cells[0] = { Position{0, 2}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
    cells[1] = { Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{2, 2} };
    cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 0} };
    cells[3] = { Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1} };

    Move(0, 3);
}

JBlock::JBlock()
{
    id = GetBlockId(BlockType::JBlock);
    color = GetCellColor(CellType::Blue);

    cells[0] = { Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
    cells[1] = { Position{0, 1}, Position{0, 2}, Position{1, 1}, Position{2, 1} };
    cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 2} };
    cells[3] = { Position{0, 1}, Position{1, 1}, Position{2, 0}, Position{2, 1} };

    Move(0, 3);
}

IBlock::IBlock()
{
    id = GetBlockId(BlockType::IBlock);
    color = GetCellColor(CellType::Cyan);

    cells[0] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{1, 3} };
    cells[1] = { Position{0, 2}, Position{1, 2}, Position{2, 2}, Position{3, 2} };
    cells[2] = { Position{2, 0}, Position{2, 1}, Position{2, 2}, Position{2, 3} };
    cells[3] = { Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{3, 1} };

    Move(-1, 3);
}

OBlock::OBlock()
{
    id = GetBlockId(BlockType::OBlock);
    color = GetCellColor(CellType::Yellow);

    cells[0] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
    cells[1] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
    cells[2] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
    cells[3] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };

    Move(0, 4);
}

SBlock::SBlock()
{
    id = GetBlockId(BlockType::SBlock);
    color = GetCellColor(CellType::Green);

    cells[0] = { Position{0, 1}, Position{0, 2}, Position{1, 0}, Position{1, 1} };
    cells[1] = { Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 2} };
    cells[2] = { Position{1, 1}, Position{1, 2}, Position{2, 0}, Position{2, 1} };
    cells[3] = { Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{2, 1} };

    Move(0, 3);
}

TBlock::TBlock()
{
    id = GetBlockId(BlockType::TBlock);
    color = GetCellColor(CellType::Purple);

    cells[0] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
    cells[1] = { Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
    cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
    cells[3] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 1} };

    Move(0, 3);
}

ZBlock::ZBlock()
{
    id = GetBlockId(BlockType::ZBlock);
    color = GetCellColor(CellType::Red);

    cells[0] = { Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{1, 2} };
    cells[1] = { Position{0, 2}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
    cells[2] = { Position{1, 0}, Position{1, 1}, Position{2, 1}, Position{2, 2} };
    cells[3] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 0} };

    Move(0, 3);
}
