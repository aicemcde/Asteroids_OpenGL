#pragma once
#include <SDL.h>
#include <memory>
#include <unordered_map>

class ResourceManager
{
public:
	class Texture* GetTexture(const char* fileName);
	void Unload();

private:
	std::unordered_map<std::string, std::unique_ptr<class Texture>> mTextures;
};