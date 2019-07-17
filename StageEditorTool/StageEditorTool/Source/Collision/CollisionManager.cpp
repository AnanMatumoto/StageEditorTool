#include "CollisionManager.h"
#include "../Object/CollisionObject.h"
#include "../Common/Common.h"
#include "../Calc/Calc.h"
#include <cmath>

void CollisionManager::Entry(CollisionObject* obj) {

	if (obj->GetColliisionType() == POINT_TYPE) {
		m_mouse_obj = obj;
	}
	else {
		m_obj_list.emplace_back(obj);
	}

	m_cur_obj = nullptr;
	/*m_target_list.emplace_back(obj);
	m_source_list.emplace_back(obj);*/
	
}

void CollisionManager::Update() {

	for (auto obj : m_obj_list) {
		//点と矩形が当たれば、その矩形を保存する
		IsPointDuringRect(m_mouse_obj, obj);
	}
	
	if (m_cur_obj == nullptr) {
		return;
	}

	for (auto rect : m_obj_list) {
		//矩形同士の重なりがあるか
		IsOverlapRect(m_cur_obj, rect);
	}

	if (m_cur_obj != nullptr) {
		m_cur_obj->Reflection(m_mouse_obj);
	}
	


	/*for (auto target_ : m_target_list) {
		CollisionObject* target = target_;
		if (target == nullptr) {
			return;
		}

		for (auto source_ : m_source_list) {
			CollisionObject* source = source_;
			if (source == nullptr) {
				return;
			}

			HitObject(target, source);
		}
	}*/
}

void CollisionManager::IsPointDuringRect(
	CollisionObject* point_obj,
	CollisionObject* rect_obj
) {
	PointCollider point;
	RectCollider  rect;

	point_obj->SetCollider(point);
	rect_obj->SetCollider(rect);

	float left = rect.pos.x;
	float right = left + rect.size.x;
	float top = rect.pos.y;
	float bottom = top + rect.size.y;

	if (point.pos.x >= left && point.pos.x <= right) {
		if (point.pos.y >= top && point.pos.y <= bottom) {
			//選択中のオブジェクトを保存
			m_cur_obj = rect_obj;
		}
	}
}

void CollisionManager::IsOverlapRect(
	CollisionObject* select_obj,
	CollisionObject* rect_obj
) {
	RectCollider select;
	RectCollider rect;

	select_obj->SetCollider(select);
	rect_obj->SetCollider(rect);
	
	float x = std::abs(Calc::PowFloat((select.pos.x - rect.pos.x)));
	float y = std::abs(Calc::PowFloat((select.pos.y - rect.pos.y)));
	float distance = x + y;
	float width  = (select.size.x / 2) + (rect.size.x / 2);
	float height = (select.size.y / 2) + (rect.size.y / 2);

	if (width < distance || height < distance) {
	//矩形が重なっている
		if (select.pos.z > rect.pos.z) {
		//ｚ値が対象より背面にある場合
			select_obj->Reflection(rect_obj);
			rect_obj->Reflection(select_obj);
		}
	}
}

