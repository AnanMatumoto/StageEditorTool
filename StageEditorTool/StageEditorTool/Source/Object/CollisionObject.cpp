#include "CollisionObject.h"
#include "../Collision/CollisionData.h"

CollisionObject::CollisionObject(
	CollisionObjectParameter &data
) :SpriteObject(
	data.sprite_name,
	data.pos.x,
	data.pos.y,
	data.pos.z,
	data.rot,
	data.scale_x,
	data.scale_y),
	m_object_type(data.object_type),
	m_collision_type(data.collision_type)
{
}

