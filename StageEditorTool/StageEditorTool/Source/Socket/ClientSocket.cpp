//#include "ClientSocket.h"
//#include "SokcketDefinition.h"
//#include "../Common/Common.h"
//#include "../Lib/Window/Window.h"
//#include "../Editor/Editor.h"
//
//#include <windowsx.h>
//
//bool ClientSocket::Start(int port_no) {
//
//	WORD version_reqested = MAKEWORD(1, 1);
//	WSADATA wsa_data;
//
//	int result =WSAStartup(version_reqested, &wsa_data);
//	if (result == SOCKET_ERROR) {
//		return false;
//	}
//	m_port_no = port_no;
//	m_sock = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
//	//ソケットの生成に失敗した場合
//	if (m_sock == INVALID_SOCKET) {
//		return false;
//	}
//	
//	//ホスト情報の取得
//	WSAAsyncGetHostByName(
//		FindWindow(Lib::WINDOW_CLASS_NAME, nullptr),
//		WmServerName,         //通知するメッセージ
//		"loaclhost",            //ホスト情報を取得するサーバー名
//		(char*)m_host_info_buff,//ホスト情報を格納するバッファ
//		HostInfoBuffSize		//バッファのサイズ
//	);
//
//	return  true;
//
//}
//
//bool ClientSocket::Connect() {
//
//	LPHOSTENT host= NULL;
//	unsigned int addr;
//	SOCKADDR_IN socket_addr;
//
//	host = (LPHOSTENT)m_host_info_buff;
//	memset(&socket_addr, 0, sizeof(SOCKADDR_IN));
//	
//	//接続先の情報が入っている場合
//	if (host->h_name != nullptr&&
//		host->h_addr_list != nullptr)
//	{
//		socket_addr.sin_family = AF_INET;
//		socket_addr.sin_port = htons(m_port_no);
//		//複数のアドレスの中から最初のアドレスを選択
//		socket_addr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
//	}
//
//	/*サーバーのソケットと接続する*/
//	//接続に失敗した場合
//	if (connect(m_sock, 
//				(SOCKADDR*)&socket_addr,
//				sizeof(socket_addr)) == SOCKET_ERROR
//	) {
//		ErrorMsg("サーバとの接続に失敗しました。");
//		return false;
//	}
//
//	//ネットワークイベント通知の設定
//	if (WSAAsyncSelect(
//		m_sock,
//		FindWindow(Lib::WINDOW_CLASS_NAME, nullptr),
//		WmAsync,
//		FD_CONNECT | FD_READ | FD_CLOSE
//		//接続の確立・読み取り可能・ソケットが閉じられた場合のイベントを通知する
//	)){
//		closesocket(m_sock);
//		return false;
//	}
//	return true;
//}
//
//bool ClientSocket::Receive(SOCKET socket) {
//
//	char buff[1024];
//	memset(buff, 0, sizeof(char) * 1024);
//
//	if (socket != m_sock) {
//		return false;
//	}	
//	int ret = recv(socket, buff, 1024, 0);
//	if (ret == SOCKET_ERROR) {
//		ErrorMsg("データの受信に失敗しました。");
//		return false;
//	}
//	
//	Editor::GetInstance()->Recive(buff);
//	return true;
//}	
//
//void ClientSocket::CleanUp() {
//
//	shutdown(m_sock, SD_BOTH);
//
//	if (m_sock != 0 && m_sock != INVALID_SOCKET) {
//		closesocket(m_sock);
//	}
//	WSACleanup();
//}