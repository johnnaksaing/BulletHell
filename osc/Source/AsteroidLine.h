#pragma once
#include "Actor.h"
#include "../Asteroid.h"
#include "MoveComponent.h"
#include <vector>
class AsteroidLine : public Actor
{
public:
	AsteroidLine(class Game* game, size_t LineCount, Vector2 initialPosition, float initalRotation, Vector2 endPosition, float endRotation);
	~AsteroidLine();
	
	//void AddAsteroid(class Asteroid* atd) { m_Asteroids.push_back(atd); }
	void UpdateActor(float deltaTime) override;

private:
	size_t m_LineCount;
	std::vector<class Astroid*> m_Astroids;

	//depends on first one..?
	Vector2 m_Position;
	float m_Rotation;

	//destination
	Vector2 m_EndPosition;
	float m_EndRotation;

	//interbal between line members(deltaTime)
	float m_LerpSpeed;
};
