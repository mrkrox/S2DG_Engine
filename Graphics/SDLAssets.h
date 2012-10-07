#pragma once
#include <string>
#include <vector>
#include <map>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

class SDLAssets
{
public:
	SDLAssets(void);
	~SDLAssets(void);

	bool LoadFont(std::string,int);
	bool LoadTexture(std::string);
	TTF_Font* GetFont(std::string);
	SDL_Surface* GetTexture(std::string);
	void CleanUp();
};

