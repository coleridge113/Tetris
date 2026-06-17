#include "classes/colors.h"
#include "classes/game.h"
#include "raylib.h"


constexpr int windowWidth = 500;
constexpr int windowHeight = 620;
constexpr int targetFPS = 60;
constexpr double interval = 0.8;

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
    InitWindow(windowWidth, windowHeight, "Tetris");
    SetTargetFPS(targetFPS);

    Game game = Game();

    while (WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(GetCellColor(static_cast<int>(CellType::DarkBlue)));

        {
            game.HandleInput();
            if (EventTriggered(interval))
            {
                game.MoveBlockDown();
            }
            game.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
