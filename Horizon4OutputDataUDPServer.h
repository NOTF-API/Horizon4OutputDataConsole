#include<stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include "TelemetryData.h"
#pragma comment(lib , "ws2_32.lib")
#pragma warning (disable:4996)
#define DEFAULT_BUFFER 360 /*缓冲区大小*/
char Buffer[DEFAULT_BUFFER];
int serverStartFlag = 0;

Horizon4TelmetryData* startServer();
void serverWorker();

Horizon4TelmetryData* startServer(){
	memset(Buffer, 0,DEFAULT_BUFFER);
	bindData(Buffer);
	serverStartFlag = 1;
	_beginthread((_beginthread_proc_type)serverWorker, 0, NULL);
	return data;
}

void serverWorker() {
	WSAData wsa;
	if (::WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		MessageBoxW(NULL,TEXT("WSAStartup error"), TEXT("error"),MB_OK);
		serverStartFlag = 0;
		_endthread();
		return;
	}
	//创建socket对象
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	//创建网络通信对象
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//绑定socket对象与通信链接
	int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
	if (0 > ret) {
		MessageBoxW(NULL, TEXT("bind error"), TEXT("error"), MB_OK);
		serverStartFlag = 0;
		_endthread();
		return;
	}
	struct sockaddr_in cli;
	int len = sizeof(cli);
	MessageBoxW(NULL, TEXT("linsten start"), TEXT("success"), MB_OK);
	while (serverStartFlag) {
		int recSize = recvfrom(sockfd, Buffer, DEFAULT_BUFFER, 0, (struct sockaddr*)&cli, &len);
	}
	MessageBoxW(NULL, TEXT("linsten end"), TEXT("info"), MB_OK);
	WSACleanup();
	_endthread();
}