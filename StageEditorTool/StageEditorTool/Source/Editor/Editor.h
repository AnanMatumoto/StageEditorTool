#pragma once

#include "../Common/Common.h"
#include "../Object/MapObject.h"
#include "../Collision/CollisionDefinition.h"
#include <string>

class Drawer;
class MouseObject;

class Editor {

public:

	static Editor* GetInstance() {
		static Editor instance;
		return &instance;
	}

	//void Init(std::string select_sprite_name);

	bool Init(
		const char* app_name,
		int width = WINDOW_W,
		int height = WINDOW_H);

	void Update();

	void Draw();

	void Release();

	//void Recive(char buff[1024]);

	std::string GetSelectSpriteName() {
		return m_select_sprite_name;
	}

	MapObject* GetDragObject() {
		return m_drag_object;
	}

	void SetDragObject(MapObject* obj) {
		m_drag_object = obj;
	}

private:
	std::string  m_select_sprite_name;
	MapObject*   m_drag_object;
	Vec2		 m_pos;
	Drawer*      m_drawer;
};