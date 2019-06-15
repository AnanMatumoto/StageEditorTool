#include "ResourceNameLoader.h"

namespace Lib {
	
	//----------------------------
	//画像名読み込み関数
	void ResourceNameLoader::LoadName() {



	}

	//-----------------------------
	//画像名取得関数
	std::string ResourceNameLoader::GetName(ResourceID id) {

		auto res = m_list.find(id);
		if (res != m_list.end()) {
			return res->second;
		}
		return nullptr;
	}
}
