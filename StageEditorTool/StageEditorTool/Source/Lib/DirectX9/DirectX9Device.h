#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../Window/Window.h"
#include <d3d9.h>
#include <d3dx9.h>


namespace Lib {

	class DirectX9Device {
	
	public:

		/**	*@brief　インスタンス取得関数 */
		static DirectX9Device* GetInstance() {
			static DirectX9Device instance;
			return &instance;
		}

		/**
		*@brief DirectX9初期化関数
		*@return 初期化の可否　成功の場合true
		*@param[in]width  ウィンドウの幅
		*@param[in]height ウィンドウの高さ
		*@param[in]is_full_screen フルサイズモードにするか
		*/
		bool Init(
			int width,
			int height,
			bool is_full_screen = false);

		/**
		*@brief DirectX9のデバイス生成
		*@return デバイス生成の可否　成功の場合true
		*/
		bool CreateDevice();

		/** 
		*@brief 描画の開始
		*@param[in]back_color バックバッファの色(デフォルトは黒）
		*/
		void DrawStart(DWORD back_color = 0xffffffff);

		/**_@brief 描画の終了*/
		void DrawEnd();

		/** @brief DirectX9インターフェースゲッター */
		const LPDIRECT3D9 GetInterface() {
			return m_interface;
		}

		/** @brief DirectX9デバイスゲッター */
		const LPDIRECT3DDEVICE9 GetDevice() {
			return m_device;
		}

		/** @brief インターフェース解放処理 */
		void Release();
	

	private:
		D3DPRESENT_PARAMETERS m_param;
		 LPDIRECT3D9       m_interface; //! DirectX9インターフェース
		LPDIRECT3DDEVICE9 m_device;	   //! DirectX9デバイス

	};


}

