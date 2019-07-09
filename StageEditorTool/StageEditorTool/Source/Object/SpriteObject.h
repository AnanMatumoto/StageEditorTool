﻿#pragma once

#include "Parameter/SpriteObjectParameter.h"
#include "Object.h"

class Drawer;

class SpriteObject:public Object{

public:

	SpriteObject(SpriteObjectParameter& data);

	SpriteObject(
		std::string sprite_name,
		float x,
		float y,
		float z   = 1.f, 
		float rot = 0.f,
		float scale_x = 1.f,
		float scale_y = 1.f
	) :Object(x,y,z,rot,scale_x, scale_y),
	   m_sprite_name(sprite_name)
	{
	}

	virtual void Update()override;

	virtual void Draw()override;


protected:

	std::string m_sprite_name;
	Drawer* m_drawer;
};