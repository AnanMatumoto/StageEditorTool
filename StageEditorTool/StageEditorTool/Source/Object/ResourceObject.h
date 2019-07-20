#pragma once

#include "CollisionObject.h"
#include "../Collision/CollisionDefinition.h"
#include "Parameter/CollisionObjectParameter.h"
#include "Parameter/MapObjectParameter.h"

class ResourceObject :public CollisionObject {

public:
	ResourceObject(CollisionObjectParameter& param);

	ResourceObject(
		ObjectType object_type,
		CollisionType collision_type,
		std::string sprite_name,
		float x, float y, float z = 1.f,
		float scale_x = 1.f, float scale_y = 1.f
	) :CollisionObject(
		object_type,
		collision_type,
		sprite_name,
		x, y, z,
		scale_x,
		scale_y)
	{
	}
	
	~ResourceObject()override
	{
	}

	void Init()override;

	void Update()override;

	void SetCollider(RectCollider& collider)override {
		collider = m_collider;
	}

	void Reflection(CollisionObject* obj)override;

	const MapObjectParameter GetSelectResource()const {
		return m_map_parameter;
	}

private:
	RectCollider m_collider;
	MapObjectParameter m_map_parameter;
};