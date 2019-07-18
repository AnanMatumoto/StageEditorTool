#include "MapObject.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Input/Input.h"
#include "../Calc/Calc.h"
#include "../Editor/Editor.h"

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
	m_size = Lib::TextureManager::GetInstance()->GetSize(m_sprite_name);
}

void MapObject::Init() {

	m_collider.pos = m_pos;
	m_collider.size = m_size;
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
		//選択中のオブジェクトが背面にある場合
		if (rect.pos.z < m_collider.pos.z) {
			Editor::GetInstance()->SwapDepth(this, obj);
		}
		break;

	case POINT_TYPE:

		if (Lib::Input::GetInstance()->OnMouseDown(LEFT)) {
			m_is_select = true;
			Editor::GetInstance()->SetDragObject(this);

		}
		if (Lib::Input::GetInstance()->OnMouseDown(RIGHT)) {
			m_is_delete = true;
			
		}
		break;
	}
	

}

