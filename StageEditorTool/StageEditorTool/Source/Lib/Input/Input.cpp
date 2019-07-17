#include "Input.h"
#include "../Window/Window.h"
namespace Lib {

	bool Input::OnMouseDown(int key) {
		if (is_click[key] == true) {
			return true;
		}
		return false;
	}

	bool Input::OnMouseUp(int key) {
		if (is_click[key] == false) {
			return true;
		}
		return false;
	}

	bool Input::CheckHitKey(const BYTE key) {
		//指定したビットが立っていればtrue
		return ((key & 0x80) != 0);
	}

	Vec2 Input::GetMovePoint() {
		Vec2 vec(point[START].x, point[START].y);
		return vec;
	}

	Vec2 Input::GetClickPoint() {
		Vec2 vec(point[END].x, point[END].y);
		return vec;

	}
}

