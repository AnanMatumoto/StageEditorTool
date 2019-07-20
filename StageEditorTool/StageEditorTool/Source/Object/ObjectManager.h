#pragma once

#include "Object.h"
#include "Parameter/MapObjectParameter.h"
#include "Parameter/CollisionObjectParameter.h"
#include "CollisionObject.h"
#include <vector>


class ObjectManager {

public:
	
	static ObjectManager* GetInstance() {
		static ObjectManager instance;
		return &instance;
	}

	void LoadData(const char* file_name);

	void AddRegist(Object* obj);

	void AddObject();

	void Init();

	void Update();

	void Draw();

	void Delete();

	void AllDelete();
private:

	std::vector<Object*>m_register_list;
	std::vector<Object*>m_object_list;
	std::vector<CollisionObject*>m_resource_list;

};