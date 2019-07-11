#pragma once

#include "InputDefinition.h"
#include "../../Common/Vec.h"

namespace Lib {

	class Input {

	public:

		static Input* GetInstance() {
			static Input instance;
			return &instance;
		}

		void Uodate();

		bool OnMouseDown(int key);

		bool OnMouseUp(int key);

		bool OnMousePush(int key);

		bool CheckHitKey(const BYTE key);

		 Vec2 GetMovePoint();

		 Vec2 GetClickPoint(int key);

	private:

		BYTE  m_key[INPUT_FLAME][KEY_NUM];
		POINT m_move_point;
		POINT m_click_point;
	};

}

