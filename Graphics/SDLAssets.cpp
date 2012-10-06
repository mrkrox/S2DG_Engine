#include "SDLAssets.h"

const unsigned char R = 0;
const unsigned char G = 0xFF;
const unsigned char B = 0xFF;


SDLAssets::SDLAssets(void)
{
}


SDLAssets::~SDLAssets(void)
{
}

bool SDLAssets::LoadFont(std::string fontName, int size)
{
	_fonts[fontName] = TTF_OpenFont(fontName.c_str(), size);

	if (_fonts[fontName] == NULL)
		return false;

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


	if (loadedImage == NULL)
		return false;

	_textures[textureName] = SDL_DisplayFormat(loadedImage);

	SDL_FreeSurface(loadedImage);

	//If the image was optimized just fine 
	if( _textures[textureName] == NULL ) 
		return false;

	//Map the color key 
	Uint32 colorkey = SDL_MapRGB(_textures[textureName]->format, R, G, B);
	//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent 
	SDL_SetColorKey( _textures[textureName], SDL_SRCCOLORKEY, colorkey );
	
	return true;
}

void SDLAssets::CleanUp()
{
	//Close the fonts used 
	
	std::map<std::string,TTF_Font*>::iterator it;
	for ( it=_fonts.begin() ; it != _fonts.end(); it++ )
	{
		TTF_CloseFont((*it).second);
		_fonts.erase(it);
	}

	std::map<std::string,SDL_Surface*>::iterator it2;
	for ( it2=_textures.begin() ; it2 != _textures.end(); it2++ )
	{
		SDL_FreeSurface((*it2).second);
		_textures.erase(it2);
	}
}
