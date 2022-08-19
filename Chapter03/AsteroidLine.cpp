#pragma once
#include "AsteroidLine.h"
#include "Game.h"

AsteroidLine::AsteroidLine(class Game* game) : Actor(game), m_LineCount(5)
{
	m_Asteroids.resize(m_LineCount);
}

AsteroidLine::~AsteroidLine()
{
	GetGame()->RemoveActor(this);
}