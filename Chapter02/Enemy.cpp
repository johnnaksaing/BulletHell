#pragma once
#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Enemy::Enemy(Game* game) 
	:Actor(game)
	,mRightSpeed(0.f)
	,mDownSpeed(0.f)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Enemy01.png"),
		game->GetTexture("Assets/Enemy02.png"),
		game->GetTexture("Assets/Enemy03.png"),
		game->GetTexture("Assets/Enemy04.png"),
		game->GetTexture("Assets/Enemy05.png"),
		game->GetTexture("Assets/Enemy06.png")
	};
	asc->SetAnimTextures(anims);
}

void Enemy::UpdateActor(float deltaTime) 
{
	Actor::UpdateActor(deltaTime);

	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	const static float fRightThreshold = 25.f;
	const static float fLeftThreshold = 970.f;
	// Restrict position to screen
	if (pos.x < fRightThreshold)
	{
		pos.x = fRightThreshold;
	}
	else if (pos.x > fLeftThreshold)
	{
		pos.x = fLeftThreshold;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

void Enemy::ActorInput(const uint8_t* keyState) 
{

}