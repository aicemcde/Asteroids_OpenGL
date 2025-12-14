#include "GameOver.h"
#include "SpriteComponent.h"
#include "Texture.h"

GameOver::GameOver()
{
	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this, 300);
	mTexture = std::make_unique<Texture>();

	mTexture->CreateFromText("GAME OVER", "Assets/MPLUSCodeLatin-Bold.ttf", 144, Vector3(1.0f, 0.0f, 0.0f));
	sc->SetTexture(mTexture.get());

	AddComponent(std::move(sc));

	ComputeWorldTransform();
}

GameOver::~GameOver()
{

}