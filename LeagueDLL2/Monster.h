#ifndef _MONSTER_
#define _MONSTER_

#include <string>

using namespace std;

class Monster {
public:
	std::string Name;
	bool IsActive;
	Monster() { }

	Monster(std::string name, bool isActive) {
		Name = name;
		IsActive = isActive;
	}
};
#endif