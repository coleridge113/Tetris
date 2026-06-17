#include "classes/colors.h"
#include "classes/game.h"
#include "raylib.h"
#include <string>


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
    Font font = GetFontDefault();

    while (WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(GetCellColor(static_cast<int>(CellType::DarkBlue)));

        {
            DrawTextEx(font, "Score", {360, 15}, 32, 2, WHITE);
            DrawRectangleRounded(
                {320, 55, 170, 60}, 
                0.3, 6, 
                GetCellColor(static_cast<int>(CellType::LightBlue))
            );

            {
                const char* scoreText = TextFormat("%i", game.score);
                Vector2 textSize = MeasureTextEx(font, scoreText, 32, 2);
                constexpr float centerX = 400.0f;
                constexpr float textY = 70.0f;
                const float dynamicX = centerX - (textSize.x / 2.0f);

                DrawTextEx(font, scoreText, { dynamicX, textY }, 32, 2, WHITE);
            }

            DrawTextEx(font, "Next Tile", {335, 150}, 32, 2, WHITE);
            DrawRectangleRounded(
                {320, 190, 170, 180}, 
                0.11, 6, 
                GetCellColor(static_cast<int>(CellType::LightBlue))
            );

            if (game.gameOver) {
                DrawTextEx(font, "Game Over", {325, 445}, 32, 2, WHITE);
            }
        }

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
