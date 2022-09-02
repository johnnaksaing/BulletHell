// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "MoveComponent.h"
#include <cstdint>

// unreal engine's inputcomponent : https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Classes/Components/InputComponent.h

class InputComponent : public MoveComponent
{
public:
	// Lower update order to update first
	InputComponent(class Actor* owner);

	void ProcessInput(const uint8_t* keyState) override;
	
	// Getters/setters for private variables
	float GetMaxForward() const { return mMaxForwardSpeed; }
	float GetMaxRight() const { return mMaxRightSpeed; }
	float GetMaxAngular() const { return mMaxAngularSpeed; }

	int GetForwardKey() const { return mForwardKey; }
	int GetBackKey() const { return mBackKey; }
	int GetClockwiseKey() const { return mClockwiseKey; }
	int GetCounterClockwiseKey() const { return mCounterClockwiseKey; }
	int GetLeftKey() const { return mLeftKey; }
	int GetRightKey() const { return mRightKey; }
	int GetResetRotateKey() const { return mResetRotateKey; }
	int GetNormalAttackKey() const { return mNormalAttackKey; }

	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	void SetMaxRightSpeed(float speed) { mMaxRightSpeed = speed; }
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	void SetForwardKey(int key) { mForwardKey = key; }
	void SetBackKey(int key) { mBackKey = key; }
	void SetClockwiseKey(int key) { mClockwiseKey = key; }
	void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }

	void SetLeftKey(int key) { mLeftKey = key; }
	void SetRightKey(int key) { mRightKey = key; }

	void SetResetRotateKey(int key) { mResetRotateKey = key; }
	void SetNormalAttackKey(int key) { mNormalAttackKey = key; }
private:
	// The maximum forward/angular speeds
	float mMaxForwardSpeed;
	float mMaxRightSpeed;
	float mMaxAngularSpeed;
	// Keys for forward/back movement
	int mForwardKey;
	int mBackKey;
	// Keys for angular movement
	int mClockwiseKey;
	int mCounterClockwiseKey;
	// Keys for left/right movement
	int mLeftKey;
	int mRightKey;
	// Key for Reset Rotation
	int mResetRotateKey;

	// Key for Normal Attack 
	int mNormalAttackKey;
};
