#pragma once

#include "CreateParameter.h"
#include <string>

struct  SpriteObjectParameter:public CreateParameter
{
	SpriteObjectParameter(
		std::string sprite_name_,
		float x, float y, float z,
		float rot, float scale_x, float scale_y
	) :CreateParameter(x, y, z, rot, scale_x, scale_y),
	   sprite_name(sprite_name_)
	{
	}

	std::string sprite_name;

private:
	SpriteObjectParameter() = delete;

};
