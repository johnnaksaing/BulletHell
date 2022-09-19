// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "CircleComponent.h"
#include "Source/WeaponComponent.h"

#include <vector>

class Ship : public Actor
{
public:
	Ship(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;
private:
	float m_BulletCooldown;
	float m_SkillCooldown;

	float m_WeaponSwitchedCooldown;
	float m_WeaponSwitchingSpeed;

	SpriteComponent* sc;
	InputComponent* ic;
	CircleComponent* cc;
	std::vector<WeaponComponent*> m_Weapon;
	WeaponComponent* m_CurrentWeapon;
};