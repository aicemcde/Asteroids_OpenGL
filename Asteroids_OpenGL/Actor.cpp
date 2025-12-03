#include "Actor.h"
#include "Component.h"

Actor::Actor()
	:mRecomputeWorldTransform(true)
	,mScale(0.0f)
	,mPosition(Vector2::Zero)
	,mRotation(0.0f)
{

}

Actor::~Actor()
{

}

void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		ComputeWorldTransform();
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
		ComputeWorldTransform();
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (const auto& comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{

}

void Actor::ComputeWorldTransform()
{
	if (mRecomputeWorldTransform)
	{
		mRecomputeWorldTransform = false;
		mWorldTransform = Matrix4::CreateScale(mScale);
		mWorldTransform *= Matrix4::CreateRotationZ(mRotation);
		mWorldTransform *= Matrix4::CreateTranslation(
			Vector3(mPosition.x, mPosition.y, 0.0f));
	}
}