#include "../headers/header.h"

bool isRaining = false;
raindrop_t raindrops[MAX_RAINDROPS];

void initializeRain(void)
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        raindrops[i].x = rand() % SCREEN_WIDTH;
        raindrops[i].y = rand() % SCREEN_HEIGHT;
        raindrops[i].speed = 300 + rand() % 200;
        raindrops[i].width = 2 + rand() % 2;
        raindrops[i].height = 5 + rand() % 3;
    }
}

void updateRain(float DeltaTime)
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        raindrops[i].y += raindrops[i].speed * DeltaTime;

        if (raindrops[i].y > SCREEN_HEIGHT)
        {
            raindrops[i].x = rand() % SCREEN_WIDTH;
            raindrops[i].y = 0;
        }
    }
}

void renderRain(void)
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        drawRect((int)raindrops[i].x, (int)raindrops[i].y, 2, 5, 0xFF0000FF);
    }
}
