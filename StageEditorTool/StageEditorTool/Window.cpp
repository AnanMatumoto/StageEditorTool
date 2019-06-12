#include "Window.h"
#include "Common.h"
namespace Lib {

	//---------------------------------
	//ウィンドウプロシージャ
	LRESULT CALLBACK WinProc(
		HWND   hwnd,
		UINT   msg,
		WPARAM wparam,
		LPARAM lparam
	) {
		switch (msg)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			break;

		case WM_SYSKEYDOWN: // システムキー押下開始時
		case WM_SYSKEYUP:   // システムキー終了時
			return 0;
		}
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	//--------------------------------
	//デバイスの設定
	void Window::SetUpDevice(
		HINSTANCE h_instance,
		const char* class_name,
		WNDCLASSEX* window_class
	) {
		window_class->cbSize        = sizeof(WNDCLASSEX);
		window_class->style         = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		window_class->lpfnWndProc   = WinProc;
		window_class->cbClsExtra    = 0;//補助バイト数(予備メモリ)
		window_class->cbWndExtra    = 0;//補助バイト数(メモリサイズ)
		window_class->hInstance     = h_instance;
		window_class->hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
		window_class->hCursor       = LoadCursor(nullptr, IDI_APPLICATION);
		window_class->hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		window_class->lpszMenuName  = MAKEINTRESOURCE(nullptr);
		window_class->lpszClassName = class_name;
		window_class->hIconSm       = nullptr;
	}

	//--------------------------------
	//ウィンドウの作成
	bool Window::Create(
		const char* title,
		int width,
		int height
	) {

		HINSTANCE h_instance;
		const char* class_name = WINDOW_CLASS_NAME;
		WNDCLASSEX window_class = {};
		
		SetUpDevice(
			h_instance, 
			class_name, 
			&window_class
		);

		if (RegisterClassEx(&window_class) == 0) {
			ErrorMsg("デバイスの登録に失敗しました。");
			return false;
		}

		DWORD dw_exstyle = WS_EX_LEFT;
		DWORD dw_style = WS_OVERLAPPEDWINDOW;

		RECT r = { 0, 0, width, height };
		AdjustWindowRectEx(&r, dw_style, FALSE, dw_exstyle);

		HWND hWnd = CreateWindowEx(
			dw_exstyle,
			class_name,
			title,
			dw_style,
			CW_USEDEFAULT,//起動時の位置と幅をウィンドウズに委ねる
			CW_USEDEFAULT,
			r.right - r.left,
			r.bottom - r.top,
			nullptr,
			nullptr,
			h_instance,
			nullptr
		);

		if (hWnd == nullptr) {
			ErrorMsg("ウィンドウの作成に失敗しました。");
			return false;
		}
		ShowWindow(hWnd, SW_SHOW);
		return true;
	}

	//----------------------------------
	//メッセージループ処理
	bool Window::ProcessMessage() {
		
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
}