#include "MapObject.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Texture/TextureManager.h"
#include "../Lib/Input/Input.h"
#include "../Calc/Calc.h"

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
	m_collider.pos.x = m_pos.x;
	m_collider.pos.y = m_pos.y;
	m_collider.pos.z = m_pos.z;
	m_collider.size.x = m_size.x;
	m_collider.size.y = m_size.y;
}

void MapObject::Update() {

	Lib::Input* input = Lib::Input::GetInstance();
	
	if (m_is_move == true) {
		m_collider.pos.x = m_pos.x = input->GetClickPoint().x;
		m_collider.pos.y = m_pos.y = input->GetClickPoint().y;
	}
}

void MapObject::Reflection(CollisionObject* obj){

	switch (obj->GetColliisionType())
	{
	case POINT_TYPE:
		if (Lib::Input::GetInstance()->OnMouseDown(LEFT)) {
			m_is_move = true;
		}
		else if (Lib::Input::GetInstance()->OnMouseUp(LEFT)) {
			m_is_move = false;
		}
	case RECT_TYPE:
		float new_z = obj->GetColliderDepth();
		Calc::SwapFloatValue(new_z, m_collider.pos.z);

	}
	

}

