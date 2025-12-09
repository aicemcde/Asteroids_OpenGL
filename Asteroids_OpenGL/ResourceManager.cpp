#include "ResourceManager.h"
#include <SDL_image.h>
#include "Texture.h"

Texture* ResourceManager::GetTexture(const char* fileName)
{
	Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		tex = iter->second.get();
	}
	else
	{
		std::unique_ptr<Texture> uniTex = std::make_unique<Texture>();
		if (tex->Load(fileName))
		{
			tex = uniTex.get();
			mTextures.emplace(fileName, std::move(uniTex));
		}
	}
	return tex;
}

void ResourceManager::Unload()
{
	mTextures.clear();
}