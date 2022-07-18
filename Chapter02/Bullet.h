#pragma once

#include "Actor.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"

class Bullet : public Actor 
{
public:
	Bullet(class Game* game);
	~Bullet() override;
	void UpdateActor(float deltaTime) override;
private:
	class CircleComponent* mCircle;
};