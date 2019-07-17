#include "DirectX9Device.h"

namespace Lib {

	//------------------------------
	//DirectX9の初期化
	bool DirectX9Device::Init(
		int width,
		int height,
		bool is_full_screen
	) {
		memset(&m_param, 0, sizeof(D3DPRESENT_PARAMETERS));
		m_interface = Direct3DCreate9(D3D_SDK_VERSION);
		if (m_interface == nullptr) {
			return false;
		}

		//PRESENT_PARAMETERの設定
		m_param.BackBufferCount  = 1;
		m_param.BackBufferFormat = D3DFMT_A8R8G8B8;//ARGB 8ビット
		m_param.hDeviceWindow    = window_handle;
		m_param.EnableAutoDepthStencil = TRUE;
		m_param.AutoDepthStencilFormat = D3DFMT_D24S8;
		m_param.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;

		if(is_full_screen == true){
			m_param.Windowed         = FALSE; 
			m_param.BackBufferWidth  = 1920;
			m_param.BackBufferHeight = 1080;
			m_param.FullScreen_RefreshRateInHz = 60.f;
		}
		else{
			m_param.Windowed         = TRUE;
			m_param.BackBufferWidth  = width;
			m_param.BackBufferHeight = height;
			m_param.FullScreen_RefreshRateInHz = 0;//ウィンドウモードの場合は０固定
		}
		m_param.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_param.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
		
		if (CreateDevice()== false) {
			return false;
		}

		return true;
	}

	//---------------------------------
	//デバイスの生成処理
	bool DirectX9Device::CreateDevice() {

		//デバイスの作成が成功したか
		if (FAILED(m_interface->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			window_handle,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&m_param,
			&m_device))
		) {
			return false;
		}
		return true;
	}

	//-----------------------------------
	//描画の開始処理
	void DirectX9Device::DrawStart(DWORD back_color) {
		
		//バッファのクリア
		m_device->Clear(
			0, nullptr,
			D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
			back_color,
			1.0f, 0
		);
		//描画開始
		m_device->BeginScene();
	}

	//-----------------------------------
	//描画の終了処理
	void DirectX9Device::DrawEnd() {
		//描画終了
		m_device->EndScene();
		m_device->Present(
			nullptr,
			nullptr,
			nullptr,
			nullptr);
	}

	//--------------------------------
	//DirectX9インターフェース解放処理
	void DirectX9Device::Release() {

		if (m_interface) {
			m_interface->Release();
			m_interface = nullptr;
		}

		if (m_device) {
			m_device->Release();
			m_device = nullptr;
		}
	}

};