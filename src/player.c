#include "../headers/header.h"

/**
 * movePlayer - Updates the player's position based on input and delta time.
 * @deltaTime: Time elapsed since the last frame, used for smooth movement
 * scaling.
 */
void movePlayer(float deltaTime)
{
	float moveStep, newPlayerX, newPlayerY;

	player.rotationAngle += player.turnDirection * player.turnSpeed * deltaTime;
	moveStep = player.walkDirection * player.walkSpeed * deltaTime;

	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

	if (isInsideMap(newPlayerX, newPlayerY) && !DetectCollision(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}

/**
 * renderPlayer - Render the player on the minimap.
 */
void renderPlayer(void)
{
	drawRect(
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF
	);

}
