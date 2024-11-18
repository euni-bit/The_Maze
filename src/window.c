#include "../headers/header.h"

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;

/**
 * initializeWindow - Initialize SDL window to display the maze.
 * Return: true on success, false on failure.
 */
bool initializeWindow(void)
{
    SDL_DisplayMode display_mode;
    int fullScreenWidth, fullScreenHeight;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return (false);
    }

    SDL_GetCurrentDisplayMode(0, &display_mode);
    fullScreenWidth = display_mode.w;
    fullScreenHeight = display_mode.h;

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        fullScreenWidth,
        fullScreenHeight,
        SDL_WINDOW_BORDERLESS
    );

    if (!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return (false);
    }

    renderer = SDL_CreateRenderer(window, -1, 1);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return (false);
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    /* Allocate memory for the color buffer */
    colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

    /* Create an SDL_Texture to display the color buffer */
    colorBufferTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    );

    return (true);
}

/**
 * destroyWindow - Frees resources and destroys the SDL window and renderer.
 */
void destroyWindow(void)
{
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * clearColorBuffer - Clears the color buffer for every frame.
 * @color: The color to fill the buffer with.
 */
void clearColorBuffer(color_t color)
{
    int i;

    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
    {
        colorBuffer[i] = color;
    }
}

/**
 * renderColorBuffer - Renders the color buffer onto the screen.
 */
void renderColorBuffer(void)
{
    SDL_UpdateTexture(colorBufferTexture, NULL,
                      colorBuffer, SCREEN_WIDTH * sizeof(uint32_t));
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

/**
 * drawPixel - Sets a color for a specific pixel in the buffer.
 * @x: The x-coordinate of the pixel.
 * @y: The y-coordinate of the pixel.
 * @color: The color to assign to the pixel.
 */
void drawPixel(int x, int y, color_t color)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        colorBuffer[(SCREEN_WIDTH * y) + x] = color;
    }
}