#pragma once

#include "DirectX9Device.h"
#include "Window.h"

/**
*@namespace ライブラリ
* ウィンドウ作成から@n
* DirectX９の描画設定を行う
*/
namespace Lib {

	/**
	*@brief アプリケーションの初期化
	*@param[in] width ウィンドウの幅
	*@param[in] height ウィンドウの高さ
	*/
	bool AppInit(
		int width,
		int height,
		const char* title,
		bool is_full_screen
	);

	/** @brief アプリケーションの終了処理 */
	void AppEnd();


	const LPDIRECT3D9 GetInterface(){
	  return DirectX9Device::GetInstance()->GetInterface();	
	}

	const LPDIRECT3DDEVICE9 GetDevice(){
		return DirectX9Device::GetInstance()->GetDevice();
	}

	/** @biref メッセージループ処理 */
	bool ProcessMessage();
}

