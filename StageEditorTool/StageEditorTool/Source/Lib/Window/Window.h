#pragma once
#include <Windows.h>

//=============================
// ウィンドウクラス
//=============================

namespace Lib {

	 extern const char* WINDOW_CLASS_NAME;
	 extern HWND window_handle;
	 extern POINT point[2];
	 extern bool  is_click[3];
	/**
	*@brief ウィンドウプロシージャ
	*@param[in] hwnd ウィンドウのハンドル
	*@param[in] msg  イベントメッセージ
	*@param[in] wparam メッセージの情報
	*@param[in] lparam メッセージの付加情報
 	*/
    LRESULT CALLBACK WinProc(
		HWND   hwnd,
		UINT   msg,
		WPARAM wparam,
		LPARAM lparam
	);

	class Window {

	public:

		/**
		*@brief  ウィンドウのインスタンスゲッター
		*@return インスタンスのポインタ
		*/
		static Window* GetInstance() {
			static Window window;
			return &window;
		}

		/** @brief デストラクタ */
		~Window(){}

		/**
		*@brief デバイスの設定
		*@param[in] h_instance インスタンスハンドル
		*@param[in] class_name ウィンドウ名（識別用）
		:@param[in] デバイス設定用構造体
		*/
		void SetUpDevice(
			HINSTANCE h_instance,
			const char* class_name,
			WNDCLASSEX* window_class);


		/**
		*@brief ウィンドウの作成
		*@return 作成の可否　成功ならture
		*@param[in] h_instance インスタンスハンドル
		*@param[in] class_name ウィンドウ名（識別用）
		*@brief[in] title ウィンドウ名
		*/
		bool Create(
			const char* title,
			int width,
			int height
		);

	};

}
