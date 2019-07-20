#pragma once

#include "SpriteObject.h"
#include "Parameter/CollisionObjectParameter.h"
#include "../Collision/CollisionDefinition.h"
#include "../Collision/CollisionData.h"

class CollisionObject :public SpriteObject {

public:

	CollisionObject(CollisionObjectParameter& data);

	CollisionObject(
		ObjectType object_type,
		CollisionType collision_type,
		std::string sprite_name,
		float x, float y, float z= 1.f,
		float rot=0.f, float scale_x=1.f, float scale_y=1.f
	):SpriteObject(sprite_name,x, y, z , rot, scale_x, scale_y),
	  m_object_type(object_type),
	  m_collision_type(collision_type),
	  m_is_select(false)
	{
	}

	~CollisionObject()override {

	}

    CollisionType GetColliisionType(){
		return m_collision_type;
	}

	virtual void SetCollider(RectCollider& collider){
	}

	virtual void SetCollider(PointCollider& collider){
	}

    ObjectType GetObjectType() {
		return m_object_type;
	}

	virtual void Reflection(
		CollisionObject* obj) = 0;

	const bool GetSelect()const{
		return m_is_select;
	}

protected:
	CollisionType m_collision_type;
	ObjectType	  m_object_type;
	bool m_is_select;

private:
	Collider m_collider;
};

