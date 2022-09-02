#include "WeaponComponent.h"
#include "../Laser.h"

void WeaponComponent::Fire() 
{
	float rot = mOwner->GetRotation();
	Vector2 pos = mOwner->GetPosition();
	Vector2 rht = mOwner->GetRight();

	// Create a laser and set its position/rotation to mine
	Laser* laser = new Laser(mOwner->GetGame());//(mOwner->GetGame());
	laser->SetPosition(pos - rht * 8.f);
	laser->SetRotation(rot);

	laser = new Laser(mOwner->GetGame());//(mOwner->GetGame());
	laser->SetPosition(pos + rht * 8.f);
	laser->SetRotation(rot);

}