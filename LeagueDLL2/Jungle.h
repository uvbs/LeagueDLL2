#include <string>
#include "Monster.h"
#include "Camp.h"
#include <time.h> 
#include <map>

using namespace std;

class Jungle {
public:
	std::map<std::string, Camp> CampMap;


	Jungle(clock_t jungleStartTime)
	{
		std::string bottomBlue = "bottomBlue";
		CampMap[bottomBlue] = new Camp(bottomBlue, jungleStartTime, 300, false);

	}
};
