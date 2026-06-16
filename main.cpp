#include "classes/colors.h"
#include "classes/grid.h"
#include "raylib.h"
#include <cstddef>
#include "classes/blocks.cpp"

Grid grid = Grid();

int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    grid.Print();

    LBlock lblock = LBlock();

    while (WindowShouldClose() == false) 
    {

        BeginDrawing();
        ClearBackground(GetCellColor(CellType::DarkBlue));
        grid.Draw();
        lblock.Draw();
        EndDrawing();
    }

    CloseWindow();
}
