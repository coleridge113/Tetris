#include "classes/grid.h"
#include "raylib.h"
#include <cstddef>

Grid grid = Grid();

int main()
{
    Color darkBlue {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    while (WindowShouldClose() == false) 
    {

        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}
