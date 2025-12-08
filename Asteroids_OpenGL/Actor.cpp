#include "Actor.h"
#include "Component.h"
#include <algorithm>

Actor::Actor()
	:mRecomputeWorldTransform(true)
	,mScale(0.0f)
	,mPosition(Vector2::Zero)
	,mRotation(0.0f)
	,mState(EActive)
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

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		for (auto& comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}
		ActorInput(keyState);
	}
}

void Actor::ActorInput(const uint8_t* keyState)
{

}

void Actor::AddComponent(std::unique_ptr<Component> compnent)
{
	int myOrder = compnent->GetUpdateOrder();
	auto iter = std::ranges::lower_bound(mComponents, myOrder, {}, &Component::GetUpdateOrder);
	if (iter != mComponents.end() && (*iter)->GetUpdateOrder() > myOrder)
	{
		mComponents.emplace(iter, std::move(compnent));
	}
}

void Actor::RemoveComponen(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
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