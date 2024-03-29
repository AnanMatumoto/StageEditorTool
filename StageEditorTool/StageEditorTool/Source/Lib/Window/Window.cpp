﻿#include "Window.h"
#include "../../Common/Common.h"
#include "../../Common/Vec.h"
#include "../Input/InputDefinition.h"
#include "../../Socket/ClientSocket.h"
#include "../../Socket/SokcketDefinition.h"
#include <windowsx.h>

namespace Lib {

	const char* WINDOW_CLASS_NAME = "StageEditorTool";
	HWND window_handle = nullptr;
	POINT point[2];
	bool is_click[MAX_OF_NUM];

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

		/*case WmAsync:
			switch (WSAGETSELECTEVENT(lparam))
			{
			case FD_READ:
				if (ClientSocket::GetInstance()->Receive(wparam) == false) {

				}
				break;
			case FD_CLOSE:
				ClientSocket::GetInstance()->CleanUp();
				break;

			default:
				return FALSE;
				break;
			}
		case WmServerName:
			if (ClientSocket::GetInstance()->Connect() == false) {
				ErrorMsg("接続に失敗しました。");
			}
			break;*/

		//押下処理
		case WM_LBUTTONDOWN:
			is_click[LEFT] = true;
			break;
		case WM_RBUTTONDOWN:
			is_click[RIGHT] = true;
			break;

		//離した際の処理
		case WM_LBUTTONUP:
			is_click[LEFT] = false;
			break;
		case WM_RBUTTONUP:
			is_click[RIGHT] = false;
			break;

		//マウス移動
		case WM_MOUSEMOVE:
			point[START].x = LOWORD(lparam);
			point[START].y = HIWORD(lparam);
			break;

		case WM_SYSKEYDOWN: // システムキー押下開始時
		case WM_SYSKEYUP:   // システムキー終了時
			break;
		}

		if (is_click[LEFT] == true) {
			point[END] = point[START];
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
		WNDCLASSEX window_class = {};
		
		//デバイスの設定
		SetUpDevice(
			h_instance, 
			WINDOW_CLASS_NAME, 
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
			WINDOW_CLASS_NAME,
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