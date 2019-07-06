#pragma once
#include "../Lib/Lib.h"

//=========================
//　頂点の定義
//=========================
struct  Vertex
{
	D3DXVECTOR4 pos;  //描画座標
	DWORD       color;//色相
	D3DXVECTOR2 uv;   //テクスチャー座標
};
