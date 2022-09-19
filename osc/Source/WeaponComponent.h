#pragma once
#include "../Component.h"
#include "../Actor.h"
#include "../Math.h"
//#include "Component.h"

#include "../Laser.h"

#include <iostream>
class WeaponComponent : public Component
{
	/*
	enum class E_WeaponType { e_Rifle, e_Pistol, e_Cannon, e_Flame, e_Chakram };
	enum class E_SkillType { e_Moonshot, e_Onslaught, e_Eclipse, e_Duskwave, e_Sentry};

	E_WeaponType m_WeaponType;
	*/
	float m_WeaponCooldownTime;
	float m_SkillCooldown;
	Vector2 m_Offset;

public:
	//static float m_WeaponSwitchingCooldownTime;
	WeaponComponent(class Actor* owner) : Component(owner), m_WeaponCooldownTime(0.f), m_SkillCooldown(0.f), m_Offset(Vector2::Zero/*owner->GetForward() * 30.f*/)
	{
		//std::cout << mOffset.x << ' ' << mOffset.y << '\n';
	}
	

	virtual void Fire() = 0;
	virtual void Skill() = 0;

	float GetSkillCooldown() const { return m_SkillCooldown; }
	void SetSkilCooldown(float time) { m_SkillCooldown = time; }

	float GetCurrentCooldown() const { return m_WeaponCooldownTime; }
	void SetCurrentCooldown(float CooldownTime) { m_WeaponCooldownTime = CooldownTime; }

	Vector2 GetOffset() const { return m_Offset; }
	void SetOffset(const Vector2& offset) { m_Offset = offset; }
};

// why cant i access this in other files? should i use wpc.cpp?
//float WeaponComponent::m_WeaponSwitchingCooldownTime = 0.7f;