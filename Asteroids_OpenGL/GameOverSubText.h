#pragma once
#include "Actor.h"

class GameOverSub : public Actor
{
public:
	GameOverSub();
	~GameOverSub();

	void ActorInput(const uint8_t* keyState) override;
private:
	std::unique_ptr<class Texture> mTexture = nullptr;
};