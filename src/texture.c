#include "../headers/header.h"

upng_t *weaponTexture = NULL;
color_t *weaponTextureBuffer = NULL;
int weaponWidth = 0;
int weaponHeight = 0;
upng_t *weaponFrames[NUM_WEAPON_FRAMES];
int currentWeaponFrame = 0;
int weaponAnimationTimer = 0;

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * WallTexturesready - load textures in the respective position
 *
*/
void WallTexturesready(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[i]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[i].upngTexture = upng;
				wallTextures[i].width = upng_get_width(upng);
				wallTextures[i].height = upng_get_height(upng);
				wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}

}

/**
 * freeWallTextures - free wall textures
 *
*/

void freeWallTextures(void)
{
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		if (wallTextures[i].upngTexture != NULL)
		{
			upng_free(wallTextures[i].upngTexture);
			wallTextures[i].upngTexture = NULL; // Avoid double free
		}
	}
}

/**
 * loadWeaponTexture - Load the weapon texture into memory
 * 
*/
void loadWeaponTexture(void)
{
	weaponTexture = upng_new_from_file("./images/weapon.png");

	if (weaponTexture != NULL)
	{
		upng_decode(weaponTexture);
		if (upng_get_error(weaponTexture) == UPNG_EOK)
		{
			weaponWidth = upng_get_width(weaponTexture);
			weaponHeight = upng_get_height(weaponTexture); 
			weaponTextureBuffer = (color_t *)upng_get_buffer(weaponTexture);
		}
		else
		{
			printf("Error decoding weapon texture: %s\n", "./images/weapon.png");
		}
	}
	else
	{
		printf("Failed to load weapon texture: %s\n", "./images/weapon.png");
	}

	char filename[50];
	for (int i = 0; i < NUM_WEAPON_FRAMES; i++)
	{
		sprintf(filename, "./images/weapon_frame_%d.png", i + 1);
		weaponFrames[i] = upng_new_from_file(filename);
		if (weaponFrames[i] != NULL)
		{
			upng_decode(weaponFrames[i]);
			if (upng_get_error(weaponFrames[i]) == UPNG_EOK)
			{
				printf("Weapon frame %d loaded succesfully: %s\n", i + 1, filename);
			}
			else
			{
				printf("Error decoding weapon frame %d: %s\n", i + 1, filename);
				upng_free(weaponFrames[i]);
				weaponFrames[i] = NULL;
			}
		}
		else
		{
			printf("Failed to load weapon frame %d: %s\n", i + 1, filename);
		}
	}
}

/**
 * freeWeaponTexture - Free the weapon texture from memory
 * 
*/
void freeWeaponTexture(void)
{
	if (weaponTexture != NULL)
	{
		upng_free(weaponTexture);
		weaponTexture = NULL;
		weaponTextureBuffer = NULL;
	}
	for (int i = 0; i < NUM_WEAPON_FRAMES; i++)
	{
		if (weaponFrames[i] != NULL)
		{
			upng_free(weaponFrames[i]);
			weaponFrames[i] = NULL;
		}
	}
}
