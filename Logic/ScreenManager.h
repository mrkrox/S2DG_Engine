#pragma once
#include "screen.h"
#include "IGraphics.h"
#include <vector>
#include <string>
#include <list>

class ScreenManager
{	
public:		
	ScreenManager(void);
	~ScreenManager(void);
	void AddScreen(Screen*);
	int GetScreenNumber();
	Screen* GetScreen(int);
	void GotoScreen(std::string, std::string);
	void Init(std::string msg);
	void GoBack(std::string msg);
	void Update(GameInputEvent*, int); //check if there's a GameTime type instead of using int
	void Draw(IGraphics*, int); //Same as above	
	void CleanUp();

	Screen *active_screen;	
private:
	bool _started;	
	Screen *_previous;
	std::vector<Screen*> _screens;

};

