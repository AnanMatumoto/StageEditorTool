#pragma once

#include "SpriteObject.h"
#include "Parameter/CollisionObjectParameter.h"
#include "../Collision/CollisionDefinition.h"
#include "../Collision/CollisionData.h"

class CollisionObject :public SpriteObject {

public:

	CollisionObject(CollisionObjectParameter& data);

	CollisionObject(
		CollisionType type,
		std::string sprite_name,
		float x, float y, float z= 1.f,
		float rot=0.f, float scale_x=1.f, float scale_y=1.f
	):SpriteObject(sprite_name,x, y, z , rot, scale_x, scale_y),
	  m_type(type)
	{
	}

	~CollisionObject()override {

	}

	const CollisionType GetColliisionType()const{
		return m_type;
	}

	virtual void SetCollider(RectCollider& collider){
	}

	virtual void SetCollider(PointCollider& collider){
	}

	virtual void Reflection(CollisionObject* obj) = 0;

protected:
	CollisionType m_type;

private:
	Collider m_collider;
};