#include "Game.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
Game::Game() { }
Game::~Game() { }

////////////////////////////////////////////////////////////
/// \brief Currently a test function.
///
////////////////////////////////////////////////////////////
void Game::Run()
{
	Init();
	sf::Clock clock;
	sf::Text text;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(12);
	text.setPosition(10, 10);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::White);
	
	float lastTime = 0.0f;
	while (WindowManager::GetInstance().GetWindow().isOpen())
	{
		Update();
		while (WindowManager::GetInstance().GetWindow().pollEvent(WindowManager::GetInstance().GetEvent()))
		{
			if (WindowManager::GetInstance().GetEvent().type == sf::Event::Closed)
				WindowManager::GetInstance().GetWindow().close();
		}

		WindowManager::GetInstance().GetWindow().clear(sf::Color::Black);

		for (unsigned int i = 0; i < EntityManager::GetInstance().GetEntities().size(); i++)
		{
			WindowManager::GetInstance().GetWindow().draw(EntityManager::GetInstance().GetEntities()[i]->FetchComponent<KIM::Sprite>()->GetSprite());
		}
		
		EntityManager::GetInstance().Update();
		//float currentTime = clock.restart().asSeconds();
		//float fps = 1.0f / currentTime;
		//lastTime = currentTime;
		//text.setString("FPS: "+ std::to_string(fps));
		//WindowManager::GetInstance().GetWindow().draw(text);
		WindowManager::GetInstance().GetWindow().display();
	}
}

void Game::Init()
{
	// Show the Splashscreen.
	SplashScreen();

	// Show the menu.
	DisplayMenu();
	std::srand((unsigned int)std::time(NULL));
	EntityManager::GetInstance().AddEntity(&Player::GetInstance());

	//for (unsigned int i = 0; i < 100; i++)
	//	EntityManager::GetInstance().TestSpawn(32);

}

void Game::Update()
{
	int tempCount = 0;
	for (unsigned int i = 0; i < EntityManager::GetInstance().GetEntities().size(); i++)
	{
		if (EntityManager::GetInstance().GetEntities()[i]->GetEntityType() == 2)
			tempCount++;
	}
	if (tempCount <= 200)
	{
		EntityManager::GetInstance().TestSpawn(32);
	}
	else
	{
		tempCount = 0;
	}
}

void Game::SplashScreen()
{

}

void Game::DisplayMenu()
{

}