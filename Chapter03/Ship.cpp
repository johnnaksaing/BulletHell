// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Asteroid.h"
#include "Game.h"
#include "Laser.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mLaserCooldown(0.0f)
{
	// Create a sprite component
	sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	// Create an input component and set keys/speed
	ic = new InputComponent(this);

	//TODO : Make GameModeManager? or Input.ini? READ CHAPTER 09 : INPUT
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetClockwiseKey(SDL_SCANCODE_Z);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_C);
	ic->SetLeftKey(SDL_SCANCODE_A);
	ic->SetRightKey(SDL_SCANCODE_D);	
	ic->SetResetRotateKey(SDL_SCANCODE_X);
	ic->SetNormalAttackKey(SDL_SCANCODE_SPACE);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxRightSpeed(300.0f);
	
	ic->SetMaxAngularSpeed(Math::TwoPi);

	cc = new CircleComponent(this);
	cc->SetRadius(5.f);

	wc = new WeaponComponent(this);
	wc->SetCurrentCooldown(0.05f);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown += deltaTime;

	// Do we intersect with an asteroid?
	for (auto ast : GetGame()->GetAsteroids())
	{
		if (Intersect(*cc, *(ast->GetCircle())))
		{
			// The first asteroid we intersect with,
			// set ourselves and the asteroid to dead
			SetState(EDead);
			ast->SetState(EDead);
			break;
		}
	}
}

//TODO : Create WeaponComponent and its derived class "LaserWeaponComponent"
void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[ic->GetNormalAttackKey()] && mLaserCooldown > wc->GetCurrentCooldown() )//mLaserCooldown <= 0.0f)
	{
		// Create a laser and set its position/rotation to mine

		wc->Fire();

		// Reset laser cooldown
		mLaserCooldown = 0.0f;
	}
	//SkillKey
	//SwitchKey
}
