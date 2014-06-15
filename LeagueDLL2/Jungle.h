#include <string>
#include "Monster.h"
#include "Camp.h"
#include <time.h> 
#include <set>
#include <map>

using namespace std;

class Jungle {
public:
	std::map<std::string, Camp> MonsterToCamp;

	Jungle(clock_t jungleStartTime)
	{
		Camp campBottomBlue = Camp("bottomBlue", 115, 300, false);
		campBottomBlue.AddMonster(Monster("AncientGolem1.1.1", false));
		campBottomBlue.AddMonster(Monster("YoungLizard1.1.2", false));
		campBottomBlue.AddMonster(Monster("YoungLizard1.1.3", false));
		MonsterToCamp["AncientGolem1.1.1"] = campBottomBlue;
		MonsterToCamp["YoungLizard1.1.2"] = campBottomBlue;
		MonsterToCamp["YoungLizard1.1.3"] = campBottomBlue;

		Camp campBottomRed = Camp("bottomRed", 115, 300, false);
		campBottomRed.AddMonster(Monster("LizardElder4.1.1", false));
		campBottomRed.AddMonster(Monster("YoungLizard4.1.2", false));
		campBottomRed.AddMonster(Monster("YoungLizard4.1.3", false));
		MonsterToCamp["LizardElder4.1.1"] = campBottomRed;
		MonsterToCamp["YoungLizard4.1.2"] = campBottomRed;
		MonsterToCamp["YoungLizard4.1.3"] = campBottomRed;

		Camp bottomWolves = Camp("bottomWolves", 125, 50, false);
		bottomWolves.AddMonster(Monster("GiantWolf2.1.3", false));
		bottomWolves.AddMonster(Monster("wolf2.1.1", false));
		bottomWolves.AddMonster(Monster("wolf2.1.2", false));
		MonsterToCamp["GiantWolf2.1.3"] = bottomWolves;
		MonsterToCamp["wolf2.1.1"] = bottomWolves;
		MonsterToCamp["wolf2.1.2"] = bottomWolves;
	
		Camp bottomWraiths = Camp("bottomWraiths", 125, 50, false);
		bottomWraiths.AddMonster(Monster("Wraith3.1.1", false));
		bottomWraiths.AddMonster(Monster("LesserWraith3.1.2", false));
		bottomWraiths.AddMonster(Monster("LesserWraith3.1.3", false));
		MonsterToCamp["Wraith3.1.1"] = bottomWraiths;
		MonsterToCamp["LesserWraith3.1.2"] = bottomWraiths;
		MonsterToCamp["LesserWraith3.1.3"] = bottomWraiths;
	
		Camp campBottomGolems = Camp("bottomGolems", 125, 50, false);
		campBottomGolems.AddMonster(Monster("Golem5.1.2", false));
		campBottomGolems.AddMonster(Monster("SmallGoem5.1.1", false));
		MonsterToCamp["Golem5.1.2"] = campBottomGolems;
		MonsterToCamp["SmallGolem5.1.1"] = campBottomGolems;
	
		Camp campTopBlue = Camp("topBlue", 115, 300, false);
		campTopBlue.AddMonster(Monster("AncientGolem7.1.1", false));
		campTopBlue.AddMonster(Monster("YoungLizard7.1.2", false));
		campTopBlue.AddMonster(Monster("YoungLizard7.1.3", false));
		MonsterToCamp["AncientGolem7.1.1"] = campTopBlue;
		MonsterToCamp["YoungLizard7.1.2"] = campTopBlue;
		MonsterToCamp["YoungLizard7.1.3"] = campTopBlue;

		Camp campTopRed = Camp("topRed", 115, 300, false);
		campTopRed.AddMonster(Monster("LizardElder10.1.1", false));
		campTopRed.AddMonster(Monster("YoungLizard10.1.2", false));
		campTopRed.AddMonster(Monster("YoungLizard10.1.3", false));
		MonsterToCamp["LizardElder10.1.1"] = campTopRed;
		MonsterToCamp["YoungLizard10.1.2"] = campTopRed;
		MonsterToCamp["YoungLizard10.1.3"] = campTopRed;

		Camp topWolves = Camp("topWolves", 125, 50, false);
		topWolves.AddMonster(Monster("GiantWolf8.1.3", false));
		topWolves.AddMonster(Monster("wolf8.1.1", false));
		topWolves.AddMonster(Monster("wolf8.1.2", false));
		MonsterToCamp["GiantWolf8.1.3"] = topWolves;
		MonsterToCamp["wolf8.1.1"] = topWolves;
		MonsterToCamp["wolf8.1.2"] = topWolves;

		Camp topWraiths = Camp("topWraiths", 125, 50, false);
		topWraiths.AddMonster(Monster("Wraith9.1.1", false));
		topWraiths.AddMonster(Monster("LesserWraith9.1.2", false));
		topWraiths.AddMonster(Monster("LesserWraith9.1.3", false));
		MonsterToCamp["Wraith9.1.1"] = topWraiths;
		MonsterToCamp["LesserWraith9.1.2"] = topWraiths;
		MonsterToCamp["LesserWraith9.1.3"] = topWraiths;

		Camp campTopGolems = Camp("topGolems", 125, 50, false);
		campTopGolems.AddMonster(Monster("Golem11.1.2", false));
		campTopGolems.AddMonster(Monster("SmallGoem11.1.1", false));
		MonsterToCamp["Golem11.1.2"] = campTopGolems;
		MonsterToCamp["SmallGolem11.1.1"] = campTopGolems;
		
		Camp campDragon = Camp("dragon", 150, 360, false);
		campDragon.AddMonster(Monster("Dragon6.1.1", false));
		MonsterToCamp["Dragon6.1.1"] = campDragon;

		Camp campBaron = Camp("baron", 900, 420, false);
		campBaron.AddMonster(Monster("Worm12.1.1", false));
		MonsterToCamp["Worm12.1.1"] = campBaron;
		
	}
};
