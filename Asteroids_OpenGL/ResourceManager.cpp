#include "ResourceManager.h"
#include "GL_Texture.h"

ResourceManager::~ResourceManager()
{

}

GL_Texture* ResourceManager::GetTexture(const std::string& fileName)
{
	GL_Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		tex = iter->second.get();
	}
	else
	{
		std::unique_ptr<GL_Texture> uniTex = std::make_unique<GL_Texture>();
		if (uniTex->Load(fileName))
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