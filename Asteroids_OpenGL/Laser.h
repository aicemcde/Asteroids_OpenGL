#pragma once
#include "Actor.h"
#include "Math.h"

class Laser : public Actor
{
public:
	Laser(const Vector2& pos, float rot);

	void UpdateActor(float deltaTime);
private:
	class CircleComponent* mCircle;
	float mDeathTimer;
};