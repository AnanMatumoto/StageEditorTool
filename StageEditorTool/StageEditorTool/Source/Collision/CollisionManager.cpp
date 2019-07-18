#include "CollisionManager.h"
#include "../Object/CollisionObject.h"
#include "../Common/Common.h"
#include "../Calc/Calc.h"
#include "../Editor/Editor.h"
#include <cmath>

void CollisionManager::Entry(CollisionObject* obj) {

	if (obj->GetColliisionType() == POINT_TYPE) {
		m_mouse_obj = obj;
	}
	else {
		m_obj_list.emplace_back(obj);
	}
	m_select_obj = nullptr;
}

void CollisionManager::Update() {

	for (auto obj : m_obj_list) {

		if (obj == nullptr) {
			continue;
		}
		if (m_select_obj != nullptr) {
			if (m_select_obj->GetSelect()) {
				break;
			}
		}

		//点と矩形の当たり
		if (IsPointDuringRect(m_mouse_obj, obj)==true) {
			m_select_obj = Editor::GetInstance()->GetDragObject();
		}
		
		
	}
	
	if (m_select_obj != nullptr) {
		for (auto rect : m_obj_list) {
			//矩形同士の重なりがあるか
			if (rect == nullptr) {
				continue;
			}
			IsOverlapRect(m_select_obj, rect);
		}
	}
}

bool CollisionManager::IsPointDuringRect(
	CollisionObject* point_obj,
	CollisionObject* rect_obj
) {
	PointCollider point;
	RectCollider  rect;
	
	if (point_obj == nullptr || rect_obj == nullptr) {
		return false;
	}

	point_obj->SetCollider(point);
	rect_obj->SetCollider(rect);

	float left   = rect.pos.x;
	float right  = left + rect.size.x;
	float top    = rect.pos.y;
	float bottom = top + rect.size.y;

	if (point.pos.x >= left && point.pos.x <= right) {
		if (point.pos.y >= top && point.pos.y <= bottom) {
			rect_obj->Reflection(point_obj);
			return true;
		}
	}
	return false;
}

void CollisionManager::IsOverlapRect(
	CollisionObject* select_obj,
	CollisionObject* rect_obj
) {
	RectCollider select;
	RectCollider rect;
	
	if (select_obj->IsDelete() || rect_obj->IsDelete()) {
		return;
	}
	select_obj->SetCollider(select);
	rect_obj->SetCollider(rect);
	
	float x = std::abs(Calc::PowFloat((select.pos.x - rect.pos.x)));
	float y = std::abs(Calc::PowFloat((select.pos.y - rect.pos.y)));
	float distance = x + y;
	float width  = (select.size.x / 2) + (rect.size.x / 2);
	float height = (select.size.y / 2) + (rect.size.y / 2);

	if (width < distance || height < distance) {
	//矩形が重なっている
		select_obj->Reflection(rect_obj);
	}
}

void CollisionManager::Clear() {
	m_obj_list.clear();
}