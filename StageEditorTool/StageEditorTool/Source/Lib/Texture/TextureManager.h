#pragma once

#include <unordered_map>
#include <string>
#include "Texture.h"

namespace Lib {


	/**
	*@class テクスチャー管理クラス
	*@brief テクスチャーの登録、削除を行う
	*/
	class TextureManager {

	public:
		/** @brief インスタンス取得関数　*/
		static TextureManager* GetInstance() {
			static TextureManager instance;
			return &instance;
		}

		/**
		*@brief テクスチャー読み込み関数
		*@param[in]tex_name 画像名
		*/
		bool Load(const char* file_name);

		/**
		*@brief テクスチャー検索関数
		*@param[in]tex_name 画像名
		*/
		Texture* Find(std::string tex_name);


		Size GetSize(std::string tex_name);

		/**
		*@brief テクスチャー解放関数
		*@param[in]tex_name　画像名
		*/
		void Release(std::string tex_name);

		/**
		*@brief テクスチャー解放関数
		*/
		void AllRelease();
	private:
		std::unordered_map<std::string, Texture*>m_texture_list; //<! 画像リスト
	};

}