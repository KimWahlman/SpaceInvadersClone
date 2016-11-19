#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>

class WindowManager
{
	sf::RenderWindow mRenderWindow;
	sf::Event mEvent;

	WindowManager()
	{
		mRenderWindow.create(sf::VideoMode(500, 800), "Test Window!");
		mRenderWindow.setFramerateLimit(70);
	}

public:
	static WindowManager&	GetInstance()
	{
		static WindowManager instance;
		return instance;
	}

	WindowManager(WindowManager const&) = delete;
	WindowManager(WindowManager&&) = delete;
	WindowManager&operator=(WindowManager const&) = delete;
	WindowManager&operator=(WindowManager&&) = delete;

	void SetWindowSize(sf::Vector2u size) { mRenderWindow.setSize(size); }

	sf::RenderWindow& GetWindow() { return mRenderWindow; }
	sf::Event& GetEvent() { return mEvent; }
	sf::Vector2u GetWindowSize() { return mRenderWindow.getSize(); }

protected:
	~WindowManager() { };
};

#endif