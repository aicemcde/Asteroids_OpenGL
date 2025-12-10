#include "GL_Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <SDL.h>
#include <glew.h>

GL_Texture::GL_Texture()
	:mTextureID(0)
	, mWidth(0)
	, mHeight(0)
{

}

GL_Texture::~GL_Texture()
{

}

bool GL_Texture::Load(const std::string& fileName)
{
	int channels = 0;

	unsigned char* image = stbi_load(fileName.c_str(), &mWidth, &mHeight, &channels, 0);

	if (!image)
	{
		SDL_Log("Failed to load image : %s", fileName.c_str());
		return false;
	}

	int format = GL_RGB;
	if (channels == 4)
	{
		format = GL_RGBA;
	}

	glGenTextures(1, &mTextureID);
	glBindTexture(GL_TEXTURE_2D, mTextureID);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		format,
		mWidth,
		mHeight,
		0,
		format,
		GL_UNSIGNED_BYTE,
		image
	);

	stbi_image_free(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

void GL_Texture::Unload()
{
	glDeleteTextures(1, &mTextureID);
}

void GL_Texture::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}