﻿#pragma once

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
		const char* title
	);

	/** @brief アプリケーションの終了処理 */
	void AppEnd();

}