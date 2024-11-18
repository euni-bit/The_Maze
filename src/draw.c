#include "../headers/header.h"

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
*/

void drawRect(int x, int y, int width, int height, color_t color)
{
	int i, j;

	for (i = x; i <= (x + width); i++)
		for (j = y; j <= (y + height); j++)
			drawPixel(i, j, color);
}

/**
 * drawLine - draw a line
 * @x0: x coordinate init
 * @y0: y coordinate init
 * @x1: x coordinate init
 * @y1: y coordinate end
 * @color: pixel color
*/

void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float xIncrement, yIncrement, currentX, currentY;
	int i, longestSideLength, deltaX,  deltaY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	currentX = x0;
	currentY = y0;

	for (i = 0; i < longestSideLength; i++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}

void renderWeapon(void)
{
    if (weaponTextureBuffer == NULL) {
        printf("Error: weaponTextureBuffer is NULL. Skipping rendering.\n");
        return;
    }

    int x = (SCREEN_WIDTH - weaponWidth) / 2;
    int y = (SCREEN_HEIGHT - weaponHeight) - 20;

    for (int i = 0; i < weaponHeight; i++) {
        for (int j = 0; j < weaponWidth; j++) {
            color_t texelColor = weaponTextureBuffer[i * weaponWidth + j];

            if ((texelColor & 0xFF000000) != 0)
			{
                drawPixel(x + j, y + i, texelColor);
            }
        }
    }
}
