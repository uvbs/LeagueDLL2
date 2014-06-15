#include <Windows.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include "Hooks.h"


// Create a console
VOID CreateConsole();

void InitiateHooks() {
	DWORD deathAddy = FindPattern("League of Legends.exe", "\x83\x3D\x00\x00\x00\x00\x00\xC6\x46\x12\x01", "xx?????xxxx");
	//deathAddy += 7;
	//MsgBoxAddr(deathAddy);

	DeathJmpBack = deathAddy + 0xB;

	PlaceJMP((BYTE*)deathAddy, (DWORD)DeathTracker, 11);


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

		printf("FULLY INJECTERIZED!\n\n");

		break;
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