#pragma once
#include "WeaponComponent.h"
#include "../Laser.h"
#include <iostream>
#include <memory>

class RifleWeaponComponent : public WeaponComponent 
{
public:
	RifleWeaponComponent(class Actor* owner) : WeaponComponent(owner) 
	{
		SetSkilCooldown(0.5f);
	}

	void Fire() override;
	void Skill() override;
};

void RifleWeaponComponent::Fire()
{
	SetOffset( mOwner->GetForward() * 30.f);//m_Offset = 
	float rot = mOwner->GetRotation();
	Vector2 pos = mOwner->GetPosition() + GetOffset();
	Vector2 rht = mOwner->GetRight();

	// Create a laser and set its position/rotation to mine
	Laser* laser = new Laser(mOwner->GetGame());//(mOwner->GetGame());
	laser->SetPosition(pos - rht * 8.f);
	laser->SetRotation(rot);
	
	laser = new Laser(mOwner->GetGame());//(mOwner->GetGame());
	laser->SetPosition(pos + rht * 8.f);
	laser->SetRotation(rot);

	/*
	std::shared_ptr<Laser> pew = std::make_shared<Laser>(mOwner->GetGame());
	pew->SetPosition(pos + rht * 8.f);
	pew->SetRotation(rot);
	*/
}

void RifleWeaponComponent::Skill() 
{
	std::cout << "Rifle\n";
}

