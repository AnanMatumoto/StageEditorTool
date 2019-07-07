#include "Texture.h"
#include "../DirectX9/DirectX9Device.h"
#include <map>
namespace Lib {

	//--------------------------------
	// コンストラクタ
	Texture* Texture::Create(std::string file_name) {

		D3DXIMAGE_INFO tex_info;
		
		DirectX9Device* device = DirectX9Device::GetInstance();

		if (SUCCEEDED(D3DXGetImageInfoFromFile(
			file_name.c_str(),
			&tex_info))
			) {
			size.x = (float)tex_info.Width;
			size.y = (float)tex_info.Height;
			D3DXCreateTextureFromFileEx(
				device->GetDevice(),
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
			//作成完了
			return this;
		}

		return nullptr;
	}

	//--------------------------------
	// デストラクタ
	Texture::~Texture() {

		if (texture != nullptr) {
			texture->Release();
		}
	}

}