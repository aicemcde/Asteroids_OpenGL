#include "GameOverSubText.h"
#include "SpriteComponent.h"
#include "Texture.h"
#include "Game.h"

GameOverSub::GameOverSub()
{
	SetPosition(Vector2(0.f, -144.0f));

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this, 300);
	mTexture = std::make_unique<Texture>();

	mTexture->CreateFromText("Enterを押して終了", "Assets/MPLUS1p-Medium.ttf", 72, Vector3(1.0f, 1.0f, 1.0f));
	sc->SetTexture(mTexture.get());

	AddComponent(std::move(sc));

	ComputeWorldTransform();
}

GameOverSub::~GameOverSub()
{

}

void GameOverSub::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_RETURN])
	{
		Game::Get().SetGameRunning(false);
	}
}