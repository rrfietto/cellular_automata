#include <raylib.h>
#include <iostream>

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 500

#define HEIGHT SCREEN_HEIGHT / 2
#define WIDTH SCREEN_WIDTH / 2

int screenBuffer[HEIGHT][WIDTH] = {{0}};

void drawPixel(int x, int y)
{
    DrawRectangle(x, y, 10, 10, WHITE);
    screenBuffer[x][y] = 1;
}

void grow()
{
    for (int i = 1; i < HEIGHT - 1; i++)
    {
        for (int j = 1; j < WIDTH - 1; j++)
        {
            if (screenBuffer[i][j] == 1 && screenBuffer[i][j - 1] == 0 && screenBuffer[i - 1][j] == 0 && screenBuffer[i + 1][j] == 0 && screenBuffer[i][j + 1] == 0)
            {
                drawPixel(i - 10, j + 10);
                drawPixel(i + 10, j + 10);
            }
        }
    }
}

int main()
{
    Camera2D cam = {0};
    cam.zoom = 4.0f;

    int initCellX = 200;
    int initCellY = 100;

    screenBuffer[initCellX][initCellY] = 1;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automata");

    SetTargetFPS(10);

    while (!(WindowShouldClose()))
    {

        BeginDrawing();
        for (int i = 1; i < HEIGHT - 1; i++)
        {
            for (int j = 1; j < WIDTH - 1; j++)
            {
                if (screenBuffer[i][j] != 0)
                {
                    drawPixel(i, j);
                }
            }
        }
        grow();
        // ClearBackground(BLACK);
        EndDrawing();
    }

    return 0;
}
