#include "MapObject.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Input/Input.h"
#include "../Calc/Calc.h"
#include "../Editor/Editor.h"

MapObject::MapObject(MapObjectParameter& data)
:CollisionObject(
	data.object_type,
	data.collision_type,
	data.sprite_name,
	data.pos.x,
	data.pos.y,
	data.pos.z,
	data.rot,
	data.scale_x,
	data.scale_x
){
	m_size = Lib::TextureManager::GetInstance()->GetSize(m_sprite_name);
	m_collider.pos.x = m_pos.x;
	m_collider.pos.y = m_pos.y;
	m_collider.size  = m_size;
}

void MapObject::Init() {

}

void MapObject::Update() {

	CollisionManager::GetInstance()->Entry(this);
	Lib::Input* input = Lib::Input::GetInstance();
	
	if (m_is_select == false) {
		return;
	}
	m_collider.pos.x = m_pos.x = input->GetClickPoint().x;
	m_collider.pos.y = m_pos.y = input->GetClickPoint().y;
	m_collider.pos.z = m_pos.z;
	m_collider.size = m_size;

	if (input->OnMouseUp(LEFT)) {
		m_is_select = false;
	}
}

void MapObject::Reflection(CollisionObject* obj){

	RectCollider rect;

	switch (obj->GetColliisionType())
	{
	case RECT_TYPE:
		obj->SetCollider(rect);
		break;

	case POINT_TYPE:

		Lib::Input* input = Lib::Input::GetInstance();
		if (input->OnMouseDown(LEFT)) {
			m_is_select = true;
			Editor::GetInstance()->SetDragObject(this);
		}
		if (input->OnMouseDown(RIGHT)) {
			m_is_delete = true;
		}
		break;
	}
	

}

