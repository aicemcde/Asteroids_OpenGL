#pragma once
#include "Actor.h"

class Score : public Actor
{
public:
	Score();
	~Score();

	void AddScore();
private:
	unsigned int mScore = 0;
	std::unique_ptr<class Texture> mTexture = nullptr;
};