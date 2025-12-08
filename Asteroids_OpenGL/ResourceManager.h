#pragma once
#include <SDL.h>
class ResourceManager
{
public:
	SDL_Texture* GetTexture(const char* fileName);
	void Unload();
};