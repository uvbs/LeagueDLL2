#include <Windows.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include "Hooks.h"
#include "d3d9.h"

void *DetourFunc(BYTE *src, const BYTE *dst, const int len);
bool RetourFunc(BYTE *src, BYTE *restore, const int len);

// Create a console
VOID CreateConsole();

void InitiateHooks() {
	DWORD deathAddy = FindPattern("League of Legends.exe", "\x83\x3D\x00\x00\x00\x00\x00\xC6\x46\x12\x01", "xx?????xxxx");
	//deathAddy += 7;
	//MsgBoxAddr(deathAddy);

	DeathJmpBack = deathAddy + 0xB;

	PlaceJMP((BYTE*)deathAddy, (DWORD)DeathTracker, 11);


	/*DWORD gameTickAddy = 0x00DB06E6; //FindPattern("League of Legends.exe", "\xCC\x81\x04\x30\x00\x00\x00\x00", "xxxx????");
	//MsgBoxAddr(gameTickAddy);

	GameTickJmpBack = gameTickAddy + 0x6;

	PlaceJMP((BYTE*)gameTickAddy, (DWORD)GameTimerTick, 6);*/
}

//Our hacks thread, here we overwrite any values that we take from our hooks
DWORD WINAPI TrackJungle()
{
	/*Loop forever, with a 500 millisecond interval per loop*/
	for (;; Sleep(500))
	{
		GameTimePtr = 0x02274d90;
		if (lastGameTime != GameTimePtr) {
			//printf("Game time is %d\n", *((int *)GameTimePtr));
			system("CLS");
			if (tickcounter == 0) {
				GameJungle = new Jungle();
			}
			GameJungle->UpdateAllCamps(*((int *)GameTimePtr));
			lastGameTime = *((int *)GameTimePtr);
			tickcounter++;
		}
	}

	return 0;
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved)     // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		//MessageBoxA(NULL, "Attached successfuly", "", 0);

		InitiateHooks();
		//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)OverwriteValues, NULL, NULL, NULL);
		CreateConsole();

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)TrackJungle, NULL, NULL, NULL);

		printf("FULLY INJECTERIZED!\n\n");

		break;


		return true;

	}
	// Successful DLL_PROCESS_ATTACH.
	return TRUE;
}

// Create a console (this code is not mine, taken from online)
VOID CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;

	// Allocate a console
	AllocConsole();

	// redirect unbuffered STDOUT to the console
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);

	// redirect unbuffered STDIN to the console
	lStdHandle = GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "r");
	*stdin = *fp;
	setvbuf(stdin, NULL, _IONBF, 0);

	// redirect unbuffered STDERR to the console
	lStdHandle = GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stderr = *fp;
	setvbuf(stderr, NULL, _IONBF, 0);
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len) {
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwback;

	VirtualProtect(src, len, PAGE_READWRITE, &dwback);

	memcpy(jmp, src, len);
	jmp += len;

	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(dst - src) - 5;

	VirtualProtect(src, len, dwback, &dwback);

	return (jmp - len);
}

bool RetourFunc(BYTE *src, BYTE *restore, const int len) {
	DWORD dwback;

	if (!VirtualProtect(src, len, PAGE_READWRITE, &dwback)) { return false; }
	if (!memcpy(src, restore, len))							{ return false; }

	restore[0] = 0xE9;
	*(DWORD*)(restore + 1) = (DWORD)(src - restore) - 5;

	if (!VirtualProtect(src, len, dwback, &dwback))			{ return false; }

	return true;

}