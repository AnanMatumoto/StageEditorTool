#include "Lib.h"
#include "Window.h"

namespace Lib {

	bool AppInit(
		int width,
		int height,
		const char* title
	) {
		//ウィンドウの作成
		if (Window::GetInstance()->Create(title, width, height)==false) {
			return false;
		}


	}



};