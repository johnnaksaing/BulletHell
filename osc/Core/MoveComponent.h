// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"
#include "Game.h"
#include "Actor.h"
#include "../Math.h"
class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;
	
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	void SetRightSpeed(float speed) { mRightSpeed = speed; }

private:

	const int screenX, screenY;

	// Controls rotation (radians/second)
	float mAngularSpeed;
	// Controls Right movement (units/second)
	float mRightSpeed;
	// Controls forward movement (units/second)
	float mForwardSpeed;

	bool bOutofBounds()
	{
		Vector2 ownerPosition = this->mOwner->GetPosition();

		return !(0 <= ownerPosition.x && 0 <= ownerPosition.y &&
			ownerPosition.x <= this->mOwner->GetGame()->screenX && ownerPosition.y <= this->mOwner->GetGame()->screenY);
	}
};
