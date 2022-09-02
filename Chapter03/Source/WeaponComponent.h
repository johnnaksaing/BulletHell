#pragma once
#include "../Component.h"
//#include "Component.h"
#include <iostream>
class WeaponComponent : public Component
{
	enum class E_WeaponType { e_Rifle, e_Pistol, e_Cannon, e_Flame, e_Chakram };
	enum class E_SkillType { e_Moonshot, e_Onslaught, e_Eclipse, e_Duskwave, e_Sentry};

	E_WeaponType m_WeaponType;
	float m_WeaponCooldownTime;
public:
	WeaponComponent(class Actor* owner) : Component(owner),m_WeaponCooldownTime(0.f) {}
	

	void Fire();

	float GetCurrentCooldown() const { return m_WeaponCooldownTime; }
	void SetCurrentCooldown(float CooldownTime) { m_WeaponCooldownTime = CooldownTime; }
};