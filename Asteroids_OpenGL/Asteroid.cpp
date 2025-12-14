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
	const float rangeX = 600.0f;
	const float rangeY = 450.0f;

	Vector2 startPos;

	int edge = Random::GetIntRange(0, 3);

	switch (edge)
	{
	case 0:
		startPos.x = -rangeX;
		startPos.y = Random::GetFloatRange(-rangeY, rangeY);
		break;
	case 1:
		startPos.x = rangeX;
		startPos.y = Random::GetFloatRange(-rangeY, rangeY);
		break;
	case 2:
		startPos.x = Random::GetFloatRange(-rangeX, rangeX);
		startPos.y = rangeY;
		break;
	case 3:
		startPos.x = Random::GetFloatRange(-rangeX, rangeX);
		startPos.y = -rangeY;
		break;
	default:
		break;
	}
	
	SetPosition(startPos);

	Vector2 targetPos = Vector2(Random::GetFloatRange(-100.0f, 100.0f), Random::GetFloatRange(-100.0f, 100.0f));

	Vector2 dir = targetPos - startPos;
	dir.Normalize();

	SetRotation(Math::Atan2(dir.y, dir.x));

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this);
	sc->SetTexture(Game::Get().GetResourceManager()->GetTexture("Assets/Asteroid.png"));
	AddComponent(std::move(sc));

	std::unique_ptr<MoveComponent> mc = std::make_unique<MoveComponent>(this);
	mc->SetForwardSpeed(150.0f);
	AddComponent(std::move(mc));

	std::unique_ptr<CircleComponent> cc = std::make_unique<CircleComponent>(this);
	mCircle = cc.get();
	mCircle->SetRadius(32.0f);
	AddComponent(std::move(cc));
	
	Game::Get().GetScene()->AddAsteroid(this);

	ComputeWorldTransform();
}

Asteroid::~Asteroid()
{
	Game::Get().GetScene()->RemoveAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime)
{
	const float deathRangeX = 650.0f;
	const float deathRangeY = 500.0f;
	Vector2 pos = GetPosition();
	if (pos.x < -deathRangeX || pos.x > deathRangeX || pos.y < -deathRangeY || pos.y > deathRangeY)
	{
		SetState(EDead);
	}
}