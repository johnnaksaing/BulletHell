#pragma once
#include <vector>
#include "../Math.h"

// 이거 그냥 game 상속받아서 클래스 리스트만 만들면 되나?
// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Private/Level.cpp

// XMLize level
// https://www.youtube.com/watch?v=wEXuNNKG9xw&ab_channel=AtherOmar
class Level 
{
public:
	Level(class Game* game);
	~Level();

	//virtual void AddActor(class Actor* AddingActor) = 0;
	std::vector<class Actor*> GetActors() const { return m_Actors; };
	void Update(float deltaTime);
private:
	class Game* m_Game;

	std::vector<class Actor*> m_Actors;
	std::vector<std::pair<float, class Actor*>> m_ActorSpawner;
	size_t m_spwnerIdx;
	Vector2 m_playerStart;

	std::vector<class BGActor*> m_background;

	int stageCount;
	
	class Player* m_PlayerCharacter;

	float m_LevelTimer;
	float m_spawnTimerMax;
	
	class XML* m_RawData;
};