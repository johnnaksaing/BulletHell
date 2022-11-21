#include "Font.h"
#include "SDL/SDL.h"
//#include "SDL/SDL_ttf.h"
#include <vector>

bool Font::Load(const std::string& fileName) 
{
	std::vector<int> fontSizes
	{
		8,9,10,11,12,14,16,18,20,22,24,26,28,
		30,32,34,36,38,40,42,44,46,48,52,56,
		60,64,68,72
	};

	for (int i = 0; i < fontSizes.size(); i++)
	{
		int size = fontSizes[i];
		//https://stackoverflow.com/questions/51805249/c-error-c2440-initializing-cannot-convert-from-class-name-to-same-class
		//https://github.com/Microsoft/vscode-cpptools/issues/3212
		//TTF_Font* font = TTF_OpenFont(fileName.c_str(),size);
		TTF_Font* font = nullptr;
		if (font == nullptr) 
		{
			SDL_Log("Font Log Failed to load font %s in size %d", fileName.c_str(),size);
			return false;
		}

		m_FontData.emplace(size,font);
	} 

	return true;
}