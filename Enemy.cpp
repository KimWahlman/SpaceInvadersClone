#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Update()
{

}

void Enemy::SetAlive(bool alive) 
{
	mAlive = alive;
}

bool Enemy::GetAlive() const
{
	return mAlive;
}