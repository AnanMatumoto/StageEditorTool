#include "CollisionManager.h"
#include "../Object/CollisionObject.h"
#include "../Common/Common.h"

void CollisionManager::Entry(CollisionObject* obj) {

	switch (obj->GetColliisionType())
	{
	case RECT_TYPE:
		m_list.emplace_back(obj);
		break;

	case POINT_TYPE:
		m_pivot_coll = obj;
		break;
	}
}

void CollisionManager::Update() {

	for (auto obj : m_list) {
		
		IsPointDuringRect(m_pivot_coll, obj);
	}
}

void CollisionManager::IsPointDuringRect(
	CollisionObject* point_obj,
	CollisionObject* map_obj
) {
	PointCollider point; 
	RectCollider  rect; 

	point_obj->SetCollider(point);
	map_obj->SetCollider(rect);

	float left   = rect.pos.x;
	float right  = left + rect.size.x;
	float top    = rect.pos.y;
	float bottom = top + rect.size.y;

	if (point.pos.x >= left && point.pos.x <= right) {
		if (point.pos.y >= top && point.pos.y <= bottom){
			//当たった後の反映処理を開始
			ErrorMsg("当たった");
			point_obj->Reflection(map_obj);
			map_obj->Reflection(point_obj);
		}
	}
}