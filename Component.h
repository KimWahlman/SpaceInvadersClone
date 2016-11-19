#ifndef COMPONENT_H
#define COMPONENT_H

#include <unordered_map>
#include <string>
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Window\Event.hpp"

namespace KIM
{
	class Component
	{
		unsigned int mGUID;
	public:
		Component();
		virtual ~Component();
		int	GetGUID() const { return mGUID; }
		void SetGUID(unsigned int id) { mGUID = id; }
	};
	
	// Class template to copy&paste for lazy programmers.
	class X : public Component
	{
	public:
	protected:
	};

	class Health : public Component
	{
		int mCurrentHealth, mMaxHealth;
		bool mAlive;
	public:
		Health(int cHealth, int mHealth) { mCurrentHealth = cHealth; mMaxHealth = mHealth; mAlive = true; }
		Health() { mAlive = true; }
		~Health() { }

		void SetCurrentHealth(int h);
		void SetMaxHealth(int h);
		void SetAlive(bool alive);

		bool GetAlive() const;
		int GetCurrentHealth() const;
		int GetMaxHealth() const;
		static std::string GetClassName() { return "Health"; }
	};

	class Sprite : public Component
	{
		sf::Sprite mSprite;
		sf::Texture mTexture;
	public:
		Sprite() { }
		~Sprite() { }

		void SetSpriteNTexture(std::string filename);
		sf::Sprite&	GetSprite();
		sf::Texture& GetTexture();
		static std::string GetClassName() { return "Sprite"; }
	};

	class Velocity : public Component
	{
		float mXVelocity, mYVelocity;
		bool mMoving;

	public:
		Velocity();
		~Velocity();

		void SetXVelocity(float x);
		void SetYVelocity(float y);

		float GetXVelocity() const;
		float GetYVelocity() const;

		static std::string GetClassName() { return "Velocity"; }

	};

	class Keyboard : public Component
	{
		sf::Keyboard	mKeyboard;
	public:
		Keyboard();
		~Keyboard();
		sf::Keyboard& GetKeyboard();
		static std::string GetClassName() { return "Keyboard"; }
	};
}
#endif