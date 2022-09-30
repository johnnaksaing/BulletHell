#pragma once
#include "Level.h"
#include "Game.h"
#include <vector>
#include <algorithm>
Level::Level(Game* game) :
	m_Game(game),
	m_spwnerIdx(0)
{
	//테스트 시 여기에 spwanwer 등록
	std::sort(m_ActorSpawner.begin(), m_ActorSpawner.end());
}

Level::~Level() 
{
	//m_Game->GetLevel().Remove(this);
}

void Level::Update(float deltaTime) 
{
	m_LevelTimer += deltaTime;
	while (m_LevelTimer < m_ActorSpawner[m_spwnerIdx].first)
	{
		//이거 작동안하는 의사코드임. 여기서 new로 생성시켜줘야 한다.
		m_Game->AddActor(m_ActorSpawner[m_spwnerIdx].second);
		m_spwnerIdx++;
	}
}