#pragma once
#include "Level.h"
#include <vector>
Level::Level(Game* game) :
	m_Game(game),
	m_Tiles(nullptr)
{

}

Level::~Level() 
{
	//m_Game->GetLevel().Remove(this);
}

void Level::Update(float deltaTime) 
{

}