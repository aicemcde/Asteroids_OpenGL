#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "ResourceManager.h"
#include "Laser.h"
#include "Scene.h"
#include "CircleComponent.h"
#include "Asteroid.h"
#include "GameOver.h"
#include "GameOverSubText.h"

Ship::Ship()
	:Actor()
	, mLaserCooldown(0.0f)
{

	std::unique_ptr<SpriteComponent> sc = std::make_unique<SpriteComponent>(this, 150);
	mShipTex = Game::Get().GetResourceManager()->GetTexture("Assets/Ship.png");
	mThrustTex = Game::Get().GetResourceManager()->GetTexture("Assets/ShipWithThrust.png");
	sc->SetTexture(mShipTex);
	mSprite = sc.get();
	AddComponent(std::move(sc));

	std::unique_ptr<InputComponent>ic = std::make_unique<InputComponent>(this);
	ic->SetMaxForwardSpeed(200.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi / 2.0f);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetClockwiseKey(SDL_SCANCODE_D);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_A);
	AddComponent(std::move(ic));

	std::unique_ptr<CircleComponent> cc = std::make_unique<CircleComponent>(this);
	cc->SetRadius(32.0f);
	mCircle = cc.get();
	AddComponent(std::move(cc));

	ComputeWorldTransform();
}

Ship::~Ship()
{

}

void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0)
	{
		std::unique_ptr<Laser> laser = std::make_unique<Laser>(GetPosition(), GetRotation());
		mLaserCooldown = 0.5f;
		Game::Get().GetScene()->AddActor(std::move(laser));
	}

	if (keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_S] || keyState[SDL_SCANCODE_D])
	{
		mSprite->SetTexture(mThrustTex);
	}
	else
	{
		mSprite->SetTexture(mShipTex);
	}
}

void Ship::UpdateActor(float deltaTime)
{
	if (mLaserCooldown > 0)
	{
		mLaserCooldown -= deltaTime;
	}

	Vector2 pos = GetPosition();
	if (pos.x < -480.0f)
	{
		pos.x = -480.0f;
	}
	if (pos.x > 480.0f)
	{
		pos.x = 480.0f;
	}
	if (pos.y < -352.0f)
	{
		pos.y = -352.0f;
	}
	if (pos.y > 352.0f)
	{
		pos.y = 352.0f;
	}
	SetPosition(pos);

	for (auto ast : Game::Get().GetScene()->GetAsteroids())
	{
		if (Intersect(*mCircle, *(ast->GetCircle())))
		{
			SetState(EDead);
			ast->SetState(EDead);
			std::unique_ptr<GameOver> go = std::make_unique<GameOver>();
			std::unique_ptr<GameOverSub> gos = std::make_unique<GameOverSub>();
			Game::Get().GetScene()->AddActor(std::move(gos));
			Game::Get().GetScene()->AddActor(std::move(go));
			break;
		}
	}
}