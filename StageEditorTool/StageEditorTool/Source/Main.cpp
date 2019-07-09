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

		//input->Uodate();

	/*	if (input->OnMouseDown(MouseKey::RIGHT)== true) {
			MessageBox(0, "クリックされた", nullptr, MB_OK);
		}

		Vec2 vec =input->GetClickPoint(MouseKey::LEFT);
		if (vec.x > 0) {
			MessageBox(0, "座標取得", nullptr, MB_OK);
		}*/

		Lib::DirectX9Device::GetInstance()->DrawStart();
		drawer->Draw2D("./Res/object_64x64.png", 500, 500);
		
		
		Lib::DirectX9Device::GetInstance()->DrawEnd();

	
	}
	Lib::AppEnd();
	return 0;
}