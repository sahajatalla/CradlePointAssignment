// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <iostream>
#include <chrono>
#include <random>
int __declspec(dllimport) excercise_server(char *host);
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


int __cdecl main(int argc, char **argv)
{
	return excercise_server(argv[1]);
}

