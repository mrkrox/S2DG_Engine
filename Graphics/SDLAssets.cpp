#pragma once
#include "SDLAssets.h"

const unsigned char R = 0;
const unsigned char G = 0xFF;
const unsigned char B = 0xFF;

std::map<std::string, SDL_Surface*> _textures;
std::map<std::string, TTF_Font*> _fonts;


SDLAssets::SDLAssets(void)
{	
}


SDLAssets::~SDLAssets(void)
{
}

TTF_Font* SDLAssets::GetFont(std::string name)
{
	return _fonts[name];
}

SDL_Surface* SDLAssets::GetTexture(std::string name)
{
	return _textures[name];
}

bool SDLAssets::LoadFont(std::string fontName, int size)
{
	
	TTF_Font* font = TTF_OpenFont(fontName.c_str(), size);

	if (font == NULL)
		return false;

	_fonts[fontName] = font;
	return true;
}

bool SDLAssets::LoadTexture(std::string textureName)
{			
	SDL_Surface* loadedImage = IMG_Load(textureName.c_str());
	if (loadedImage == NULL)
	{
		//std::string error = IMG_GetError();
		return false;
	}

	SDL_Surface* texture = SDL_DisplayFormat(loadedImage);
	SDL_FreeSurface(loadedImage);

	//If the image was optimized just fine 
	if( texture == NULL ) 
		return false;

	//Map the color key 
	Uint32 colorkey = SDL_MapRGB(texture->format, R, G, B);
	//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent 
	SDL_SetColorKey( texture, SDL_SRCCOLORKEY, colorkey );

	//_textures.push_back(texture);
	_textures[textureName] = texture;
	
	return true;
}

void SDLAssets::CleanUp()
{
	//Close the fonts used 
	std::map<std::string, TTF_Font*>::iterator it;
	for ( it=_fonts.begin() ; it != _fonts.end(); it++ )
	{
		TTF_CloseFont((*it).second);
	}

	std::map<std::string, SDL_Surface*>::iterator it2;
	for ( it2=_textures.begin() ; it2 != _textures.end(); it2++ )
	{
		if ( it2->second != NULL)
			SDL_FreeSurface(it2->second);
	}
}
