#pragma once

#include "../Object/MapObject.h"
#include "../Collision/CollisionDefinition.h"
#include <string>

class MouseObject;

class Editor {

public:

	static Editor* GetInstance() {
		static Editor instance;
		return &instance;
	}

	void Init(std::string select_sprite_name);

	void Recive(char buff[1024]);

	std::string GetSelectSpriteName() {
		return m_select_sprite_name;
	}

	MapObject* GetDragObject() {
		return m_drag_object;
	}

	void SetDragObject(MapObject* obj) {
		m_drag_object = obj;
	}


	//void Update();

private:
	std::string  m_select_sprite_name;
	MapObject*   m_drag_object;
	Vec2		 m_pos;
};