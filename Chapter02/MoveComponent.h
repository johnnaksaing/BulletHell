#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetFowardSpeed() const { return mForwardSpeed; }

	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetFowardSpeed(float speed) { mForwardSpeed = speed; }

private:
	//rad/s
	float mAngularSpeed;

	//unit/s
	float mForwardSpeed;
};