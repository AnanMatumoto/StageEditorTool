#pragma once

#include "SpriteObjectParameter.h"
#include "CollisionDefinition.h"

struct CollisionObjectParameter: public SpriteObjectParameter
{
	CollisionObjectParameter(
		CollisionType type,
		std::string sprite_name_,
		float x, float y, float z,
		float rot, float scale_x, float scale_y
	) :SpriteObjectParameter(sprite_name_,x,y,z,rot,scale_x,scale_y)
	{
	}

	CollisionType type;

private:
	CollisionObjectParameter() = delete;

};