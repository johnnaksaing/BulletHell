// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
:Component(owner, updateOrder)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
,mRightSpeed(0.0f)
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
	Vector2 pos = mOwner->GetPosition();
	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos_forward;
		pos_forward += mOwner->GetForward() * mForwardSpeed * deltaTime;

		pos += pos_forward;
	}

	if (!Math::NearZero(mRightSpeed)) 
	{
		Vector2 pos_right;
		pos_right += mOwner->GetRight() * mRightSpeed * deltaTime;

		pos += pos_right;
	}

	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f - 10.f) 
	{
		//pos.x = 1022.0f; 
		mOwner->SetRotation(0.5 * Math::TwoPi - mOwner->GetRotation());
		pos.x += 15.f;
	}
	else if (pos.x > 1024.0f + 10.f) 
	{
		mOwner->SetRotation(0.5 * Math::TwoPi - mOwner->GetRotation());
		pos.x -= 15.f;
	}

	if (pos.y < 0.0f - 10.f) 
	{
		mOwner->SetRotation(-mOwner->GetRotation());

		pos.y += 15.;
	}
	else if (pos.y > 768.0f + 10.f)
	{
		mOwner->SetRotation(-mOwner->GetRotation());

		pos.y -= 15.f;
	}

	mOwner->SetPosition(pos);
}
