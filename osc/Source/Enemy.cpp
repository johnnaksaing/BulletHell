#include "Enemy.h"

Enemy::Enemy(class Game* game)
	: Actor(game)
	, m_Circle(nullptr)
	, mc(nullptr)
	, sc(nullptr)
{
}

Enemy::~Enemy() 
{
	//GetGame()->Remove
}