﻿#include "Input.h"
#include "../Window/Window.h"
namespace Lib {

	void Input::Uodate() {

		memcpy(m_key[KEY_PRE], m_key[KEY_CUR], sizeof(*m_key));
		GetKeyboardState(m_key[KEY_CUR]);
	}

	bool Input::OnMouseDown(int key) {
		return(CheckHitKey(m_key[KEY_CUR][key]));
	}

	bool Input::OnMousePush(int key) {
		return CheckHitKey(m_key[KEY_CUR][key]) &&
			CheckHitKey(m_key[KEY_PRE][key] == false);
	}

	bool Input::OnMouseUp(int key) {
		return CheckHitKey(m_key[KEY_CUR][key] == false) &&
			CheckHitKey(m_key[KEY_PRE][key]);
	}

	bool Input::CheckHitKey(const BYTE key) {
		return ((key & 0x80) != 0);
	}

	Vec2 Input::GetMovePoint() {
		GetCursorPos(&m_move_point);
		ScreenToClient(window_handle, &m_move_point);
		Vec2 vec = {
		 (float)m_move_point.x,
		 (float)m_move_point.y
		};
		return vec;
	}

	Vec2 Input::GetClickPoint(int key) {

		Vec2 vec = { 0,0 };

		if (OnMouseDown(key) || OnMousePush(key)) {
			GetCursorPos(&m_move_point);
			ScreenToClient(window_handle, &m_move_point);
			vec = {
				(float)m_move_point.x,
				(float)m_move_point.y
			};
		}
		return vec;
	}
}

