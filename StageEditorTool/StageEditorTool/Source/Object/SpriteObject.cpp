#include "SpriteObject.h"
#include "../Drawer.h"

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


void SpriteObject::Update() {

}

void SpriteObject::Draw() {

	m_drawer->Draw2D(
		m_sprite_name,
		m_pos.x, m_pos.y
	);
}

