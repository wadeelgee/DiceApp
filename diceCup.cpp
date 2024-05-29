#include "diceCup.h"

DiceCup::DiceCup()
{
	std::mt19937 gen(std::time(0));
	m_gen = gen;
	m_numOfDice = 0;
}

DiceCup::DiceCup(int numOfDice)
{
	std::mt19937 gen(std::time(0));
	m_gen = gen;
	m_numOfDice = numOfDice;
}

Dice DiceCup::rollOne()
{
	// TODO: Check if numDice > 0, else throw error
	Dice die = Dice(&m_gen);
	die.rollDie();
	m_numOfDice--; // Remove one Die from cup
	return die;
}

std::vector<Dice> DiceCup::rollDice()
{
	std::vector<Dice> diceInCup(m_numOfDice);
	std::cout << "\nRolling " << m_numOfDice << " Dice!\n";
	for (Dice& die : diceInCup) {
		die.setSides(m_diceSides);
		die.rollDie();
	}

	reset(); // Remove all Dice from cup

	return diceInCup;
}
