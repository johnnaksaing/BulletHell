#pragma once
#include "Actor.h"
#include "Asteroid.h"
#include "MoveComponent.h"
#include <vector>
class AsteroidLine : public Actor
{
public:
	AsteroidLine(class Game* game);
	~AsteroidLine();
	
	void AddAsteroid(class Asteroid* atd) { m_Asteroids.push_back(atd); }
	void UpdateActor(float deltaTime) override {};

private:
	std::vector<class Asteroid*> m_Asteroids;
	size_t m_LineCount;
};
