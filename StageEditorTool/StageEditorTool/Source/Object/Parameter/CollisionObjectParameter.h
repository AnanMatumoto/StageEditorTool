#pragma once

#include "SpriteObjectParameter.h"
#include "../../Collision/CollisionDefinition.h"

struct CollisionObjectParameter: public SpriteObjectParameter
{
	CollisionObjectParameter(
		CollisionType type_,
		std::string sprite_name_,
		float x,
		float y,
		float z = 1.f,
		float rot = 0.f,
		float scale_x = 1.f,
		float scale_y = 1.f
	) :SpriteObjectParameter(sprite_name_,x,y,z,rot,scale_x,scale_y),
	  type(type_)
	{
	}

	CollisionObjectParameter() {
	}

	CollisionType type;

};


