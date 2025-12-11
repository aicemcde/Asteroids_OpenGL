#include "Asteroid.h"
#include "Random.h"
#include "CircleComponent.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Scene.h"


Asteroid::Asteroid()
	:Actor()
	, mCircle(nullptr)
{
	Vector2 randPos = Random::GetVector(Vector2(-512.0f, -384.0f),
		Vector2(512.0f, 384.0f));
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this);
	sc->SetTexture(Game::Get().GetResourceManager()->GetTexture("Assets/Asteroid.png"));
	AddComponent(std::move(sc));

	std::unique_ptr<MoveComponent> mc = std::make_unique<MoveComponent>(this);
	mc->SetForwardSpeed(150.0f);
	AddComponent(std::move(mc));

	std::unique_ptr<CircleComponent> cc = std::make_unique<CircleComponent>(this);
	mCircle = cc.get();
	mCircle->SetRadius(40.0f);
	AddComponent(std::move(cc));
	
	Game::Get().GetScene()->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	Game::Get().GetScene()->RemoveAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime)
{
	Vector2 pos = GetPosition();
	if (pos.x < -562.0f || pos.x > 562.0f || pos.y < -434.0f || pos.y > 434.0f)
	{
		SetState(EDead);
	}
}