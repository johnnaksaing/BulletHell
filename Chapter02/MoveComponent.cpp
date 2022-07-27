#pragma once
#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	: Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
{

}
void MoveComponent::Update(float deltaTime) 
{
	if (!Math::NearZero(mAngularSpeed)) 
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}
	if (!Math::NearZero(mForwardSpeed)) 
	{
		Vector2 rot = mOwner->GetPosition();
		rot += mOwner->GetForward() * mForwardSpeed * deltaTime;
		mOwner->SetPosition(rot);
	}
}