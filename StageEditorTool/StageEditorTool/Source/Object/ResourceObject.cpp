#include "ResourceObject.h"
#include "../Common/Common.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Input/Input.h"
#include "../Editor/Editor.h"
#include "../Factory/ObjectFactory.h"

ResourceObject::ResourceObject(CollisionObjectParameter& data)
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
}

void ResourceObject::Init() {

    CollisionManager::GetInstance()->Entry(this);
	m_collider.pos  = m_pos;
	m_collider.size = m_size;
}

void ResourceObject::Update() {

	
	
}

void ResourceObject::Reflection(CollisionObject* obj) {

	if (Lib::Input::GetInstance()->OnMousePush(LEFT)) {

		//オブジェクトを生成
		MapObjectParameter param(
			ObjectType::MAP,
			m_collision_type,
			m_sprite_name,
			WINDOW_CENTER_X,
			WINDOW_CENTER_Y,
			1.f
		);
		ObjectFactory factory;
		factory.CreateMapObject(param);
	}
	else {
		return;
	}
}