#pragma once
#include "Actor.h"


class Enemy : public Actor
{
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;

	void ActorInput(const uint8_t* keyState) override;

	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
private:
	float mRightSpeed;
	float mDownSpeed;
};