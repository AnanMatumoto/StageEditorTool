#pragma once

#include "../Collision/CollisionDefinition.h"
#include "../Common/Vec.h"
#include <map>
#include <vector>

class CollisionObject;

class CollisionManager {

public:

	static CollisionManager* GetInstance() {
		static CollisionManager instance;
		return &instance;
	}

	void Entry(CollisionObject* obj);

	void Update();

	void IsPointDuringRect(
		CollisionObject* point,
		CollisionObject* rect);

	//矩形と矩形の当たり判定
	void IsOverlapRect(
		CollisionObject* rect_a,
		CollisionObject* rect_b
	);
	

private:

	std::vector<CollisionObject*>m_obj_list;
	CollisionObject* m_mouse_obj;
	CollisionObject* m_cur_obj;
};


