// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* game)
	:Actor(game)
	,mCircle(nullptr)
{
	// Initialize to random position/orientation
	Vector2 randPos = Random::GetVector(
		Vector2::Zero, Vector2(game->screenX, game->screenY * .25f)//,Vector2::Zero,512.0f,384
		//Vector2(1024.0f, 768.0f));
	);
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	// Create a sprite component
	sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));

	// Create a move component, and set a forward speed
	mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	// Add to mAsteroids in game
	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	//Level로 고쳐야겠지?
	GetGame()->RemoveAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime) 
{
	Vector2 pos = this->GetPosition();
	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f - 10.f)
	{
		//pos.x = 1022.0f; 
		this->SetRotation(0.5 * Math::TwoPi - this->GetRotation());
		pos.x += 15.f;
	}
	else if (pos.x > GetGame()->screenX + 10.f)
	{
		this->SetRotation(0.5 * Math::TwoPi - this->GetRotation());
		pos.x -= 15.f;
	}

	if (pos.y < 0.0f - 10.f)
	{
		this->SetRotation(-this->GetRotation());

		pos.y += 15.f;
	}
	else if (pos.y > GetGame()->screenY + 10.f)
	{
		this->SetRotation(-this->GetRotation());

		pos.y -= 15.f;
	}
	this->SetPosition(pos);
}