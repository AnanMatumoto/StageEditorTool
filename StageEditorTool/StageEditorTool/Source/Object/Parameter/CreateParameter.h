#pragma once
#include "../../Common/Vec.h"

struct  CreateParameter
{
	CreateParameter(
		float x,
		float y,
		float z=1.f,
		float rot_=0.f,
		float scale_x_=1.f,
		float scale_y_=1.f
	):pos(x,y,z),
	  rot(rot_),
	  scale_x(scale_x_),
	  scale_y(scale_y_)
	{
	}

	CreateParameter() {
	}

	Vec3  pos;
	float rot;
	float scale_x;
	float scale_y;
};