#include "classes/colors.h"
#include "classes/game.h"
#include "raylib.h"

int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(GetCellColor(CellType::DarkBlue));

        {
            game.HandleInput();
            game.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
