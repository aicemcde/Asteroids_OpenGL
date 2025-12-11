#pragma once
#include "MoveComponent.h"

class InputComponent : public MoveComponent
{
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const uint8_t* keyState) override;

	float GetMaxForwardSpeed() const { return mMaxForwardSpeed; }
	float GetMaxAngularSpeed() const { return mMaxAngularSpeed; }
	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	void SetForwardKey(const int key) { mForwardKey = key; }
	void SetBackKey(const int key) { mBackKey = key; }
	void SetClockwiseKey(const int key) { mClockwiseKey = key; }
	void SetCounterClockwiseKey(const int key) { mCounterClockwiseKey = key; }
private:
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;
	int mForwardKey;
	int mBackKey;
	int mClockwiseKey;
	int mCounterClockwiseKey;
};