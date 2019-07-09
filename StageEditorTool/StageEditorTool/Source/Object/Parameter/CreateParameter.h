#pragma once
#include "../../Common/Vec.h"

struct  CreateParameter
{

	CreateParameter(
		float x, float y, float z,
		float rot_, float scale_x_, float scale_y_
	):pos(x,y,z),
	  rot(rot_),
	  scale_x(scale_x_),
	  scale_y(scale_y_)
	{
	}

	Vec3  pos;
	float rot;
	float scale_x;
	float scale_y;

private:
	CreateParameter() = delete;

};