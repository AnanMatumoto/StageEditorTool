#include "MouseObject.h"
#include "../Lib/Input/Input.h"

MouseObject::MouseObject(CollisionObjectParameter& data)
:CollisionObject(
	data.type,
	data.sprite_name,
	data.pos.x,
	data.pos.y,
	data.pos.z,
	data.rot,
	data.scale_x,
	data.scale_y
){

	m_collider = PointCollider(
		m_pos.x,
		m_pos.y,
		m_pos.z
	);
}

void MouseObject::Reflection(CollisionObject* obj) {

	Lib::Input* input = Lib::Input::GetInstance();

	if (input->OnMouseDown(MouseKey::LEFT)) {
		//オブジェクト選択
		m_is_drag = true;
	}
	else if(input->OnMousePush(MouseKey::RIGHT)){
		//オブジェクト削除
		obj->IsDelete();
	}
}

