// clientServer.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#undef UNICODE
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "ctpl_stl.h"

using namespace std;
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

ctpl::thread_pool p(10/* two threads in the pool */);

// helper to compute the primality of an unsigned number.
bool __declspec(dllexport)  isPrime(unsigned int n)
{
	// Corner cases
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	// With this check we can skip middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (unsigned int i = 5; i*i <= n; i = i + 6)
		if (n%i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// Computes the primality of the number and writes the result back to the client(socket).
void find_primality_send_result(int id, unsigned num, SOCKET ClientSocket)
{
	//bool result = do_is_prime(id, num);
	bool result = isPrime(num);
	std::string result_s;
	std::cout << "thread id is  " << " socket is " << ClientSocket << " : " << id << ", num is " << num;

	if( result )
	{
		result_s = "true";
	}
	else
	{
		result_s = "false";
	}

	int iSendResult = send(ClientSocket, result_s.c_str() , result_s.length(), 0);
	if (iSendResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
	}
	else
	{
		printf("Bytes sent: %d\n", iSendResult);
	}
	closesocket(ClientSocket);

}

// Assigns the task of computing the primality to the thread pool
void assign_task(unsigned int num_for_primality_test, SOCKET client_socket)
{
	p.push(find_primality_send_result, num_for_primality_test, client_socket);  // function
}

// read the unsigned prime number from the client socket and call assign_task
void get_client_data_assign_task_tp(SOCKET ClientSocket)
{
	unsigned MyInt;
	unsigned NetInt;

	int iResult = recv(ClientSocket, (char *)&NetInt, sizeof(long), 0);
	MyInt = (int)ntohl(NetInt);

	if (iResult > 0) {
		printf("Number received: %u\n", MyInt);
		// primality is calculated, result sent to the client and the client socket is closed
		assign_task(MyInt, ClientSocket);
	}
	else if (iResult == 0)
		printf("Connection closing...\n");
	else {
		printf("recv failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
	}
}

int __declspec(dllexport) start_server()
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = ::bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	SOCKET client_socket;
	while ((client_socket = accept(ListenSocket, NULL, NULL))) {
		if (client_socket == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
		get_client_data_assign_task_tp(client_socket);
	}

	// No longer need server socket
	closesocket(ListenSocket);


	// shutdown the connection since we're done
	iResult = shutdown(client_socket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(client_socket);
	WSACleanup();

	return 0;
}

int __cdecl main(void)
{
	start_server();
}
