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

	//파일로부터 폰트를 로드/언로드
	bool Load(const std::string& fileName);
	void UnLoad();

	//해당 폰트와 문자열로 텍스쳐에 그리기
	class Texture* RenderText(
		const std::string& text,
		const Vector3& color = Color::White,
		int pointSize = 30
	);

private:
	std::unordered_map<int, class TTF_Font*> m_FontData;

};
