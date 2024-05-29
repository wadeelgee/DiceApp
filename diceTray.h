#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "diceCup.h"

class DiceTray {
private:
	DiceCup cup;
	std::vector<Dice> m_diceInTray{};
	int displayType = 1;

public:
	DiceTray();

	DiceCup getCup() {
		return cup;
	}

	void addDiceToTray(Dice x) {
		m_diceInTray.push_back(x);
	}

	void addDiceToCup(int x) {
		cup.addDice(x);
	}

	void rollOneDiceToTray();
	void rollFiveDiceToTray();
	void rollAllDiceToTray();

	void rerollDice();

	void sortDice();
	void resetTray();

	void changeDisplay();
	void changeDiceSides();
	void printStatus();
	void printDice();
	void print();

	int inputSelection(int lowerBound, int upperBound);

	void menuSelection();
	void menuStartRolling();
};