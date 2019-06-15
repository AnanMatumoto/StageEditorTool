#pragma once

#include "Lib.h"
#include "Vec.h"
#include <string>

//===================================
// テクスチャー生成クラス
//===================================
namespace Lib {

	class Texture {

	public:

		/** コンストラクタ@n
		   (メンバイニシャライザ)
		*/
		Texture() : texture(nullptr), size(0, 0)
		{
		}

		/** @brief デストラクタ */
		~Texture();

	    /** 
		*@brief コンストラクタ
		*@param[in]id リソース識別ID		
		*/
		Texture(std::string file_naem);

		/**
		*@brief コピーコンストラクタ
		*@param[in]data テクスチャのオブジェクト
		*/
		Texture(const Texture& data);

		/**
		*@brief コピーコンストラクタ@n
		 (代入演算子オーバーロード)
		*@param[in]data テクスチャのオブジェクト
		*/
		Texture& operator=(const Texture& data);

		/**
		*@brief 型変換キャスト@n
		(TextureクラスをLPDIRECT3DTEXTUREとして生成)
		*/
		operator LPDIRECT3DTEXTURE9() const {
			return texture;
		}

		/** @brief 画像サイズゲッター*/
		const Size GetSize() const{
			return size;
		}


	private:
		LPDIRECT3DTEXTURE9 texture;//! テクスチャ保存変数
		Size size;				   //! 画像名
		std::string name;		   //! 画像名
		
	};
}