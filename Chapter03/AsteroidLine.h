#pragma once
#include "Actor.h"
#include "Asteroid.h"
#include <vector>
class AsteroidLine : public Actor
{
public:
	AsteroidLine(class Game* game);
	~AsteroidLine();

	class CircleComponent* GetCircle() { return mCircle; }
private:
	class CircleComponent* mCircle;

	std::vector<class Asteroid*> m_Asteroids;
};
