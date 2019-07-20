#include "SpriteObject.h"
#include "../Lib/Texture/TextureManager.h"
#include "../Collision/CollisionManager.h"

SpriteObject::SpriteObject(SpriteObjectParameter&data
):Object(data.pos.x,
		 data.pos.y,
	     data.pos.z,
		 data.rot,
		 data.scale_x,
		 data.scale_y),
		m_sprite_name(data.sprite_name)
{
	m_drawer = new Drawer();
}

void SpriteObject::Init() {
	m_size = { 1,1 };
}


void SpriteObject::Update() {
}

void SpriteObject::Draw() {

	m_drawer->Draw2D(
		m_sprite_name,
		m_pos.x, m_pos.y,
		m_pos.z
	);
}

SpriteObject::~SpriteObject() {

	delete m_drawer;
}