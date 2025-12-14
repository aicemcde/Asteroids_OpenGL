#include "Score.h"
#include "SpriteComponent.h"
#include "Texture.h"

Score::Score()
{
	SetPosition(Vector2(350.0f, 350.0f));

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this, 300);
	mTexture = std::make_unique<Texture>();

	std::string scoreText = "Score : " + std::to_string(mScore);

	mTexture->CreateFromText(scoreText, "Assets/MPLUSCodeLatin-Bold.ttf", 60, Vector3(1.0f, 1.0f, 1.0f));
	sc->SetTexture(mTexture.get());

	AddComponent(std::move(sc));

	ComputeWorldTransform();
}

Score::~Score()
{

}

void Score::AddScore()
{
	mScore += 100;
	std::string scoreText = "Score : " + std::to_string(mScore);
	mTexture->CreateFromText(scoreText, "Assets/MPLUSCodeLatin-Bold.ttf", 72, Vector3(1.0f, 1.0f, 1.0f));
}