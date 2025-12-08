#include "ResourceManager.h"
#include <SDL_image.h>

SDL_Texture* ResourceManager::GetTexture(const char* fileName)
{
	SDL_Surface* surf = IMG_Load(fileName);
	if (!surf)
	{
		SDL_Log("Filed to load texturefile : %s", fileName);
		return nullptr;
	}

	SDL_Texture* text;
	return text;
}