#pragma once

#include "Object.h"
#include "Parameter/MapObjectParameter.h"
#include "Parameter/SpriteObjectParameter.h"
#include <vector>

class ObjectManager {

public:
	
	static ObjectManager* GetInstance() {
		static ObjectManager instance;
		return &instance;
	}

	void LoadData(const char* file_name);
	
	void AddObject();

	void Init();

	void Update();

	void Draw();

	void Delete();

	void AllDelete();
private:

	std::vector<Object*>m_object_list;
	std::vector<MapObjectParameter>m_map_list;
	std::vector<SpriteObjectParameter>m_sprite_list;
};