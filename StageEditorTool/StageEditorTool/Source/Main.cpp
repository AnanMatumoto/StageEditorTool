#include "Lib/Lib.h"
#include "Lib/Texture/TextureManager.h"
#include "Object/ObjectManager.h"
#include "Collision/CollisionManager.h"
//#include "Socket/ClientSocket.h"
//#include "Editor/Edditor.h"
#include "Lib/Input/Input.h"
#include <WinSock2.h>
#include <Windows.h>
#include <string>


int WINAPI WinMain(
	HINSTANCE h_instance,
	HINSTANCE h_pre_instance,
	LPSTR	  lp_cmd_line,
	INT       n_cmd_show
) {

	if (Lib::AppInit(1500, 1000, "StageEditorTool", false)==false) {
		return -1;
	}

	//ClientSocket::GetInstance()->Start(2000);

	Lib::TextureManager::GetInstance()->Load("./Res/object_64x64.png");
	Lib::TextureManager::GetInstance()->Load("./Res/object_192×192_ver2_c.png");
	Lib::TextureManager::GetInstance()->Load("./Res/object_192x192.png");
	Lib::TextureManager::GetInstance()->Load(
		"./Res/reource_space.png"
	);
	ObjectManager::GetInstance()->LoadData("./Res/resource_data.csv");


	ObjectManager::GetInstance()->Init();


	//Editor::GetInstance()->Init("./Res/object_64x64.png");

	while (Lib::ProcessMessage()){

		//エディターに閉じ込める忘れない
		CollisionManager::GetInstance()->Clear();

		ObjectManager::GetInstance()->Update();
		CollisionManager::GetInstance()->Update();
		

		Lib::DirectX9Device::GetInstance()->DrawStart();
		ObjectManager::GetInstance()->Draw();
		Lib::DirectX9Device::GetInstance()->DrawEnd();
		ObjectManager::GetInstance()->Delete();
	}

	//ClientSocket::GetInstance()->CleanUp();
	Lib::AppEnd();
	return 0;
}