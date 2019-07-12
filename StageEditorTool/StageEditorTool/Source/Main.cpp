#include "Lib/Lib.h"
#include "Lib/Texture/TextureManager.h"
#include "Object/ObjectManager.h"
#include "Lib/Input/Input.h"
#include <Windows.h>
#include <string>


int WINAPI WinMain(
	HINSTANCE h_instance,
	HINSTANCE h_pre_instance,
	LPSTR	  lp_cmd_line,
	INT       n_cmd_show
) {

	if (Lib::AppInit(1000, 800, "Test", false)==false) {
		return -1;
	}

	Lib::TextureManager::GetInstance()->Load("./Res/object_64x64.png");
	ObjectManager::GetInstance()->LoadData("./Res/test.csv");
	ObjectManager::GetInstance()->Init();

	while (Lib::ProcessMessage()){

		Lib::Input::GetInstance()->Uodate();
		ObjectManager::GetInstance()->Update();

		Lib::DirectX9Device::GetInstance()->DrawStart();
		ObjectManager::GetInstance()->Draw();
		Lib::DirectX9Device::GetInstance()->DrawEnd();
	}
	ObjectManager::GetInstance()->AllDelete();
	Lib::AppEnd();
	return 0;
}