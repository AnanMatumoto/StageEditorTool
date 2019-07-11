#include "MapObject.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Texture/TextureManager.h"

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

	

}

void MapObject::Reflection(CollisionObject* obj){

	PointCollider point;
	obj->SetCollider(point);

	m_pos.x = point.pos.x;
	m_pos.y = point.pos.y;
}