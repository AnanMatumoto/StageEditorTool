#include "Common.h"
#include <WinSock2.h>
#include <Windows.h>

void ErrorMsg(const char* err_msg) {
	MessageBox(0, err_msg, nullptr, MB_OK);
}