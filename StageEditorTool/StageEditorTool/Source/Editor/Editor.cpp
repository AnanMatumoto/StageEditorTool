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

void Editor::Init(std::string select_sprite_name) {
	m_select_sprite_name = select_sprite_name;
	m_drag_object = nullptr;
}




