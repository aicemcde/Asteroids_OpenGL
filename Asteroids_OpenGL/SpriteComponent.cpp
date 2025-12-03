#include "SpriteComponent.h"
#include <glew.h>

SpriteComponent::SpriteComponent(int updateOrder)
	:Component(updateOrder)
{

}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Draw(Shader* shader)
{
	glDrawElements(
		GL_TRIANGLES,
		6,
		GL_UNSIGNED_INT,
		nullptr
	);
}