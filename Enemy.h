#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
	int mCooldown;
	bool mAlive;
public:
	Enemy();
	~Enemy();

	void Update();
	void SetAlive(bool alive);
	bool GetAlive() const;
};

#endif