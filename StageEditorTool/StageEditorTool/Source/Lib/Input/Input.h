﻿#pragma once

#include "InputDefinition.h"
#include "../../Common/Vec.h"
#include <WinSock2.h>
#include <Windows.h>

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
		int   m_count = 0;
	};

}

