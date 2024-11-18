#include "../headers/header.h"


color_t colorBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];


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
	printf("Drawing rectangle at (%d, %d) with size %dx%d and color 0x%X\n", x, y, width, height, color);

	for (int i = x; i < (x + width); i++)
	{
		for (int j = y; j < (y + height); j++)
		{
			drawPixel(i, j, color);
		}
	}
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
/**
 * render_game - calls all functions needed for on-screen rendering
 *
*/
void render_game(void)
{
	clearColorBuffer(0xFF000000);

	renderWall();
	renderMap();
	renderRays();
	renderPlayer();
	renderWeapon();

	if (isRaining)
	{
		renderRain();
	}

	renderColorBuffer();
}

void renderWeapon(void)
{
    upng_t *currentTexture = (isWeaponFiring) ? weaponFrames[currentWeaponFrame] : weaponTexture;

	if (currentTexture == NULL)
	{
		printf("Error: Current weapon texture is NULL. Skipping rendering.\n");
		return;
    }

	color_t *buffer= (color_t *)upng_get_buffer(currentTexture);
	int width = upng_get_width(currentTexture);
	int height = upng_get_height(currentTexture);

	int x = (SCREEN_WIDTH - width) / 2;
	int y = (SCREEN_HEIGHT - height) - 20;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			color_t texelColor = buffer[i * width + j];

			if ((texelColor & 0xFF000000) != 0)
			{
				drawPixel(x + j, y + i, texelColor);
			}
		}
	}
}

