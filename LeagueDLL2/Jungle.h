#ifndef _JUNGLE_
#define _JUNGLE_

#include <string>
#include "Monster.h"
#include "Camp.h"
#include <time.h> 
#include <set>
#include <map>
#include <assert.h> 

using namespace std;

class Jungle {
public:
	std::map<std::string, Camp*> MonsterToCamp;
	std::set<Camp*> Camps;

	Jungle()
	{
		Camp* campBottomBlue = new Camp("bottomBlue", 115, 300, false);
		campBottomBlue->AddMonster(Monster("AncientGolem1.1.1", false));
		campBottomBlue->AddMonster(Monster("YoungLizard1.1.2", false));
		campBottomBlue->AddMonster(Monster("YoungLizard1.1.3", false));
		MonsterToCamp["AncientGolem1.1.1"] = campBottomBlue;
		MonsterToCamp["YoungLizard1.1.2"] = campBottomBlue;
		MonsterToCamp["YoungLizard1.1.3"] = campBottomBlue;
		Camps.insert(campBottomBlue);

		Camp* campBottomRed = new Camp("bottomRed", 115, 300, false);
		campBottomRed->AddMonster(Monster("LizardElder4.1.1", false));
		campBottomRed->AddMonster(Monster("YoungLizard4.1.2", false));
		campBottomRed->AddMonster(Monster("YoungLizard4.1.3", false));
		MonsterToCamp["LizardElder4.1.1"] = campBottomRed;
		MonsterToCamp["YoungLizard4.1.2"] = campBottomRed;
		MonsterToCamp["YoungLizard4.1.3"] = campBottomRed;
		Camps.insert(campBottomRed);

		/*Camp* bottomWolves = new Camp("bottomWolves", 125, 50, false);
		bottomWolves->AddMonster(Monster("GiantWolf2.1.3", false));
		bottomWolves->AddMonster(Monster("wolf2.1.1", false));
		bottomWolves->AddMonster(Monster("wolf2.1.2", false));
		MonsterToCamp["GiantWolf2.1.3"] = bottomWolves;
		MonsterToCamp["wolf2.1.1"] = bottomWolves;
		MonsterToCamp["wolf2.1.2"] = bottomWolves;
		Camps.insert(bottomWolves);
	
		Camp* bottomWraiths = new Camp("bottomWraiths", 125, 50, false);
		bottomWraiths->AddMonster(Monster("Wraith3.1.1", false));
		bottomWraiths->AddMonster(Monster("LesserWraith3.1.2", false));
		bottomWraiths->AddMonster(Monster("LesserWraith3.1.3", false));
		MonsterToCamp["Wraith3.1.1"] = bottomWraiths;
		MonsterToCamp["LesserWraith3.1.2"] = bottomWraiths;
		MonsterToCamp["LesserWraith3.1.3"] = bottomWraiths;
		Camps.insert(bottomWraiths);

		Camp* campBottomGolems = new Camp("bottomGolems", 125, 50, false);
		campBottomGolems->AddMonster(Monster("Golem5.1.2", false));
		campBottomGolems->AddMonster(Monster("SmallGoem5.1.1", false));
		MonsterToCamp["Golem5.1.2"] = campBottomGolems;
		MonsterToCamp["SmallGolem5.1.1"] = campBottomGolems;
		Camps.insert(campBottomGolems);*/

		Camp* campTopBlue = new Camp("topBlue", 115, 300, false);
		campTopBlue->AddMonster(Monster("AncientGolem7.1.1", false));
		campTopBlue->AddMonster(Monster("YoungLizard7.1.2", false));
		campTopBlue->AddMonster(Monster("YoungLizard7.1.3", false));
		MonsterToCamp["AncientGolem7.1.1"] = campTopBlue;
		MonsterToCamp["YoungLizard7.1.2"] = campTopBlue;
		MonsterToCamp["YoungLizard7.1.3"] = campTopBlue;
		Camps.insert(campTopBlue);


		Camp* campTopRed = new Camp("topRed", 115, 300, false);
		campTopRed->AddMonster(Monster("LizardElder10.1.1", false));
		campTopRed->AddMonster(Monster("YoungLizard10.1.2", false));
		campTopRed->AddMonster(Monster("YoungLizard10.1.3", false));
		MonsterToCamp["LizardElder10.1.1"] = campTopRed;
		MonsterToCamp["YoungLizard10.1.2"] = campTopRed;
		MonsterToCamp["YoungLizard10.1.3"] = campTopRed;
		Camps.insert(campTopRed);

		/*Camp* topWolves = new Camp("topWolves", 125, 50, false);
		topWolves->AddMonster(Monster("GiantWolf8.1.3", false));
		topWolves->AddMonster(Monster("wolf8.1.1", false));
		topWolves->AddMonster(Monster("wolf8.1.2", false));
		MonsterToCamp["GiantWolf8.1.3"] = topWolves;
		MonsterToCamp["wolf8.1.1"] = topWolves;
		MonsterToCamp["wolf8.1.2"] = topWolves;
		Camps.insert(topWolves);

		Camp* topWraiths = new Camp("topWraiths", 125, 50, false);
		topWraiths->AddMonster(Monster("Wraith9.1.1", false));
		topWraiths->AddMonster(Monster("LesserWraith9.1.2", false));
		topWraiths->AddMonster(Monster("LesserWraith9.1.3", false));
		MonsterToCamp["Wraith9.1.1"] = topWraiths;
		MonsterToCamp["LesserWraith9.1.2"] = topWraiths;
		MonsterToCamp["LesserWraith9.1.3"] = topWraiths;
		Camps.insert(topWraiths);

		Camp* campTopGolems = new Camp("topGolems", 125, 50, false);
		campTopGolems->AddMonster(Monster("Golem11.1.2", false));
		campTopGolems->AddMonster(Monster("SmallGoem11.1.1", false));
		MonsterToCamp["Golem11.1.2"] = campTopGolems;
		MonsterToCamp["SmallGolem11.1.1"] = campTopGolems;
		Camps.insert(campTopGolems);*/

		Camp* campDragon = new Camp("dragon", 150, 360, false);
		campDragon->AddMonster(Monster("Dragon6.1.1", false));
		MonsterToCamp["Dragon6.1.1"] = campDragon;
		Camps.insert(campDragon);

		Camp* campBaron = new Camp("baron", 900, 420, false);
		campBaron->AddMonster(Monster("Worm12.1.1", false));
		MonsterToCamp["Worm12.1.1"] = campBaron;
		Camps.insert(campBaron);
		printf("Jungle Initialized\n");
	}

	void MonsterDied(std::string monster) {
		Camp* currCamp = MonsterToCamp[monster];
		currCamp->MonsterDied(monster);
		//assert(!currCamp->CampToMonster[monster].IsActive);
		MonsterToCamp[monster] = currCamp;
		//assert(MonsterToCamp[monster]->CampToMonster[monster].IsActive);
	}


	void UpdateAllCamps(int currentTime) {
		//printf("UpdateAllChamps(%d)", currentTime);
		for (std::set<Camp*>::iterator it = Camps.begin(); it != Camps.end(); ++it) {
			Camp* currCamp = (Camp*)(*it);
			int ret = currCamp->Update(currentTime);
			/*if (ret <= 0) {
				printf("%s is alive!!!", currCamp.CampName);
			}
			else {
				printf("%s will respawn in %d", currCamp.CampName, ret);
			}*/
		}
	}
};
#endif