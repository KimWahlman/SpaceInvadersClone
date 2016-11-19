#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	AddComponent<KIM::Sprite>();
	AddComponent<KIM::Velocity>();
	AddComponent<KIM::Health>();

	FetchComponent<KIM::Sprite>()->SetSpriteNTexture("bullet.png");
	FetchComponent<KIM::Health>()->SetMaxHealth(1);
	FetchComponent<KIM::Health>()->SetCurrentHealth(1);

	FetchComponent<KIM::Velocity>()->SetXVelocity(0.0f);
	FetchComponent<KIM::Velocity>()->SetYVelocity(3.0f);

	mCollisionBox = this->FetchComponent<KIM::Sprite>()->GetSprite().getGlobalBounds();
	SetEntityType(3);
}

Bullet::~Bullet()
{

}

void Bullet::BulletInit(float x, float y)
{
	FetchComponent<KIM::Sprite>()->GetSprite().setPosition(x, y);
}

void Bullet::Update() 
{ 
	if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y > 800.0f)
		FetchComponent<KIM::Health>()->SetAlive(false);

	if (FetchComponent<KIM::Velocity>())
	{
		FetchComponent<KIM::Sprite>()->GetSprite().setPosition(
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x + FetchComponent<KIM::Velocity>()->GetXVelocity(),
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y + FetchComponent<KIM::Velocity>()->GetYVelocity()
		);
	}
}