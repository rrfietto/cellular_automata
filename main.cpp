#include <raylib.h>
#include <iostream>

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 500

#define HEIGHT SCREEN_HEIGHT / 10
#define WIDTH SCREEN_WIDTH / 10

int screenBuffer[HEIGHT][WIDTH] = {{0}};

void drawPixel(int x, int y)
{
    DrawRectangle(x * 10, y * 10, 10, 10, WHITE);
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
                drawPixel(i - 1, j + 1);
                drawPixel(i + 1, j + 1);
            }
        }
    }
}

int main()
{
    int initCellX = 25;
    int initCellY = 25;

    screenBuffer[initCellX][initCellY] = 1;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automata");

    SetTargetFPS(10);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << screenBuffer[i][j];
        }
        std::cout << std::endl;
    }

    while (!(WindowShouldClose()))
    {
        ClearBackground(BLACK);
        BeginDrawing();
        drawPixel(initCellX, initCellY);
        // for (int i = 1; i < HEIGHT - 1; i++)
        // {
        //     for (int j = 1; j < WIDTH - 1; j++)
        //     {
        //         if (screenBuffer[i][j] != 0)
        //         {
        //             drawPixel(i, j);
        //         }
        //     }
        // }
        grow();

        EndDrawing();
    }

    return 0;
}
