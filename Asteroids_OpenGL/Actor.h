#pragma once
#include <cstdint>
#include "Math.h"
#include <vector>
#include <memory>

class Actor
{
public:

	enum State
	{
		EActive,
		EPouse,
		EDead
	};

	Actor();
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	void ProcessInput(const uint8_t* keyState);
	virtual void ActorInput(const uint8_t* keyState);

	void ComputeWorldTransform();

private:
	State mState;
	float mScale;
	float mRotation;
	Vector2 mPosition;

	//オブジェクト空間からワールド空間への変換に用いる
	Matrix4 mWorldTransform;

	//スケールや回転、座標を変更したら、mWorldTransformをもう一度計算し直す
	bool mRecomputeWorldTransform;

	std::vector<std::unique_ptr<class Component>> mComponents;
};