#pragma once

#include "ResourceID.h"
#include <map>
#include <string>
//====================================
// リソース名読み込みクラス
//====================================

namespace Lib {

	class ResourceNameLoader {

	public:
		/** 
		*@brief インスタンス取得関数
		*@return ResourceNameLoaderのオブジェクト
		*/
		static ResourceNameLoader* GetInstance() {
			static ResourceNameLoader instance;
			return &instance;
		}

		/** @brief 画像名読み込み関数 */
		void LoadName();

		/** 
		*@brief 画像名取得関数
		*@param[in]id リソース識別ID
		*@return IDと対応する画像名
		*/
		std::string GetName(ResourceID id);

	private:
		std::map<ResourceID, std::string> m_list;
	};

}