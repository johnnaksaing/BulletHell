#pragma once
#include "Level.h"
#include "Game.h"
#include <vector>
#include <algorithm>
Level::Level(Game* game) :
	m_Game(game),
	m_spwnerIdx(0)
{
	//�׽�Ʈ �� ���⿡ spwanwer ���
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
		//�̰� �۵����ϴ� �ǻ��ڵ���. ���⼭ new�� ����������� �Ѵ�.
		m_Game->AddActor(m_ActorSpawner[m_spwnerIdx].second);
		m_spwnerIdx++;
	}
}