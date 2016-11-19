#ifndef GAME_H
#define GAME_H

#include "WindowManager.h"
#include "EntityManager.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Init();
	void Update();
	void SplashScreen();
	void DisplayMenu();
};

#endif