#include "Player.h"
#include <iostream>

const float xVel = 6.0f;
const float yVel = 7.0f;

bool IsItZero(float x, float y)
{
	float diff = x - y;
	return (diff < 0.1f);
}


Player::Player()
{
	this->AddComponent<KIM::Health>();
	AddComponent<KIM::Velocity>();
	AddComponent<KIM::Keyboard>();
	AddComponent<KIM::Sprite>();
	FetchComponent<KIM::Sprite>()->SetSpriteNTexture("cat.png");
	FetchComponent<KIM::Sprite>()->GetSprite().setPosition(250, 750);
	FetchComponent<KIM::Health>()->SetCurrentHealth(10);

	SetEntityType(0);
}

Player::~Player() { }

void Player::Update()
{
	if (FetchComponent<KIM::Keyboard>() && FetchComponent<KIM::Velocity>())
	{
		// Left
		if (FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::D))
		{
			FetchComponent<KIM::Velocity>()->SetXVelocity(xVel);
		}

		if (!FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::D) && FetchComponent<KIM::Velocity>()->GetXVelocity() > 0.0f)
		{
			if(!IsItZero(FetchComponent<KIM::Velocity>()->GetXVelocity(), 0.0f))
				FetchComponent<KIM::Velocity>()->SetXVelocity(FetchComponent<KIM::Velocity>()->GetXVelocity() - 0.15f);
			else
				FetchComponent<KIM::Velocity>()->SetXVelocity(0.0f);
		}

		// Right
		if (FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::A))
		{
			FetchComponent<KIM::Velocity>()->SetXVelocity(-xVel);
		}

		if (!FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::A) && FetchComponent<KIM::Velocity>()->GetXVelocity() < 0.0f)
		{
			if (!IsItZero(abs(FetchComponent<KIM::Velocity>()->GetXVelocity()), 0.0f))
				FetchComponent<KIM::Velocity>()->SetXVelocity(FetchComponent<KIM::Velocity>()->GetXVelocity() + 0.15f);
			else
				FetchComponent<KIM::Velocity>()->SetXVelocity(0.0f);
		}

		// Up
		if (FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::W))
		{
			FetchComponent<KIM::Velocity>()->SetYVelocity(-yVel);
		}

		if (!FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::W) && FetchComponent<KIM::Velocity>()->GetYVelocity() < 0.0f)
		{
			if (!IsItZero(abs(FetchComponent<KIM::Velocity>()->GetYVelocity()), 0.0f))
				FetchComponent<KIM::Velocity>()->SetYVelocity(FetchComponent<KIM::Velocity>()->GetYVelocity() + 0.15f);
			else
				FetchComponent<KIM::Velocity>()->SetYVelocity(0.0f);
		}

		// Down
		if (FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::S))
		{
			FetchComponent<KIM::Velocity>()->SetYVelocity(yVel);
		}

		if (!FetchComponent<KIM::Keyboard>()->GetKeyboard().isKeyPressed(sf::Keyboard::S) && FetchComponent<KIM::Velocity>()->GetYVelocity() > 0.0f)
		{
			if (!IsItZero(abs(FetchComponent<KIM::Velocity>()->GetYVelocity()), 0.0f))
				FetchComponent<KIM::Velocity>()->SetYVelocity(FetchComponent<KIM::Velocity>()->GetYVelocity() - 0.15f);
			else
				FetchComponent<KIM::Velocity>()->SetYVelocity(0.0f);
		}

		if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x < 1.0f)
		{
			FetchComponent<KIM::Sprite>()->GetSprite().setPosition(1.0f, FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y);
			FetchComponent<KIM::Velocity>()->SetXVelocity(-FetchComponent<KIM::Velocity>()->GetXVelocity());
		}

		if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x > 465.0f)
		{
			FetchComponent<KIM::Sprite>()->GetSprite().setPosition(465.0f, FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y);
			FetchComponent<KIM::Velocity>()->SetXVelocity(-FetchComponent<KIM::Velocity>()->GetXVelocity());
		}

		if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y < 1.0f)
		{
			FetchComponent<KIM::Sprite>()->GetSprite().setPosition(FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x, 1.0f);
			FetchComponent<KIM::Velocity>()->SetYVelocity(-FetchComponent<KIM::Velocity>()->GetYVelocity());
		}

		if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y > 765.0f)
		{
			FetchComponent<KIM::Sprite>()->GetSprite().setPosition(FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x, 765.0f);
			FetchComponent<KIM::Velocity>()->SetYVelocity(-FetchComponent<KIM::Velocity>()->GetYVelocity());
		}

	}

	if (FetchComponent<KIM::Velocity>())
	{
		FetchComponent<KIM::Sprite>()->GetSprite().setPosition(
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x + FetchComponent<KIM::Velocity>()->GetXVelocity(),
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y + FetchComponent<KIM::Velocity>()->GetYVelocity()
		);
	}
}