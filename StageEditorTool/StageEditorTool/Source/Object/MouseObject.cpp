﻿#include "MouseObject.h"
#include "../Lib/Input/Input.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/CollisionData.h"

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
}

void MouseObject::Init() {

	CollisionManager::GetInstance()->Entry(this);
}

void MouseObject::Update() {

	Lib::Input* input = Lib::Input::GetInstance();
	 m_collider.pos.x = m_pos.x = input->GetMovePoint().x;
	 m_collider.pos.y = m_pos.y = input->GetMovePoint().y;

}
void MouseObject::Reflection(CollisionObject* obj) {
	

}

