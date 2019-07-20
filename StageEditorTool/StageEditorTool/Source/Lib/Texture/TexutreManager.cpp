#include "TextureManager.h"
#include "../../File/File.h"
namespace Lib {

	//---------------------------------
	//テクスチャー読み込み処理
	bool TextureManager::Load(const char* file_name) {

		/*if (m_texture_list.count(tex_name) > 0) {
			return false;
		}
		Texture* texture = new Texture();
		texture->Create(tex_name);


		if (texture == nullptr) {
			return false;
		}
		m_texture_list.emplace(tex_name, texture);*/
		std::vector<std::string>texture_list;
		if (File::InputTextureData(file_name, texture_list) == false) {
			return false;
		}

		for (auto tex_name : texture_list) {
			Texture* texture = new Texture();
			texture->Create(tex_name);
			if (texture != nullptr) {
				m_texture_list.emplace(tex_name,texture);
			}
		}
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

	Size TextureManager::GetSize(std::string tex_name) {
		
		Size size(0, 0);
		auto itr = m_texture_list.find(tex_name);
		if (itr != m_texture_list.end()) {
		    size = itr->second->GetSize();
			return size;
		}
		return size;
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
			if (tex != nullptr) {
				delete tex;
				//要素を削除
				itr = m_texture_list.erase(itr);
			}
			++itr;
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