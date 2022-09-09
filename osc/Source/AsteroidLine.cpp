#pragma once
#include "AsteroidLine.h"
#include "Actor.h"
#include "Game.h"

AsteroidLine::AsteroidLine(class Game* game, size_t LineCount, Vector2 initialPosition, float initalRotation, Vector2 endPosition, float endRotation)
	: Actor(game),
	m_LineCount(LineCount),
	m_Position(initialPosition),
	m_Rotation(initalRotation),
	m_EndPosition(endPosition),
	m_EndRotation(endRotation),
	m_LerpSpeed(0.f)
{
	m_Astroids.resize(LineCount);
}

AsteroidLine::~AsteroidLine()
{
	GetGame()->RemoveActor(this);
}

void AsteroidLine::UpdateActor(float deltaTime) 
{

	/*
	//근데 이거 맞음?
	if (m_Astroids.size() == m_LineCount)
		return;

	// Is it time to spawn a new enemy?
	mNextEnemy -= deltaTime;
	if (mNextEnemy <= 0.0f)
	{
		new Enemy(GetGame());
		mNextEnemy += EnemyTime;
	}
	*/
}