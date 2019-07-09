#include "Input.h"
#include <Windows.h>

namespace Lib {


	void Input::Uodate() {
		GetCursorPos(&m_move_point);
		memcpy(m_key[KEY_PRE], m_key[KEY_CUR], sizeof(*m_key));
		GetKeyboardState(m_key[KEY_CUR]);
	}

	bool Input::OnMouseDown(int key) {
		return(CheckHitKey(m_key[KEY_CUR][key]));
	}

	bool Input::OnMousePush(int key) {
		return CheckHitKey(m_key[KEY_CUR][key]) &&
			CheckHitKey(m_key[KEY_PRE][key]==false);
	}

	bool Input::OnMouseUp(int key) {
		return CheckHitKey(m_key[KEY_CUR][key] == false) &&
			CheckHitKey(m_key[KEY_PRE][key]);
	}

	bool Input::CheckHitKey(const BYTE key) {
		return ((key & 0x80) != 0);
	}

	Vec2 Input::GetClickPoint(int key) {

		Vec2 vec = { 0,0 };
		if (OnMouseDown(key)|| OnMousePush(key)){
			m_click_point = m_move_point;
			vec.x = (float)m_click_point.x;
			vec.y = (float)m_click_point.y;
		}
		return vec;
	}
}

