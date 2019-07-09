#pragma once

#include "CollisionObjectParameter.h"
#include "CollisionDefinition.h"
#include <string>

struct  MapObjectParameter:public CollisionObjectParameter
{
	MapObjectParameter(
		CollisionType type,
		std::string sprite_name,
		float x, float y, float z, 
		float rot, float scale_x, float scale_y
	):CollisionObjectParameter(
		type, sprite_name, x, y, z, rot, scale_x,scale_y
	){
	}

	CollisionType type;

private:

	MapObjectParameter() = delete;
};
