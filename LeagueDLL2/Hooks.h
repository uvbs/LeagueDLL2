#include "Functions.h"
#include <time.h>

DWORD DeathJmpBack = 0;
DWORD CurrentObjNamePtr;
DWORD CurrentObj = 0;

void SomethingDied() {
	char timeStr[9];
	_strtime(timeStr);
	printf("%s  -  ", timeStr);
	CurrentObjNamePtr = CurrentObj + 0x52C;
	printf("%s just died!\n", (char *)CurrentObjNamePtr);
}

__declspec(naked) void DeathTracker() {
	__asm
	{
		CMP DWORD PTR DS:[0x2BAD6B8], 0
		MOV [ESI+0x12], 1
		MOV CurrentObj, ESI
		// Remember that we need to preserve registers and the stack!
		PUSHAD
		PUSHFD
	}

	SomethingDied();

	__asm
	{
		// Restore everything to how it was before
		POPFD
		POPAD

		jmp [DeathJmpBack]
	}
}