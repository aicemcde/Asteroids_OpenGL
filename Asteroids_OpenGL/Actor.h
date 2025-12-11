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

	State GetState() const { return mState; }
	Matrix4 GetWorldTransform() const { return mWorldTransform; }

	float GetRotation() const { return mRotation; }
	void SetRotation(float rot) { mRotation = rot; mRecomputeWorldTransform = true; }
	Vector2 GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; mRecomputeWorldTransform = true; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; mRecomputeWorldTransform = true; }
	void SetState(const State& state) { mState = state; }

	Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), Math::Sin(mRotation)); }

	void AddComponent(std::unique_ptr<class Component> component);
	void RemoveComponent(class Component* component);
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