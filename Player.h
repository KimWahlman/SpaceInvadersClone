#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
	Player();
public:
	static Player& GetInstance()
	{
		static Player instance;
		return instance;
	}

	Player(Player const&) = delete;
	Player(Player&&) = delete;
	Player&operator=(Player const&) = delete;
	Player&operator=(Player&&) = delete;

	void Update();
protected:
	~Player();

	
};

#endif