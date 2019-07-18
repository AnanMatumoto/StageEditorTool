#pragma once

#include "CollisionObject.h"
#include "MapObject.h"
#include "../Collision/CollisionData.h"
#include "../Collision/CollisionDefinition.h"

class MouseObject :public CollisionObject {

public:

	MouseObject(CollisionObjectParameter &data);

	MouseObject(
		CollisionType type,
		std::string sprite_name,
		float x, float y, float z=1.f,
		float rot=0.f, float scale_x=1.f, float scale_y=1.f
	) :CollisionObject(
		type, 
		sprite_name,
		x, y, z,
		scale_x,
		scale_y)
	{
	}

	~MouseObject()override {
	}

	void Init()override;

	void Update()override;

	void SetCollider(PointCollider& collider)override {
		collider = m_collider;
	}

	void Reflection(CollisionObject* obj)override;
	
	
private:

	//CollisionObject* m_select_obj;
	PointCollider    m_collider;
};