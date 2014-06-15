#include <string>
#include "Monster.h"
#include <time.h> 
#include <map>

using namespace std;

class Camp {
public:
	std::map<std::string, Monster> CampToMonster;
	clock_t DeathTimeStart;
	int RespawnLengthSecs;
	int FirstRespawnSecs;
	int NextRespawnSecs;
	bool IsActive;
	std::string CampName;

	Camp() { }

	Camp(std::string campName, int firstRespawnSecs, int respawnLengthSecs, bool isActive) {
		CampName = campName;
		FirstRespawnSecs = firstRespawnSecs;
		RespawnLengthSecs = respawnLengthSecs;
		IsActive = isActive;
	}

	void AddMonster(Monster monster) {
		CampToMonster[monster.Name] = monster;
	}

	void Activate() {
		for (std::map<std::string, Monster>::iterator it = CampToMonster.begin(); it != CampToMonster.end(); ++it)
			it->second.IsActive = true;
	}

	bool IsCampActive() {
		bool isCampActive = false;
		for (std::map<std::string, Monster>::iterator it = CampToMonster.begin(); it != CampToMonster.end(); ++it)
			isCampActive |= it->second.IsActive;
		return isCampActive;
	}

	int Update(int currentTime) {
		if (currentTime <= FirstRespawnSecs) {
			if (FirstRespawnSecs - currentTime == 0) {
				Activate();
				// So we fool ourself into thinking
				// they've passed a respawn time and
				// need to watch for the camp dieing.
				NextRespawnSecs = currentTime;
			}

			return FirstRespawnSecs - currentTime;
		} else {
			if (NextRespawnSecs - currentTime == 0) {
				Activate();
			}
			else if (NextRespawnSecs - currentTime <= 0) {
				if (!IsCampActive) {
					NextRespawnSecs = currentTime + RespawnLengthSecs;
				}
			}

			return NextRespawnSecs - currentTime;
		}
	}		
};
