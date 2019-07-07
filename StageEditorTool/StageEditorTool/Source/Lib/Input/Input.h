#pragma once

#include "InputDefinition.h"
namespace Lib {

	class Input {

	public:
		Input()
		{
		}

		~Input()
		{
		}

		void Uodate();

		bool OnMouseDown(int key);

		bool OnMouseUp(int key);

		bool OnMousePush(int key);

		bool CheckHitKey(const BYTE key);


	private:

		BYTE m_key[INPUT_FLAME][KEY_NUM];
	};

}

