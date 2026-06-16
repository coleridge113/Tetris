#include "classes/colors.h"
#include "classes/game.h"
#include "raylib.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if ((currentTime - lastUpdateTime) >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(GetCellColor(static_cast<int>(CellType::DarkBlue)));

        {
            game.HandleInput();
            if (EventTriggered(0.8))
            {
                game.MoveBlockDown();
            }
            game.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
