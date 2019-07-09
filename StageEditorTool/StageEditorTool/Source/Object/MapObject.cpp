#include "MapObject.h"



MapObject::MapObject(CollisionObjectParameter& data)
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
	
	m_collider = RectCollider(
		m_pos.x,
		m_pos.y,
		m_pos.z,
		m_size.x,
		m_size.y
	);
}

void MapObject::Reflection(CollisionObject* obj){

	m_pos = obj->GetCollider().pos;

}