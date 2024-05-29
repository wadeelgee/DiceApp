#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include "dice.h"

class DiceCup {

private:
	std::mt19937 m_gen{};
	int m_numOfDice{};
	int m_diceSides = 6;

public:
	DiceCup();
	DiceCup(int numOfDice);

	int diceNum() { 
		return m_numOfDice; 
	}

	void reset() {
		m_numOfDice = 0;
	}

	void addDice(int numOfDice) {
		m_numOfDice += numOfDice;
	}

	int getSides() {
		return m_diceSides;
	}

	void setSides(int diceSize) {
		m_diceSides = diceSize;
	}

	Dice rollOne();
	std::vector<Dice> rollDice();

};