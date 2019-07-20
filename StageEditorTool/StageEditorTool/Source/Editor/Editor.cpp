#include "Editor.h"
#include "../Socket/SokcketDefinition.h"
#include "../Object/ObjectManager.h"
#include "../Collision/CollisionManager.h"
#include "../Lib/Texture/TextureManager.h"
#include "../Drawer/Drawer.h"

bool Editor::Init(
	const char* app_name,
	int width, int height
) {
	
	m_drawer = new Drawer();

	if (Lib::AppInit(width, height, app_name, false) == false) {
		return false;
	}

	if (Lib::TextureManager::GetInstance()->Load("./Res/texture_name_table.csv") == false) {
		return false;
	}
	if (ObjectManager::GetInstance()->Load("./Res/resource_data.csv") == false) {
		return false;
	}
	ObjectManager::GetInstance()->Init();
	return true;
}

void Editor::Update() {

	CollisionManager::GetInstance()->Clear();
	ObjectManager::GetInstance()->Update();
	CollisionManager::GetInstance()->Update();
}

void Editor::Draw() {

	m_drawer->Draw2D(
		"./Res/resource_space.csv",
		0, 0,
		0.2
	);

	Lib::DirectX9Device::GetInstance()->DrawStart();
	ObjectManager::GetInstance()->Draw();
	Lib::DirectX9Device::GetInstance()->DrawEnd();
	ObjectManager::GetInstance()->Delete();
}

void Editor::Release() {
	Lib::TextureManager::GetInstance()->AllRelease();
	Lib::AppEnd();
}


//void Editor::Recive(char buff[1024]) {
//
//	int command = 0;
//	memcpy(&command, buff, sizeof(int));
//
//	switch (command)
//	{
//	case CommunicarionCommand::OUTPUT:
//		break;
//
//	case CommunicarionCommand::SELECT_SPRITE:
//		m_select_sprite_name = &buff[sizeof(int)];
//		break;
//	}
//}

//void Editor::Init(std::string select_sprite_name) {
//	m_select_sprite_name = select_sprite_name;
//	m_drag_object = nullptr;
//}