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

		bool OnMouseDown(int key);

		bool OnMouseUp(int key);

		bool OnMousePush(int key);

		bool CheckHitKey(const BYTE key);

		 Vec2 GetMovePoint();

		 Vec2 GetClickPoint();

	private:

		BYTE  m_key[INPUT_FLAME][KEY_NUM];
		POINT m_move_point;
		POINT m_click_point;
	};

}

