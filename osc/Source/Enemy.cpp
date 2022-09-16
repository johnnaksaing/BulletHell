#include "Enemy.h"
#include "Game.h"
#include "../Laser.h"
#include "../SpriteComponent.h"

Enemy::Enemy(class Game* game)
	: Actor(game)
	, m_Circle(nullptr)
	, mc(nullptr)
	, sc(nullptr)
	, attackSpeed(0.5f)
	,innerTimer(attackSpeed)
{

	SetPosition(Vector2(1024.f * .5f, 300.0f));

	SetRotation(- Math::Pi * .5f);

	// Create a sprite component
	sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Enemy.png"));

	/*
	// Create a move component, and set a forward speed
	mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	*/

	//GetGame()->AddEnemy(this);
}

Enemy::~Enemy() 
{
	//GetGame()->RemoveEnemy(this);
}

void Enemy::UpdateActor(float deltaTime)
{
	innerTimer -= deltaTime;
	if (innerTimer < 0.f) 
	{
		Laser* pew = new Laser(GetGame());
		pew->SetPosition(GetPosition());
		pew->SetRotation(GetRotation());
		innerTimer = attackSpeed;
	}
}