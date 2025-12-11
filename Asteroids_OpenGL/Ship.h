#pragma once
#include "Actor.h"

class Ship : public Actor
{
public:
	Ship();
	~Ship();

	void ActorInput(const uint8_t* keyState) override;
	void UpdateActor(float deltaTime) override;
private:
	float mLaserCooldown;
};