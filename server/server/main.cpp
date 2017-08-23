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
int __declspec(dllimport) start_server();
int __cdecl main(void)
{
	start_server();
}