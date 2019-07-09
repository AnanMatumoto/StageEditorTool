#pragma once

#include "CollisionObject.h"
#include "../Collision/CollisionData.h"

class MouseObject :public CollisionObject {

public:
	MouseObject(CollisionObjectParameter &data);

	MouseObject(
		CollisionType type,
		std::string sprite_name,
		float x, float y, float z,
		float rot, float scale_x, float scale_y
	) :CollisionObject(type, sprite_name, x, y, z, scale_x, scale_y)
	{
	}

	Collider GetCollider()override {
		return m_collider;
	}

	void Reflection(CollisionObject* obj)override;


private:

	bool m_is_drag;
	Vec2 m_click_pos;
	PointCollider m_collider;
};