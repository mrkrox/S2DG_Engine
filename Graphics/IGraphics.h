#pragma once
#include <string>
#include <vector>
#include "GameMathTypes.h"

class IGraphics
{
public:	
	virtual int CreateGameSurface(const int, const int, const int) = 0;
	virtual void Shutdown() = 0;
	virtual void UpdateScreen() = 0;
	virtual void FreeSurface(std::string) = 0;
	virtual void LoadSurface(std::string) = 0;
	virtual void LoadFont(std::string, int) = 0;
	virtual void FreeFont(std::string) = 0;
	virtual void DrawSurface(std::string, Vector2) = 0;
	virtual void DrawSurface(Rectangle, std::string, Vector2) = 0;
	virtual void DrawFont(std::string, std::string, int,int,int, Vector2) = 0;
};

