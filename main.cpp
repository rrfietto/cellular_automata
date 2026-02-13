#include <raylib.h>
#include <iostream>
#include <random>
#include <ctime>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800

#define HEIGHT SCREEN_HEIGHT / 10
#define WIDTH SCREEN_WIDTH / 10

int screenBuffer[HEIGHT][WIDTH] = {{0}};
int prevScreenBuffer[HEIGHT][WIDTH] = {{0}};

void drawPixel(int x, int y)
{
    DrawRectangle(x * 10, y * 10, 10, 10, WHITE);
    screenBuffer[x][y] = 1;
}

// add growth rules here

void grow()
{
    // pattern 1

    int randIdxI = 1 + rand() % 10;
    int randIdxJ = 1 + rand() % 10;

    for (int i = 1; i < HEIGHT - 1; i++)
    {
        for (int j = 1; j < WIDTH - 1; j++)
        {

            if ((prevScreenBuffer[i][j] == 0) &&
                (prevScreenBuffer[i - 1][j - 1] == 0) &&
                (prevScreenBuffer[i - 1][j] == 0) &&
                (prevScreenBuffer[i][j - 1] == 0) &&
                (prevScreenBuffer[i][j + 1] == 0) &&
                (prevScreenBuffer[i + 1][j] == 0) &&
                (prevScreenBuffer[i + 1][j + 1] == 0) &&
                ((prevScreenBuffer[i - 1][j + 1] == 1) ||
                 (prevScreenBuffer[i + 1][j - 1] == 1)) &&
                (j < 70 && j > 10) && (i < 70 && i > 10) && (i % randIdxI != 0 || j % randIdxJ != 0))
            {
                drawPixel(i, j);
            }

            if ((prevScreenBuffer[i][j] == 0) &&
                (prevScreenBuffer[i - 1][j] == 0) &&
                (prevScreenBuffer[i - 1][j + 1] == 0) &&
                (prevScreenBuffer[i][j - 1] == 0) &&
                (prevScreenBuffer[i][j + 1] == 0) &&
                (prevScreenBuffer[i + 1][j - 1] == 0) &&
                (prevScreenBuffer[i + 1][j] == 0) &&
                ((prevScreenBuffer[i - 1][j - 1] == 1) ||
                 (prevScreenBuffer[i + 1][j + 1] == 1)) &&
                (j < 70 && j > 10) && (i < 70 && i > 10) && (i % randIdxI != 0 || j % randIdxJ != 0))
            {
                drawPixel(i, j);
            }
        }
    }

    // ------------------------------------------
}

int main()
{
    srand(time(NULL));
    int initCellX = WIDTH / 2;
    int initCellY = HEIGHT / 2;

    screenBuffer[initCellX][initCellY] = 1;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automata");

    SetTargetFPS(10);

    while (!(WindowShouldClose()))
    {
        BeginDrawing();

        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (screenBuffer[i][j] == 1)
                {
                    drawPixel(i, j);
                }
            }
        }

        grow();

        EndDrawing();
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                prevScreenBuffer[i][j] = screenBuffer[i][j];
            }
        }
    }

    return 0;
}
