#pragma once
#include <string>
#include <unordered_map>
#include "../Math.h"
#include "SDL/SDL_ttf.h"
#include "Game.h"
//https://infoarts.tistory.com/59

class Font 
{
public:
	Font(class Game* game);
	~Font();

	//���Ϸκ��� ��Ʈ�� �ε�/��ε�
	bool Load(const std::string& fileName);
	void Unload();

	//�ش� ��Ʈ�� ���ڿ��� �ؽ��Ŀ� �׸���
	class Texture* RenderText(
		const std::string& text,
		const Vector3& color = Color::White,
		int pointSize = 30
	);

private:
	std::unordered_map<int, TTF_Font*> m_FontData;
	class Game* m_Game;
};
