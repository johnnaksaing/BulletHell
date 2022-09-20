#include "Enemy.h"
#include "Game.h"
#include "../Laser.h"
#include "../SpriteComponent.h"
#include "CircleComponent.h"
#include <vector>

Enemy::Enemy(class Game* game)
	: Actor(game)
	, m_Circle(nullptr)
	, mc(nullptr)
	, sc(nullptr)
	, attackSpeed(0.5f)
	, innerTimer(attackSpeed)
	, hp(30)
	//, m_WeaponOffset(Vector2(0,20))
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

	*/

	// Create a circle component (for collision)
	m_Circle = new CircleComponent(this);
	m_Circle->SetRadius(15.0f);

	//GetGame()->AddEnemy(this);
}

Enemy::~Enemy() 
{
	auto iter = std::find(GetGame()->GetEnemies().begin(),
		GetGame()->GetEnemies().end(), this);
	if (iter != GetGame()->GetEnemies().end())
	{
		GetGame()->GetEnemies().erase(iter);
	}
}

void Enemy::UpdateActor(float deltaTime)
{
	if (GetState() == EDead)
		return;

	innerTimer -= deltaTime;
	if (innerTimer < 0.f) 
	{
		Laser* pew = new Laser(GetGame());
		pew->SetPosition(GetPosition() + GetForward() * 30.f);
		pew->SetRotation(GetRotation());
		innerTimer = attackSpeed;
	}
}

void Enemy::Hit(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		//GetGame()->RemoveActor(this);
		SetState(EDead);
	}
}