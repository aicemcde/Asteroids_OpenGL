#pragma once
#include "Actor.h"

class Laser : public Actor
{
public:
	Laser();

	void UpdateActor(float deltaTime);
private:
	class CircleComponent* mCircle;
	float mDeathTimer;
};