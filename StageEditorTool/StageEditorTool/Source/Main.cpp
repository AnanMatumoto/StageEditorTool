#include "Lib/Lib.h"
#include "Editor/Editor.h"

int WINAPI WinMain(
	HINSTANCE h_instance,
	HINSTANCE h_pre_instance,
	LPSTR	  lp_cmd_line,
	INT       n_cmd_show
) {

	if(Editor::GetInstance()->Init("StageEditorTool") == false){
		return -1;
	}

	while (Lib::ProcessMessage()){
	
		Editor::GetInstance()->Update();
		Editor::GetInstance()->Draw();
	
	}
	Editor::GetInstance()->Release();
	return 0;
}