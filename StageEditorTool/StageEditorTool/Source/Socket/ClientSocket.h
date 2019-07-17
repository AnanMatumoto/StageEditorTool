#pragma once
#pragma comment(lib, "Ws2_32.lib")

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <Windows.h>

class ClientSocket {


public:

	static ClientSocket* GetInstance() {
		static ClientSocket instance;
		return &instance;
	}

	bool Start(int port_no);

	bool Connect();

	bool Receive(SOCKET socket);

	void CleanUp();

private:
	int    m_port_no;
	SOCKET m_sock;
	char   m_host_info_buff[MAXGETHOSTSTRUCT];
};

