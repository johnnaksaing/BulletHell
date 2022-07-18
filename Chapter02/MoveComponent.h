#pragma once
#include "Component.h"

class MoveComponent : Component
{
public:
	MoveComponent(class Acotr* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetFowardSpeed() const { return mFowardSpeed; }

	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetFowardSpeed(float speed) { mFowardSpeed = speed; }

private:
	//rad/s
	float mAngularSpeed;

	//unit/s
	float mFowardSpeed;
};