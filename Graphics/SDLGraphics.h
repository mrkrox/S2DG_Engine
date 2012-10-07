#pragma once
#include "IGraphics.h"
#include "SDLAssets.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

class SDLGraphics :
	public IGraphics
{
public:
	SDLGraphics(void);
	~SDLGraphics(void);

	int CreateGameSurface(const int, const int, const int);
	void Shutdown();
	void UpdateScreen();
	void FreeSurface(std::string);
	void LoadSurface(std::string);
	void LoadFont(std::string, int);
	void FreeFont(std::string);
	void DrawSurface(std::string, Vector2);
	void DrawSurface(Rectangle, std::string, Vector2);
	void DrawFont(std::string, std::string, int,int,int, Vector2);
private:
	SDL_Surface* _main_surface;
	SDLAssets* _assets;
};

