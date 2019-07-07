#include "Input.h"


namespace Lib {

	void Input::Uodate() {
		memcpy(m_key[KEY_PRE], m_key[KEY_CUR], sizeof(*m_key));
		GetKeyboardState(m_key[KEY_CUR]);
	}

	bool Input::OnMouseDown(int key) {
		return CheckHitKey(m_key[KEY_CUR][key]);
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
}

