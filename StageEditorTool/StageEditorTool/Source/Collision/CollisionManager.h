#pragma once

#include "../Common/Vec.h"

class CollisionObject;

class CollisionManager {

public:

	static CollisionManager* GetInstance() {
		static CollisionManager instance;
		return &instance;
	}

	void IsPointDuringRect(
		CollisionObject* obj,
		CollisionObject* target
	);



private:
	

	
};


