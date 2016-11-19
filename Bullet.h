#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
	sf::FloatRect mCollisionBox;
public:
	Bullet();
	~Bullet();
	
	void BulletInit(float x, float y);
	void CheckCollision(sf::FloatRect other);
	void Update();
};

#endif