#pragma once
#include "../Actor.h"


class Enemy  : public Actor
{
public:
	Enemy(class Game* game);
	virtual ~Enemy();
	
	virtual void UpdateActor(float deltaTime) override {};
	class CircleComponent* GetCircle() { return m_Circle; }
private:
	class CircleComponent* m_Circle;
	class SpriteComponent* sc;
	class MoveComponent* mc;
};