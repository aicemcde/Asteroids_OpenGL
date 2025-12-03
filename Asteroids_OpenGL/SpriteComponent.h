#pragma once
#include "Component.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(int updateOrder = 20);
	~SpriteComponent();

	void Draw(class Shader* shader);
};