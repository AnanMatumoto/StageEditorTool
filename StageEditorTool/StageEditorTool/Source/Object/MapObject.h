#pragma once

#include "SpriteObject.h"
#include "CollisionObject.h"
#include "../Object/Parameter/CollisionDefinition.h"
#include "../Collision/CollisionData.h"

class MapObject : public CollisionObject{

public:

	MapObject(CollisionObjectParameter& data);

	MapObject(CollisionType type,
		std::string sprite_name,
		float x, float y, float z = 1.f,
		float scale_x= 1.f, float scale_y = 1.f
		):CollisionObject(
		  type,
		  sprite_name,
		  x,y,z,
		  scale_x,
		  scale_y)
	{
	}

	Collider GetCollider()override {
		return m_collider;
	}

	void Reflection(CollisionObject* obj)override;

private:
	RectCollider m_collider;

};