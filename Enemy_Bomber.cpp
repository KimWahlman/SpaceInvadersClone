#include "Enemy_Bomber.h"
#include <iostream>
#include "EntityManager.h"

// Functions only used in here /////////////
void UpdateBullet(Bomber *b);
///////////////////////////////////////////

Bomber::Bomber()
{
	SetEntityType(2);
	mGoLeft = false;
	mFired = false;
	AddComponent<KIM::Health>();
	AddComponent<KIM::Sprite>();
	AddComponent<KIM::Velocity>();

	//FetchComponent<KIM::Health>()->SetAlive(true);
	FetchComponent<KIM::Health>()->SetMaxHealth(10);
	FetchComponent<KIM::Health>()->SetCurrentHealth(10);

	FetchComponent<KIM::Sprite>()->SetSpriteNTexture("bomber.png");
	FetchComponent<KIM::Sprite>()->GetSprite().setPosition(float((rand() % 450)), float((rand() % 600)));
}

Bomber::~Bomber() { }

void Bomber::Update()
{
	if (FetchComponent<KIM::Health>()->GetCurrentHealth() <= 0)
		FetchComponent<KIM::Health>()->SetAlive(false);

	if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x < 0.0f)
		mGoLeft = false;
	if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x > 465.0f)
		mGoLeft = true;

	if (FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y > 800.0f) 
		FetchComponent<KIM::Health>()->SetAlive(false);

	if (mGoLeft) 
	{
		FetchComponent<KIM::Sprite>()->GetSprite().setPosition(
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x - 3.0f,
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y + 1.0f
		);
	}
	else
	{
		FetchComponent<KIM::Sprite>()->GetSprite().setPosition(
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x + 3.0f,
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y + 1.0f
		);
	}

	if (!mFired)
	{
		mClock.restart();
		bullet = new Bullet();
		bullet->BulletInit(
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().x,
			FetchComponent<KIM::Sprite>()->GetSprite().getPosition().y
		);
		mFired = true;
		EntityManager::GetInstance().AddEntity(bullet);
	}
	//bullet.Update();
	UpdateBullet(this);
}

sf::Clock Bomber::GetClock() const
{
	return mClock;
}

// Functions only used in here /////////////
void UpdateBullet(Bomber *b)
{
	float bulletCooldown = b->GetClock().getElapsedTime().asSeconds();
	if (bulletCooldown >= 1.0f)
		b->SetFired(false);
}
// \Functions only used in here ////////////