#pragma once
#include <vector>
#include "../Math.h"

// �̰� �׳� game ��ӹ޾Ƽ� Ŭ���� ����Ʈ�� ����� �ǳ�?
// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Private/Level.cpp
class Level 
{
public:
	Level(class Game* game);
	~Level();

	void AddActor(class Actor* AddingActor);
	std::vector<class Actor*> GetActors() const { return m_Actors; };
	void Update(float deltaTime);
private:
	class Game* m_Game;

	std::vector<class Actor*> m_Actors;
	std::vector<std::pair<float, class Actor*>> m_ActorSpawner;

	Vector2 m_playerStart;

	class Tile** m_Tiles;
};