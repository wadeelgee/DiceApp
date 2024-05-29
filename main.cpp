#include <iostream>
#include <limits>
#include <random>
#include "main.h"
#include "diceTray.h"


int main()
{

	DiceTray tray{};
	std::cout << "Dice Roller!\n";
	while (true) {
		tray.menuSelection();
		tray.menuStartRolling();
	}
	return 0;
}
