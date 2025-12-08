#include "SpriteComponent.h"
#include <glew.h>
#include "Math.h"
#include "Actor.h"
#include "Shader.h"
#include "Game.h"
#include "Scene.h"

SpriteComponent::SpriteComponent(Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mTexHeight(64)
	, mTexWidth(64)
	, mTexture(nullptr)
{
	Game::Get().GetScene()->AddSpriteComponent(this);
}

SpriteComponent::~SpriteComponent()
{
	Game::Get().GetScene()->RemoveSpriteComponent(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	Matrix4 scaleMat = Matrix4::CreateScale(
		static_cast<float>(64),
		static_cast<float>(64),
		1.0f
	);
	Matrix4 world = scaleMat * mOwner->GetWorldTransform();
	shader->SetMatrixUniform("uWorldTransform", world);
	glDrawElements(
		GL_TRIANGLES,
		6,
		GL_UNSIGNED_INT,
		nullptr
	);
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}