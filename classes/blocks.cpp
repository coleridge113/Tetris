#include "colors.h"
#include "block.h"
#include "position.h"

class LBlock : public Block
{
    public:
        LBlock()
        {
            id = GetBlockId(BlockType::LBlock);
            color = GetCellColor(CellType::Orange);

            cells[0] = { Position{0, 2}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
            cells[1] = { Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{2, 2} };
            cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 0} };
            cells[3] = { Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1} };
        };
};

class JBlock : public Block
{
    public:
        JBlock()
        {
            id = GetBlockId(BlockType::JBlock);
            color = GetCellColor(CellType::Blue);

            cells[0] = { Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
            cells[1] = { Position{0, 1}, Position{0, 2}, Position{1, 1}, Position{2, 1} };
            cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 2} };
            cells[3] = { Position{0, 1}, Position{1, 1}, Position{2, 0}, Position{2, 1} };
        };
};

class IBlock : public Block
{
    public:
        IBlock()
        {
            id = GetBlockId(BlockType::IBlock);
            color = GetCellColor(CellType::Cyan);

            cells[0] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{1, 3} };
            cells[1] = { Position{0, 2}, Position{1, 2}, Position{2, 2}, Position{3, 2} };
            cells[2] = { Position{2, 0}, Position{2, 1}, Position{2, 2}, Position{2, 3} };
            cells[3] = { Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{3, 1} };
        };
};

class OBlock : public Block
{
    public:
        OBlock()
        {
            id = GetBlockId(BlockType::OBlock);
            color = GetCellColor(CellType::Yellow);

            cells[0] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
            cells[1] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
            cells[2] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
            cells[3] = { Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1} };
        };
};

class SBlock : public Block
{
    public:
        SBlock()
        {
            id = GetBlockId(BlockType::SBlock);
            color = GetCellColor(CellType::Green);

            cells[0] = { Position{0, 1}, Position{0, 2}, Position{1, 0}, Position{1, 1} };
            cells[1] = { Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 2} };
            cells[2] = { Position{1, 1}, Position{1, 2}, Position{2, 0}, Position{2, 1} };
            cells[3] = { Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{2, 1} };
        };
};

class TBlock : public Block
{
    public:
        TBlock()
        {
            id = GetBlockId(BlockType::TBlock);
            color = GetCellColor(CellType::Purple);

            cells[0] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{1, 2} };
            cells[1] = { Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
            cells[2] = { Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
            cells[3] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 1} };
        };
};

class ZBlock : public Block
{
    public:
        ZBlock()
        {
            id = GetBlockId(BlockType::ZBlock);
            color = GetCellColor(CellType::Red);

            cells[0] = { Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{1, 2} };
            cells[1] = { Position{0, 2}, Position{1, 1}, Position{1, 2}, Position{2, 1} };
            cells[2] = { Position{1, 0}, Position{1, 1}, Position{2, 1}, Position{2, 2} };
            cells[3] = { Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 0} };
        };
};
