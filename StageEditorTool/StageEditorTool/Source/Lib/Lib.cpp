#include "Lib.h"
#include "Window/Window.h"
#include "DirectX9/DirectX9Device.h"

namespace Lib {

	//-----------------------------
	//アプリケーションの初期化
	bool AppInit(
		int width,
		int height,
		const char* title,
		bool is_full_screen
	) {
		//ウィンドウの作成
		if (Window::GetInstance()->Create(title, width, height)==false) {
			return false;
		}

		//DirectX9の初期化
		if (DirectX9Device::GetInstance()->Init(width,height)==false) {
			return false;
		}


		return true;
	}

	//----------------------------------
	//アプリケーションの終了処理
	void AppEnd() {
		DirectX9Device::GetInstance()->Release();
	}

	//----------------------------------
	//メッセージループ処理
	bool ProcessMessage() {

		MSG msg;
		//　メッセージが０では無い間
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT) {
				return false;
			}
		}
		return true;
	}

	LPDIRECT3DDEVICE9 GetDevice() {
		return Lib::DirectX9Device::GetInstance()->GetDevice();
	}
};