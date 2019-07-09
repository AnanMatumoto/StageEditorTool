#pragma once

#include "DirectX9/DirectX9Device.h"
#include "Window/Window.h"
#include "../Common/Vec.h"

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

	/** @biref メッセージループ処理 */
	bool ProcessMessage();

	void SetMovePoint(Vec2 &point);

	void SetClickPoint(Vec2 &point);

}

