#pragma once

#include "../Object/MapObject.h"
#include <string>

class Editor {

public:

	static Editor* GetInstance() {
		static Editor instance;
		return &instance;
	}

	void Init(std::string select_sprite_name) {
		m_select_sprite_name = select_sprite_name;
		m_drag_object = nullptr;
	}

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

	void SwapDepth(
		CollisionObject* select_obj,
		CollisionObject* map_obj);

	void Update();

private:
	std::string m_select_sprite_name;
	MapObject* m_drag_object;
};