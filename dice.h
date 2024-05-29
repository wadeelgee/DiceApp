#include <iostream>
#include <random>

class Dice {
private:
	int m_sides{ 6 };
	int m_value{};
	std::mt19937* m_genPtr{ nullptr }; // PTR to Generator

public:

	Dice();
	Dice(std::mt19937* t_gen) {
		m_genPtr = t_gen;
	}

	Dice(int sides) {
		m_sides = sides;
	}

	int getSides() {
		return m_sides;
	}

	void setSides(int sides) {
		m_sides = sides;
	}

	int getValue() {
		return m_value;
	}

	void setValue(int value) {
		m_value = value;
	}

	bool operator<(Dice& d2);

	void generateValue();
	void print();
	void rollDie();

};
