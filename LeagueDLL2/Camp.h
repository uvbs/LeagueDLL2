#ifndef _CAMP_
#define _CAMP_

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
	bool IsActiveCamp;
	std::string CampName;

	Camp() { }

	Camp(std::string campName, int firstRespawnSecs, int respawnLengthSecs, bool isActive) {
		CampName = campName;
		FirstRespawnSecs = firstRespawnSecs;
		RespawnLengthSecs = respawnLengthSecs;
		IsActiveCamp = isActive;
	}

	bool operator<(const Camp& rhs) const
	{
		return CampName < rhs.CampName;  //assume that you compare the record based on a
	}

	void MonsterDied(std::string monster) {
		CampToMonster[monster].IsActive = false;
	}

	void AddMonster(Monster monster) {
		CampToMonster[monster.Name] = monster;
	}

	void Activate() {
		for (std::map<std::string, Monster>::iterator it = CampToMonster.begin(); it != CampToMonster.end(); ++it) {
			Monster currMonst = (Monster)it->second;
			currMonst.IsActive = true;
			CampToMonster[currMonst.Name] = currMonst;
		}
	}

	bool IsCampActive() {
		bool isCampActive = false;
		for (std::map<std::string, Monster>::iterator it = CampToMonster.begin(); it != CampToMonster.end(); ++it) {
			isCampActive |= it->second.IsActive;
		}
		return isCampActive;
	}

	int Update(int currentTime) {
		//cout << "Trying to update " << CampName << " currentTime " << currentTime << " FirstRespawnSecs " << FirstRespawnSecs << "\n";
		
		if (currentTime >= 0) {
			if (currentTime <= FirstRespawnSecs) {
				if (FirstRespawnSecs - currentTime == 0) {
					Activate();
					// So we fool ourself into thinking
					// they've passed a respawn time and
					// need to watch for the camp dieing.
					NextRespawnSecs = currentTime -1;
				}

				cout << CampName << " will respawn in " << FirstRespawnSecs - currentTime << " seconds\n";
			}
			else {
				if (NextRespawnSecs - currentTime == 0) {
					Activate();
					cout << CampName << " is alive!!!\n";
					return 0;
				}
				else if (NextRespawnSecs - currentTime <= 0) {
					if (!IsCampActive()) {
						NextRespawnSecs = currentTime + RespawnLengthSecs - 1;
						cout << CampName << " will respawn in " << NextRespawnSecs - currentTime << " seconds\n";
						return 0;
					}
					else {
						cout << CampName << " is alive!!!\n";
						return 0;
					}
				}
				cout << CampName << " will respawn in " << NextRespawnSecs - currentTime << " seconds\n";
				return NextRespawnSecs - currentTime;
			}
		}
	}		
};
#endif //_CAMP_