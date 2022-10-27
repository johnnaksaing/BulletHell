#pragma once
#include <string>
#include <unordered_map>
#include "../Math.h"
//#include "SDL/SDL_ttf.h"
//https://infoarts.tistory.com/59

class Font 
{
public:
	Font();
	~Font();

	//���Ϸκ��� ��Ʈ�� �ε�/��ε�
	bool Load(const std::string& fileName);
	void UnLoad();

	//�ش� ��Ʈ�� ���ڿ��� �ؽ��Ŀ� �׸���
	class Texture* RenderText(
		const std::string& text,
		const Vector3& color = Color::White,
		int pointSize = 30
	);

private:
	std::unordered_map<int, class TTF_Font*> m_FontData;

};
