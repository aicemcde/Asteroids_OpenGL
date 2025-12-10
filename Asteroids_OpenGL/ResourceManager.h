#pragma once
#include <memory>
#include <unordered_map>
#include <string>

class ResourceManager
{
public:
	~ResourceManager();
	class GL_Texture* GetTexture(const std::string& fileName);
	void Unload();
private:
	std::unordered_map<std::string, std::unique_ptr<class GL_Texture>> mTextures;
};