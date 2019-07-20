#pragma once

#include "CollisionObject.h"
#include "../Collision/CollisionData.h"
#include "Parameter/MapObjectParameter.h"
#include "../Lib/Texture/TextureManager.h"

class MapObject : public CollisionObject{

public:

	MapObject(MapObjectParameter& data);

	MapObject(
		ObjectType object_type,
		CollisionType collision_type,
		std::string sprite_name,
		float x, float y, float z = 1.f,
		float scale_x= 1.f, float scale_y = 1.f
		):CollisionObject(
		  object_type,
		  collision_type,
		  sprite_name,
		  x,y,z,
		  scale_x,
		  scale_y)
	{
	}

	~MapObject()override
	{
	}

	void Init()override;

	void Update()override;

	void SetCollider(RectCollider& collider)override {
		 collider = m_collider;
	}
    
	void Reflection(CollisionObject* obj)override;

private:
	RectCollider m_collider;
};