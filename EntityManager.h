#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
class Entity;

class EntityManager
{
	std::vector<Entity*> mEntities;
	EntityManager();
public:
	static EntityManager& GetInstance()
	{
		static EntityManager instance;
		return instance;
	}

	EntityManager(EntityManager const&) = delete;
	EntityManager(EntityManager&&) = delete;
	EntityManager&operator=(EntityManager const&) = delete;
	EntityManager&operator=(EntityManager&&) = delete;
	/// Testfunctions
	void TestSpawn(int health, float x = 0.0f, float y = 0.0f); // Spawn
	/// !Testfunctions
	void Update();
	void AddEntity(Entity* e);

	std::vector<Entity*>& GetEntities();
protected:	
	~EntityManager();
};

#endif