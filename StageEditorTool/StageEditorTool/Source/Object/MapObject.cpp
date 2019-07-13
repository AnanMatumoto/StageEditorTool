#include "MapObject.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Texture/TextureManager.h"
#include "../Lib/Input/Input.h"

MapObject::MapObject(MapObjectParameter& data)
:CollisionObject(
	data.type,
	data.sprite_name,
	data.pos.x,
	data.pos.y,
	data.pos.z,
	data.rot,
	data.scale_x,
	data.scale_x
){
}

void MapObject::Init() {

	CollisionManager::GetInstance()->Entry(this);

	m_size = Lib::TextureManager::GetInstance()->GetSize(m_sprite_name);
	m_collider = RectCollider(
		m_pos.x,
		m_pos.y,
		m_pos.z,
		m_size.x,
		m_size.y
	);
}

void MapObject::Update() {

	Lib::Input* input = Lib::Input::GetInstance();
		
	if (m_is_move==true) {
			m_pos.x = input->GetClickPoint().x;
			m_pos.y = input->GetClickPoint().y;
	}
}

void MapObject::Reflection(CollisionObject* obj){

	if (obj->GetColliisionType() == POINT_TYPE) {

		if (Lib::Input::GetInstance()->OnMouseDown(LEFT)) {
			m_is_move = true;
		}
		else {
			m_is_move = false;
		}

		if (Lib::Input::GetInstance()->OnMouseDown(RIGHT)) {
			m_is_delete = true;
		}
	}
}