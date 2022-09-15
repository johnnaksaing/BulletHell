#pragma once
#include <vector>


// �̰� �׳� game ��ӹ޾Ƽ� Ŭ���� ����Ʈ�� ����� �ǳ�?
// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Private/Level.cpp
class Level 
{
public:
	Level();
	~Level();

	void AddActor(class Actor* AddingActor);
	std::vector<class Actor*> GetActors() const; 

private:
	std::vector<class Actor*> m_Actors;

};