#include "dice.h"
#include <iostream>
#include <random>

Dice::Dice()
{
	// Initialize a generator if not given one
	std::random_device rd;
	std::mt19937 gen(rd());
	m_genPtr = &gen;
}

bool Dice::operator<(Dice& d2)
{
	return getValue() < d2.getValue();
}

void Dice::generateValue() {
	std::uniform_int_distribution<> dis(1, m_sides);
	m_value = dis(*m_genPtr);
}

void Dice::print() {
	std::cout << "Rolled: " << m_value << "\n";
}

void Dice::rollDie() {
	generateValue();
}
