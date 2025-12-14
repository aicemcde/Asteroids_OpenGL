#include "Laser.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "MoveComponent.h"
#include "Asteroid.h"
#include "CircleComponent.h"
#include "ResourceManager.h"
#include "Scene.h"

Laser::Laser(const Vector2& pos, float rot)
	:Actor()
	, mDeathTimer(1.0f)
{
	SetPosition(pos);
	SetRotation(rot);

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this, 200);
	sc->SetTexture(Game::Get().GetResourceManager()->GetTexture("assets/Laser.png"));
	AddComponent(std::move(sc));

	std::unique_ptr<MoveComponent> mc = std::make_unique<MoveComponent>(this);
	mc->SetForwardSpeed(400.0f);
	AddComponent(std::move(mc));

	std::unique_ptr<CircleComponent> cc = std::make_unique<CircleComponent>(this);
	mCircle = cc.get();
	mCircle->SetRadius(8.0f);
	AddComponent(std::move(cc));

	ComputeWorldTransform();
}

void Laser::UpdateActor(float deltaTime)
{
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0)
	{
		SetState(EDead);
	}
	else
	{
		for (auto ast : Game::Get().GetScene()->GetAsteroids())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				Game::Get().ScoreUpdate();
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}