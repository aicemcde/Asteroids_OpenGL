#pragma once
#include "Component.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* owner, int updateOrder = 20);
	~SpriteComponent();

	void Draw(class Shader* shader);
private:
	int mTexWidth;
	int mTexHeight;
};