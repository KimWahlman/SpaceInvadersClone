#ifndef ENEMY_BOMBER
#define ENEMY_BOMBER

#include "Enemy.h"
#include <SFML\System\Time.hpp>
#include <SFML\System\Clock.hpp>
#include "Bullet.h"

class Bomber : public Entity
{
	bool mGoLeft, mFired;
	sf::Time mTime;
	sf::Clock mClock;
	Bullet* bullet;
public:
	Bomber();
	virtual ~Bomber();

	void Update();
	void SetFired(bool fired) { mFired = fired; }
	sf::Clock GetClock() const;
	bool GetFired() const { return mFired; }
};

#endif // !ENEMY_BOMBER