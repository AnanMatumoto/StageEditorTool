#pragma once

#include "../Common/Vec.h"
#include <map>
#include <vector>

class CollisionObject;
class ResourceObject;
class SpriteObject;

class CollisionManager {

public:

	static CollisionManager* GetInstance() {
		static CollisionManager instance;
		return &instance;
	}

	void Entry(CollisionObject* obj);

	void Update();

	bool IsPointDuringRect(
		CollisionObject* point,
		CollisionObject* rect);

	//矩形と矩形の当たり判定
	void IsOverlapRect(
		CollisionObject* rect_a,
		CollisionObject* rect_b
	);

	void Clear();
	
private:

	std::vector<CollisionObject*>m_obj_list;
	std::vector<CollisionObject*>m_resource_list;
	CollisionObject* m_mouse_obj;
	CollisionObject* m_select_obj;
	bool m_is_select;
};


