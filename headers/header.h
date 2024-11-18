#ifndef HEADER_H
#define HEADER_H

/* Libraries */
#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "upng.h"


/* Constants */
#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS SCREEN_WIDTH

#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 8

#define NUM_WEAPON_FRAMES 3

typedef uint32_t color_t;

/* Global Game State */
extern bool GameRunning;

/*Input Functions*/
void handleInput(void);

/* Drawing Functions */

bool initializeWindow(void);
void destroyWindow(void);
void clearColorBuffer(color_t color);
void render_game(void);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);

/* Map Functions */

bool DetectCollision(float x, float y);
bool isInsideMap(float x, float y);
void renderMap(void);
int getMapValue(int row, int col);

/* Player Structure and Functions */

/**
 * struct player_s - struct for the textures
 * @x: x coordinate
 * @y: y coordinate
 * @width: player width
 * @height: player height
 * @turnDirection: Turn Direction
 * @walkDirection: Walk Direction
 * @rotationAngle: player rotation angle
 * @walkSpeed: walk speed
 * @turnSpeed: turn speed
 */

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

extern player_t player;

void movePlayer(float DeltaTime);
void renderPlayer(void);

/* Raycasting Structure and Functions */

/**
 * struct ray_s - struct for the textures
 * @rayAngle: ray angle
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit x coordinate
 * @distance: ditance to the wall
 * @wasHitVertical: verify hit vertical
 * @wallHitContent: wall hit content
 */

typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

float distanceBetweenPoints(float x1, float y1, float x2, float y2);
bool isRayFacingUp(float angle);
bool isRayFacingDown(float angle);
bool isRayFacingLeft(float angle);
bool isRayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderRays(void);
void horzIntersection(float rayAngle);
void vertIntersection(float rayAngle);

/* Texture Structure and Functions */

/**
 * struct texture_s - struct for the textures
 * @width: texture width
 * @height: texture height
 * @texture_buffer: pointer to texture buffer
 * @upngTexture: pointer to upng buffer
 *
 */

typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

texture_t wallTextures[NUM_TEXTURES];

void WallTexturesready(void);
void freeWallTextures(void);

/* Wall rendering */
void renderWall(void);

/* Weapon Animation Functions and Variables */
extern upng_t *weaponTexture;
extern color_t *weaponTextureBuffer;
extern int weaponWidth, weaponHeight;
extern upng_t *weaponFrames[NUM_WEAPON_FRAMES];
extern int currentWeaponFrame;
extern int weaponAnimationTimer;
extern bool isWeaponFiring;

void renderWeapon(void);
void loadWeaponTexture(void);
void updateWeaponAnimation(void);
void handleWeaponInput(SDL_Event event);
void freeWeaponTexture(void);
void updateWeaponAnimation(void);

/* Rain Functions and Structure */
extern bool isRaining;

#endif /*HEADER_H*/
