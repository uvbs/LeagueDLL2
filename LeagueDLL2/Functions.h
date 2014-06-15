#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <Psapi.h>

void MsgBoxAddr(DWORD addr) {
	char szBuffer[1024];
	sprintf_s(szBuffer, "Addr: %02x", addr);
	MessageBox(NULL, szBuffer, "Title", MB_OK);
}

void PlaceJMP(BYTE *address, DWORD jumptTo, DWORD length = 5) {
	DWORD dwOldProtect, dwBkup, dwRelAddr;

	// Elevate permissions & remember old
	VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// Calculate ((distance we're gonna jump) - (size of the jmp instruction))
	dwRelAddr = (DWORD)(jumptTo - (DWORD)address) - 5;

	// JMP opcode @ jump positions
	*address = 0xE9;

	// Offset we're going to jump to
	*((DWORD *)(address + 0x1)) = dwRelAddr;

	for (DWORD x = 0x5; x < length; x++) {
		*(address + x) = 0x90;
	}

	// Restore old permissions
	VirtualProtect(address, length, dwOldProtect, &dwBkup);
}

MODULEINFO GetModuleInfo(char *szModule) {
	MODULEINFO modinfo = { 0 };
	
	HMODULE hModule = GetModuleHandle(szModule);

	if (hModule == 0) {
		return modinfo;
	}

	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));

	return modinfo;
}

DWORD FindPattern(char *module, char *pattern, char *mask) {
	MODULEINFO mInfo = GetModuleInfo(module);

	DWORD base = (DWORD)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;


	DWORD patternLength = (DWORD)strlen(mask);

	bool found = true;
	for (DWORD i = 0; i < size - patternLength; i++) {
		found = true;
		for (DWORD j = 0; j < patternLength; j++) {
			found &= (mask[j] == '?') || (pattern[j] == *(char*)(base + i + j));
		}

		if (found) {
			return base + i;
		}
	}	

	return NULL;
}