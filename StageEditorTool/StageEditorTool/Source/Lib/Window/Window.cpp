#include "Window.h"
#include "../../Common/Common.h"
#include "../../Common/Vec.h"

namespace Lib {

	const char* WINDOW_CLASS_NAME = "StageEditorTool";
	HWND window_handle = nullptr;

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
		case WM_DESTROY:
			PostQuitMessage(0);
			break;


		case WM_SYSKEYDOWN: // システムキー押下開始時
		case WM_SYSKEYUP:   // システムキー終了時
			break;



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

		HINSTANCE h_instance = nullptr;
		const char* class_name = WINDOW_CLASS_NAME;
		WNDCLASSEX window_class = {};
		
		//デバイスの設定
		SetUpDevice(
			h_instance, 
			class_name, 
			&window_class
		);

		if (RegisterClassEx(&window_class) == 0) {
			ErrorMsg("デバイスの登録に失敗しました。");
			return false;
		}

		DWORD dw_exstyle = WS_EX_LEFT;//左揃えのプロパティウィンドウ
		DWORD dw_style = WS_OVERLAPPEDWINDOW;//タイトルと枠あり

		RECT r = { 0, 0, width, height };
		AdjustWindowRectEx(&r, dw_style, FALSE, dw_exstyle);
		
		//ウィンドウの作成
		window_handle = CreateWindowEx(
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

		if (window_handle== nullptr) {
			ErrorMsg("ウィンドウの作成に失敗しました。");
			return false;
		}
		ShowWindow(window_handle, SW_SHOW);
		return true;
	}
}