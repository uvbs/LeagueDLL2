#include <string>
#include "Monster.h"
#include <time.h> 
#include <map>

using namespace std;

class Camp {
public:
	std::map<std::string, Monster> MonsterMap;
	clock_t DeathTimeStart;
	int RespawnSecsLength;
	bool IsActive;
	std::string CampName;

	Camp() { }

	Camp(std::string campName, clock_t deathTimeStart, int respawnSecsLength, bool isActive) {
		CampName = campName;
		DeathTimeStart = deathTimeStart;
		RespawnSecsLength = respawnSecsLength;
		IsActive = isActive;
	}

	void AddMonster(Monster monster) {
		MonsterMap[monster.Name] = monster;
	}
};
