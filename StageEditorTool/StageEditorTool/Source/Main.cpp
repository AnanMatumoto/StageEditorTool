#include "Lib/Lib.h"
#include "Lib/Texture/TextureManager.h"
#include "Lib/Input/Input.h"
#include "Lib/Input/InputDefinition.h"
#include "Drawer.h"
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

	Lib::Input* input = new Lib::Input();;
	Lib::TextureManager::GetInstance()->Load("./Res/object_64x64.png");

	Drawer* drawer = new Drawer();

	while (Lib::ProcessMessage()){

		input->Uodate();

		if (input->OnMouseDown(MOUSE_KEY::RIGHT)== true) {
			MessageBox(0, "クリックされた", nullptr, MB_OK);
		}

		Lib::DirectX9Device::GetInstance()->DrawStart();
		drawer->Draw2D("./Res/object_64x64.png", 500, 500);
		
		
		Lib::DirectX9Device::GetInstance()->DrawEnd();

	
	}
	Lib::AppEnd();
	return 0;
}