#pragma once
#include "Actor.h"

class GameOver : public Actor
{
public:
	GameOver();
	~GameOver();

private:
	std::unique_ptr<class Texture> mTexture;
};