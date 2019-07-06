#include "TextureManager.h"

namespace Lib {

	//---------------------------------
	//テクスチャー読み込み処理
	bool TextureManager::Load(std::string tex_name) {

		if (m_texture_list.count(tex_name) > 0) {
			//登録済である場合
			return true;
		}
		
		Texture* texture = new Texture();
		texture->Create(tex_name);
		if (texture == nullptr) {
			return false;
		}
		//登録完了
		m_texture_list.emplace(tex_name, texture);
		return true;
	}

	//---------------------------------
	//テクスチャー検索処理
	Texture* TextureManager::Find(std::string tex_name) {
		
		auto itr = m_texture_list.find(tex_name);
		if (itr != m_texture_list.end()) {
			return itr->second;
		}
		return nullptr;
	}

	void TextureManager::Release(std::string tex_name) {
		
		//リスト内に指定された画像が無い場合
		if (m_texture_list.count(tex_name) == 0) {
			return;
		}

		auto itr = m_texture_list.find(tex_name);
		if (itr != m_texture_list.end()) {
			//値を削除
			Texture* tex = itr->second;
			if (tex == nullptr) {
				return;
			}
			delete tex;
			//要素を削除
			m_texture_list.erase(itr);
		}
	}

	void TextureManager::AllRelease() {

		if (m_texture_list.empty()) {
			return;
		}

		for (auto itr : m_texture_list) {
			Texture* tex = itr.second;
			if (tex == nullptr) {
				continue;
			}
			delete tex;
		}
		m_texture_list.clear();
	}

}