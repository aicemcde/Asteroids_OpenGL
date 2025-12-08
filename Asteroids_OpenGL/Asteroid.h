#pragma once
#include "Actor.h"

class Asteroid : public Actor
{
public:
	Asteroid();
	~Asteroid();

	class CircleComponent* GetCircle() { return mCircle; }

private:
	class CircleComponent* mCircle;
};