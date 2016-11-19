#include "Component.h"
#include <iostream>

namespace KIM
{
	Component::Component()
	{
	}
	
	Component::~Component()
	{
	}

	///////////////////////////////////////
	// Velocity
	///////////////////////////////////////
	Velocity::Velocity() { mXVelocity = 0.0f; mYVelocity = 0.0f; mMoving = false; }
	Velocity::~Velocity() { }

	void Velocity::SetXVelocity(float x) { mXVelocity = x; }
	void Velocity::SetYVelocity(float y) { mYVelocity = y; }

	float Velocity::GetXVelocity() const { return mXVelocity; }
	float Velocity::GetYVelocity() const { return mYVelocity; }

	///////////////////////////////////////
	// KEYBOARD, NOT MUCH HERE!
	///////////////////////////////////////
	Keyboard::Keyboard() { }
	Keyboard::~Keyboard() { }
	sf::Keyboard& Keyboard::GetKeyboard() { return mKeyboard; }

	///////////////////////////////////////
	// HEALTH
	///////////////////////////////////////
	void Health::SetCurrentHealth(int h) { mCurrentHealth = h; }
	void Health::SetMaxHealth(int h) { mMaxHealth = h; }
	void Health::SetAlive(bool alive) { mAlive = alive; }

	bool Health::GetAlive() const { return mAlive; }
	int Health::GetCurrentHealth() const { return mCurrentHealth; }
	int Health::GetMaxHealth() const { return mMaxHealth; }

	///////////////////////////////////////
	// SPRITE
	///////////////////////////////////////
	void Sprite::SetSpriteNTexture(std::string filename)
	{
		// Fix better error handling.
		if (!mTexture.loadFromFile(filename))
		{
			std::cerr << "Couldn't load file " << filename << "!\n";
			exit(0);
		}
		mSprite.setTexture(mTexture);
	}

	sf::Sprite& Sprite::GetSprite() { return mSprite; }
	sf::Texture& Sprite::GetTexture() { return mTexture; }
}