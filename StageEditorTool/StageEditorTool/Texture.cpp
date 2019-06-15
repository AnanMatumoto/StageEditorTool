#include "Texture.h"
#include "ResourceNameLoader.h"
#include <map>
namespace Lib {

	std::map<std::string, Texture> tex_list;

	//--------------------------------
	// コンストラクタ
	Texture::Texture(std::string file_name) {

		auto it = tex_list.find(file_name);

		if (it != tex_list.end()) {//既にリストに存在する場合
			
			texture = it->second;
			if (texture != nullptr) {
				//参照カウンタをインクリメント
				texture->AddRef();
			}
			size = it->second.size;
		}
		else {//リストに存在しない場合
			D3DXIMAGE_INFO tex_info;
			if (SUCCEEDED(D3DXGetImageInfoFromFile(
				file_name.c_str(),
				&tex_info))
			) {
				size.x = (float)tex_info.Width;
				size.y = (float)tex_info.Height;
				D3DXCreateTextureFromFileEx(
					Lib::GetDevice(),
					file_name.c_str(),
					0, 0, 0, 0,		   // 画像ファイルから取得
					D3DFMT_A8R8G8B8,
					D3DPOOL_MANAGED,
					D3DX_FILTER_LINEAR,//フィルタリング指定（中間色）
					D3DX_FILTER_LINEAR,
					NULL,			   //カラーキー（指定なし）
					&tex_info,
					nullptr,
					&texture
				);
				tex_list.emplace(file_name.c_str(), *this);
			}
		}
	}

	//---------------------------------
	// コピーコンストラクタ
	Texture::Texture(const Texture& data):
		texture(data.texture),
		size(data.size),
		name(data.name)
	{
		if (texture != nullptr) {
			//参照カウンタをインクリメント
			texture->AddRef();
		}
	}

	//--------------------------------
	// オーバーロード
	Texture& Texture::operator=(const Texture& data) {
		
		if (texture != nullptr) {
			texture->Release();
			//前回のデータを削除
		}
		texture = data.texture;

		if (texture != nullptr) {
			texture->AddRef();
			//新しいデータを追加し参照カウンタを増やす
		}
		size = data.size;
		name = data.name;
		return *this;
	}
	//--------------------------------
	// デストラクタ
	Texture::~Texture() {

		if (texture != nullptr) {
			texture->Release();
		}
	}

}