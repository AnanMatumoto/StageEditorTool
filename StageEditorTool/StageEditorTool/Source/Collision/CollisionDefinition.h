#pragma once

//=============================
//  衝突の種類
//=============================
enum  CollisionType{

	RECT_TYPE=1,
	CIRCLE_TYPE,
	POINT_TYPE,
};

enum CollisionMode {

	SELECT_MODE,
	LAYOUT_MODE
};

enum ObjectType {

	RESOURCE,
	MOUSE,
	MAP,
};