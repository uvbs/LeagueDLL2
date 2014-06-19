#include "Functions.h"
#include <time.h>
#include "Jungle.h"


DWORD DeathJmpBack = 0;
DWORD CurrentObjNamePtr;
DWORD CurrentObj = 0;
Jungle* GameJungle;

void SomethingDied() {
	//char timeStr[9];
	//_strtime(timeStr);
	//printf("%s  -  ", timeStr);
	//CurrentObjNamePtr = CurrentObj + 0x52C;
	//printf("%s just died!\n", (char *)CurrentObjNamePtr);
	//if (!strcmp((char *)CurrentObj + 0x2C, "Object")) {
		if (GameJungle->MonsterToCamp.find((char *)(CurrentObj + 0x570)) != GameJungle->MonsterToCamp.end()) {
			cout << "An object died - " << (char *)(CurrentObj + 0x570) << endl;

			GameJungle->MonsterDied((char *)(CurrentObj + 0x570));
		}
	//}
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

DWORD GameTimePtr;
DWORD GameTickJmpBack;
int tickcounter;
int lastGameTime = -1;
void GameTick() {
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

__declspec(naked) void GameTimerTick() {
	__asm
	{
		INC DWORD PTR DS : [ECX+0x313004]
		MOV GameTimePtr, ECX

		PUSHAD
		PUSHFD
	}

	GameTick();

	__asm
	{
		// Restore everything to how it was before
		POPFD
		POPAD

		jmp [GameTickJmpBack]
	}
}