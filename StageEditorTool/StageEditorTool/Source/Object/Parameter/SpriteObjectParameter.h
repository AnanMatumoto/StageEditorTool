#pragma once

#include "CreateParameter.h"
#include <string>

struct  SpriteObjectParameter:public CreateParameter
{
	SpriteObjectParameter(
		std::string sprite_name_,
		float x,
		float y,
		float z=1.f,
		float rot=0.f,
		float scale_x=1.f,
		float scale_y=1.f
	) :CreateParameter(x, y, z, rot, scale_x, scale_y),
	   sprite_name(sprite_name_)
	{
	}

	SpriteObjectParameter() {
	}

	std::string sprite_name;
};
