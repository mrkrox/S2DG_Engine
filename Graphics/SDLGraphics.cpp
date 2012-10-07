#pragma once
#include "SDLGraphics.h"


SDLGraphics::SDLGraphics(void)
{
	_assets = new SDLAssets();
}


SDLGraphics::~SDLGraphics(void)
{
}

int SDLGraphics::CreateGameSurface(const int width, const int height , const int bitsPerPixel)
{
	//Initialize SDL_ttf 
	if( TTF_Init() == -1 ) 
	{ 
		return -1;
	}

	//Start SDL - returns negative if Init failed.
	int result = SDL_Init(SDL_INIT_EVERYTHING); 

	if (result < 0)
	{
		Shutdown();
		return -1;
	}

	_main_surface = SDL_SetVideoMode(width, height, bitsPerPixel, SDL_SWSURFACE );	

	if (_main_surface == NULL) 
	{
		Shutdown();
		return -1;
	}

	return 0;
}
	
void SDLGraphics::Shutdown()
{
	SDL_FreeSurface(_main_surface);
	_assets->CleanUp();
	TTF_Quit(); 
	//Quit SDL 
	SDL_Quit(); 
}
	
void SDLGraphics::UpdateScreen()
{
	SDL_Flip(_main_surface);
}

void SDLGraphics::FreeSurface(std::string surfaceName)
{	
	//SDL_FreeSurface(_assets->_texures[surfaceName]);
	//delete _assets->_texures[surfaceName]
}

void SDLGraphics::LoadSurface(std::string surfaceName)
{
	_assets->LoadTexture(surfaceName);
}
	
void SDLGraphics::LoadFont(std::string fontName, int size)
{
	_assets->LoadFont(fontName, size);
}
	
void SDLGraphics::FreeFont(std::string fontName)
{
	TTF_CloseFont(_assets->GetFont(fontName));
}

void SDLGraphics::DrawSurface(std::string surfaceName, Vector2 position)
{
	SDL_Rect offset;
	offset.x = (Sint16) position.x;
	offset.y = (Sint16) position.y;
	SDL_BlitSurface(_assets->GetTexture(surfaceName), NULL,_main_surface , &offset);
}
	
void SDLGraphics::DrawSurface(Rectangle srcRect, std::string surfaceName, Vector2 position)
{
	SDL_Rect offset;
	offset.x = (Sint16) position.x;
	offset.y = (Sint16) position.y;

	SDL_Rect sourceRect;
	sourceRect.x = (Sint16) srcRect.coordinates.x;
	sourceRect.y = (Sint16) srcRect.coordinates.y;
	sourceRect.w = srcRect.width;
	sourceRect.h = srcRect.height;

	SDL_BlitSurface(_assets->GetTexture(surfaceName), &sourceRect, _main_surface, &offset);
}

void SDLGraphics::DrawFont(std::string fontName, std::string text, int r, int g ,int b, Vector2 pos)
{
	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	SDL_Rect offset;
	offset.x = (Sint16) pos.x;
	offset.y = (Sint16) pos.y;

	SDL_Surface* textDrawn = TTF_RenderText_Solid(_assets->GetFont(fontName),text.c_str(), color);
	SDL_BlitSurface(textDrawn, NULL, _main_surface , &offset);
}
