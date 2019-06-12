#include <Windows.h>
#include "Lib.h"


int WINAPI WinMain(
	HINSTANCE h_instance,
	HINSTANCE h_pre_instance,
	LPSTR	  lp_cmd_line,
	INT       n_cmd_show
) {

	if (Lib::AppInit(1600, 980, "Test", false)==false) {
		return 0;
	}

	while (Lib::ProcessMessage()){

		Lib::DirectX9Device::GetInstance()->DrawStart();
		Lib::DirectX9Device::GetInstance()->DrawEnd();
	}
	Lib::AppEnd();

	return 0;
}