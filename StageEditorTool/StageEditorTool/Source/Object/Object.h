#pragma once

#include "Parameter/CreateParameter.h"

class Object {

public:

	Object(
		float x, float y, float z = 1.f,
		float rot = 0.f, float scale_x = 1.f, float scale_y = 1.f
	) :m_pos(x,y,z),
	   m_rot(rot),
	   m_scale(scale_x, scale_y),
	   m_is_delete(false)
	{
	}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	const bool IsDelete() const{
		return m_is_delete;
	}

protected:

	Vec3  m_pos;
	Vec2  m_scale;
	float m_rot;
	bool  m_is_delete;

};

