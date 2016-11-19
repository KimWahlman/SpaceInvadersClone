#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <string>
#include "Component.h"			// Components
#include <iostream>
class Entity
{
	std::unordered_map<std::string, KIM::Component*> mComponentMap;
	int mEntityType;
public:
	Entity() { }
	virtual ~Entity();
	virtual void Update() { }

	void SetEntityType(int);
	int GetEntityType() const;

	template <typename T>
	void AddComponent()
	{
		T *t(new T());
		mComponentMap.insert(std::make_pair(T::GetClassName(), t));
	}

	void DeleteComponent(std::string key) { mComponentMap.erase(key); }

	template<typename T>
	T* FetchComponent()
	{
		return dynamic_cast<T*>(mComponentMap[T::GetClassName()]);
	}
};

#endif