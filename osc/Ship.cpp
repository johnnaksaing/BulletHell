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

#include "Source/RifleWeaponComponent.h"

Ship::Ship(Game* game)
	:Actor(game)
	, m_BulletCooldown(0.0f)
	, m_SkillCooldown(0.0f)
{
	// Create a sprite component
	sc = new SpriteComponent(this, 150);
	//sc->SetTexture(game->GetTexture("Assets/Ship.png"));
	sc->SetTexture(game->GetTexture("Assets/OSC_1.png"));

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
	ic->SetSkillUsingKey(SDL_SCANCODE_Q);
	ic->SetWeaponSwitchingKey(SDL_SCANCODE_E);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxRightSpeed(300.0f);
	
	ic->SetMaxAngularSpeed(Math::TwoPi);

	cc = new CircleComponent(this);
	cc->SetRadius(5.f);

	m_Weapon = { new RifleWeaponComponent(this) };
	m_Weapon[0]->SetCurrentCooldown(0.05f);

	m_CurrentWeapon = m_Weapon[0];
}

void Ship::UpdateActor(float deltaTime)
{
	m_BulletCooldown += deltaTime;
	m_SkillCooldown += deltaTime;

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
	if (keyState[ic->GetNormalAttackKey()] && m_BulletCooldown > m_CurrentWeapon->GetCurrentCooldown() )//mLaserCooldown <= 0.0f)
	{
		// Create a laser and set its position/rotation to mine

		m_CurrentWeapon->Fire();

		// Reset laser cooldown
		m_BulletCooldown = 0.0f;
	}

	//SkillKey
	if (keyState[ic->GetSkillUsingKey()] && m_SkillCooldown > m_CurrentWeapon->GetSkillCooldown())
	{
		//std::cout << "Not Implemented Yet...\n";
		m_CurrentWeapon->Skill();

		m_SkillCooldown = 0.0f;
	}
	//SwitchKey
	if (keyState[ic->GetWeaponSwitchingKey()]) 
	{
		std::cout << "Not Implemented Yet...\n";
	}
}
