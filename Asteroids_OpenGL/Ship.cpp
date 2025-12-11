#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "ResourceManager.h"
#include "Laser.h"
#include "Scene.h"

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

}