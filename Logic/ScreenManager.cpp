#include "ScreenManager.h"


ScreenManager::ScreenManager(void) : _started(false), _previous(NULL), active_screen(NULL)
{
}


ScreenManager::~ScreenManager(void)
{
	for (unsigned int i=0; i < _screens.size(); i++)
	{
		delete &_screens[i];
	}
}

int ScreenManager::GetScreenNumber() 
{
	return _screens.size();
}

Screen* ScreenManager::GetScreen(int nr) 
{
	if (nr > GetScreenNumber())
		return NULL;
	return _screens[nr];
}

void ScreenManager::AddScreen(Screen* screenToAdd) 
{				
	for (unsigned int i=0; i < _screens.size(); i++)
	{
		if (_screens[i]->GetName() == screenToAdd->GetName())
		{
			return;
		}
	}

	_screens.push_back(screenToAdd);
}

void ScreenManager::GotoScreen(std::string name, std::string msg) 
{
	for (unsigned int i=0; i < _screens.size(); i++)
	{
		if (_screens[i]->GetName() == name)
		{
			// Shutsdown Previous Screen           
			_previous = active_screen;
			if (active_screen != NULL)
			{
				active_screen->Shutdown();
			}
			// Inits New Screen
			
			active_screen = _screens[i];
			if (_started)
				active_screen->Init(msg);
			return;
		}
	}
}

void ScreenManager::Init(std::string msg) 
{
	_started = true;
	if (active_screen != NULL)
	{		
		active_screen->Init(msg);
	}
}

void ScreenManager::GoBack(std::string msg)
{
	if (_previous != NULL)
	{
		GotoScreen(_previous->GetName(), msg);
		return;
	}
}

void ScreenManager::Update(GameInputEvent* input, int gameTime)
{
	if (_started == false) 
		return;
	/*if (active_screen != NULL)
	{
		ScreenUpdate result = active_screen->Update(input, gameTime);
		if (result.changeScreen)
		{
			GotoScreen(result.screen, result.msg);
		}
	}*/
}

void ScreenManager::Draw(IGraphics* graphics, int gameTime) 
{
	if (_started == false) 
		return;
	/*if (active_screen != NULL)
	{
		active_screen->Draw(screen, gameTime);
	}*/
}

void ScreenManager::CleanUp() 
{
	for (int i=0; i < _screens.size(); i++) 
	{
		_screens[i]->Shutdown();
		delete _screens[i];
	}
}


