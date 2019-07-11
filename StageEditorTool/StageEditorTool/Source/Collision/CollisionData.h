#pragma once

#include "../Common/Vec.h"
#include "../Object/CollisionObject.h"

struct Collider {

	Collider()
	{
	}

	Collider(float x, float y,float z)
	:pos(x,y,z)
	{
	}

	Vec3 pos;
};

struct PointCollider:public Collider
{
	PointCollider()
	{
	}

	PointCollider(float x, float y, float z)
	:Collider(x, y, z) 
	{
	}


};

struct RectCollider:public Collider
{
	RectCollider()
	{
	}

	RectCollider(
		float x,
		float y,
		float z,
		float width,
		float height
	) :Collider(x, y, z),
	   size(width, height)
	{
	}


	Vec2 size;
};