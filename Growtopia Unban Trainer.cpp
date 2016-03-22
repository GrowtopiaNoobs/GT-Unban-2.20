// Growtopia Unban Trainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <map>
#include <chrono>
#include <mutex>
#include <memory>

using namespace std;

HANDLE hProc;

void gen_random(char *s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	HWND hWnd = FindWindowA(0, "Growtopia");
	if (hWnd == 0){
		cerr << "Growtopia not found. Please run Growtopia and try it again!" << endl;
		_getch();
		return 0;
	}
	DWORD PID;
	GetWindowThreadProcessId(hWnd, &PID);
	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);

	if (!hProc) {
	cerr << "Cannot open process." << endl;
		_getch();
		return 0;
	}
	char newRandVal[100];
	gen_random(newRandVal, 17);
	WriteProcessMemory(hProc, (LPVOID)0x14021B0B1, &newRandVal, (DWORD)17, NULL);
	cout << "Before connecting to growtopia change your MAC with TMAC!" << endl;
	_getch();
	return 0;
}

