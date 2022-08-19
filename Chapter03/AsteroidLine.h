#pragma once
#include "Actor.h"
#include "Asteroid.h"
#include <vector>
class AsteroidLine : public Actor
{
public:
	AsteroidLine(class Game* game);
	~AsteroidLine();

private:
	std::vector<class Asteroid*> m_Asteroids;
	size_t m_LineCount;
};
