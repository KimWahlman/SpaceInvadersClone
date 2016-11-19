#include "Entity.h"

Entity::~Entity() 
{ 
	for (unsigned int i = 0; i < mComponentMap.size(); i++)
	{
		auto health = mComponentMap.find("Health");
		auto sprite = mComponentMap.find("Sprite");
		auto velocity = mComponentMap.find("Velocity");
		auto keyboard = mComponentMap.find("Keyboard");
		
		if (health != mComponentMap.end())
		{
			delete health->second;
			DeleteComponent("Health");
			break;
		}
		if (sprite != mComponentMap.end())
		{
			delete sprite->second;
			DeleteComponent("Sprite");
			break;
		}
		if (velocity != mComponentMap.end())
		{
			delete velocity->second;
			DeleteComponent("Velocity");
			break;
		}
		if (keyboard != mComponentMap.end())
		{
			delete keyboard->second;
			DeleteComponent("Keyboard");
			break;
		}
		std::cout << "Deleted\n";
	}
}

void Entity::SetEntityType(int id) { mEntityType = id; }
int Entity::GetEntityType() const { return mEntityType; }