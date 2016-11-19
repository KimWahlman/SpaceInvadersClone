#include "EntityManager.h"
#include "Entity.h"
#include "Enemy_Bomber.h"
#include <string>
#include <iostream>
/// Global test vars.
std::string files[3] = { "cat.png", "test.png", "bullet.png" };
int po = 0;
/// /////////////////

EntityManager::EntityManager() { }
EntityManager::~EntityManager() { }

void EntityManager::AddEntity(Entity* e) { mEntities.push_back(e); }
std::vector<Entity*>& EntityManager::GetEntities() { return mEntities; }

void EntityManager::Update()
{
	// Player is always 0.
	GetEntities()[0]->Update();
	for (unsigned int i = 1; i < GetEntities().size(); i++)
	{
		GetEntities()[i]->Update();
		if (!GetEntities()[i]->FetchComponent<KIM::Health>()->GetAlive())
		{
			delete GetEntities()[i];
			GetEntities().erase(GetEntities().begin() + i);
			i--;
		}
	}
}

void EntityManager::TestSpawn(int health, float x, float y)
{
	Bomber *e = new Bomber();
	AddEntity(e);
}