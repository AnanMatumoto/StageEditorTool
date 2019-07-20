#pragma once

#include "../Lib/Texture/Texture.h"
#include "../Lib/DirectX9/DirectX9Device.h"
#include <map>
#include <string>

class Drawer {

public:

	Drawer();

	void Draw2D(
		std::string tex_name,
		float pos_x,
		float pos_y,
		float depth = 1.f,
		float degree = 0.f,
		float ofset_x = 0.5f,
		float ofset_y = 0.5f,
		DWORD color = 0x00ffffff
	);

	~Drawer() {
		delete m_tex;
	}

private:
	Lib::Texture* m_tex;

};