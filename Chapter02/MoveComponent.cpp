#pragma once
#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

void MoveComponent::Update(float deltaTime) 
{
	if (!Math::NearZero(mAngularSpeed)) 
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}
	if (!Math::NearZero(mFowardSpeed)) 
	{
		Vector2 rot = mOwner->GetPosition();
		rot += mOwner->GetForward() * mFowardSpeed * deltaTime;
		mOwner->SetPosition(rot);
	}
}