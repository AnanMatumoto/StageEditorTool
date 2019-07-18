#include "Editor.h"
#include "../Socket/SokcketDefinition.h"

void Editor::Recive(char buff[1024]) {

	int command = 0;
	memcpy(&command, buff, sizeof(int));

	switch (command)
	{
	case CommunicarionCommand::OUTPUT:
		break;

	case CommunicarionCommand::SELECT_SPRITE:
		m_select_sprite_name = &buff[sizeof(int)];
		break;
	}
}

void Editor::Update() {

	if (m_drag_object != nullptr) {
		
	}
}

void Editor::SwapDepth(
	CollisionObject* select_obj,
	CollisionObject* map_obj
) {
	RectCollider select_rect;
	RectCollider map_rect;

	select_obj->SetCollider(select_rect);
	map_obj->SetCollider(map_rect);

	float temp = 0;
	
	temp = select_rect.pos.z;
	select_rect.pos.z = map_rect.pos.z;
	map_rect.pos.z = temp;
}