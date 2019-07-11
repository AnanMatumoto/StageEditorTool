#pragma once

#include "../Collision/CollisionDefinition.h"
#include "../Common/Vec.h"
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
		CollisionObject* rect
	);


private:
	CollisionObject* m_pivot_coll;
	std::vector<CollisionObject*> m_list;

	
};


