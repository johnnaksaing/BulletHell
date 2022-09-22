#pragma once
#include <vector>


// 이거 그냥 game 상속받아서 클래스 리스트만 만들면 되나?
// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Private/Level.cpp
class Level 
{
public:
	Level(class Game* game);
	~Level();

	void AddActor(class Actor* AddingActor);
	std::vector<class Actor*> GetActors() const; 
	void Update(float deltaTime);
private:
	std::vector<class Actor*> m_Actors;
	std::vector<std::pair<float, class Actor*>> m_ActorSpawner;

	Vector2 m_playerStart;

	class Tile** m_Tiles;
};