#include "Drawer.h"
#include "Lib/Texture/TextureManager.h"
#include "Lib/DirectX9/DirectX9Device.h"
#include "Common/Vertex.h"

#define VERTEX_FVF (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
 void Drawer::Draw2D(
	std::string tex_name,
	float pos_x,
	float pos_y,
	float degree,
	float ofset_x,
	float ofset_y,
	float depth,
	DWORD color
 ) {

	
	Lib::Texture* texture = Lib::TextureManager::GetInstance()->Find(tex_name);
	if( texture == nullptr){
		return;
	}

	Lib::DirectX9Device* device = Lib::DirectX9Device().GetInstance();
	
	float x1 = pos_x - texture->GetSize().x * ofset_x;
	float y1 = pos_y - texture->GetSize().y * ofset_y;
	float x2 = pos_x + texture->GetSize().x *(1.f - ofset_x);
	float y2 = pos_y + texture->GetSize().y* (1.f - ofset_y);

	Vertex vtx[4]=
	{ {{x1,y1,depth,1.f},color,{0.f,0.f}},
	  {{x2,y1,depth,1.f},color,{1.f,0.f}},
	  {{x2,y2,depth,1.f},color,{1.f,1.f}},
	  {{x1,y2,depth,1.f},color,{0.f,1.f}},
	};

	device->GetDevice()->SetTexture(0, *texture);
	device->GetDevice()->SetFVF(VERTEX_FVF);
	device->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
 }