#pragma once

#include "SpriteObjectParameter.h"
#include "../../Collision/CollisionDefinition.h"

struct CollisionObjectParameter: public SpriteObjectParameter
{
	CollisionObjectParameter(
		ObjectType object_type_,
		CollisionType collision_type_,
		std::string sprite_name_,
		float x,
		float y,
		float z = 1.f,
		float rot = 0.f,
		float scale_x = 1.f,
		float scale_y = 1.f
	) :SpriteObjectParameter(sprite_name_,x,y,z,rot,scale_x,scale_y),
	  object_type(object_type_),
	  collision_type(collision_type_)
	{
	}

	CollisionObjectParameter() {
	}

	ObjectType object_type;
	CollisionType collision_type;

};


