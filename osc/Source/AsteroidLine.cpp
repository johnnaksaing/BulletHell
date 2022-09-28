#pragma once
#include "AsteroidLine.h"
#include "Actor.h"
#include "Game.h"

AsteroidLine::AsteroidLine(class Game* game, size_t LineCount, Vector2 initialPosition, float initalRotation, Vector2 endPosition, float endRotation)
	: Actor(game),
	m_Astroids(),
	m_LineCount(LineCount),
	m_Position(initialPosition),
	m_Rotation(initalRotation),
	m_EndPosition(endPosition),
	m_EndRotation(endRotation),
	m_LerpSpeed(0.5f),
	mNextEnemy(0.5f),
	m_Spawned(0),
	m_MoveSpeed( (endPosition - initialPosition) * m_LerpSpeed ),
	m_RotateSpeed(0.002f)
{
	//m_Astroids.resize(LineCount);

}

AsteroidLine::~AsteroidLine()
{
	GetGame()->RemoveActor(this);
}

void AsteroidLine::UpdateActor(float deltaTime) 
{

	// Is it time to spawn a new enemy?
	mNextEnemy -= deltaTime;
	if (m_Spawned <= m_LineCount && mNextEnemy <= 0.0f)
	{
		m_Astroids.push_back( new Asteroid(GetGame()) );
		m_Astroids.back()->SetPosition(m_Position);
		m_Astroids.back()->SetRotation(m_Rotation);
		m_Spawned++;
		//m_Astroids.emplace_back( GetGame() );
		mNextEnemy += m_LerpSpeed;
	}

	for (int i = 0; i < m_Astroids.size(); i++) 
	{
		Asteroid* ith = m_Astroids[i];
		ith->SetRotation(ith->GetRotation() + m_RotateSpeed);
	}
}