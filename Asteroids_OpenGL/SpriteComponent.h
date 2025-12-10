#pragma once
#include "Component.h"
#include <SDL.h>

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* owner, int updateOrder = 20);
	~SpriteComponent();

	void Draw(class Shader* shader);
	void SetTexture(class GL_Texture* texture);
private:
	int mTexWidth;
	int mTexHeight;
	class GL_Texture* mTexture;
};