#include "diceTray.h"


DiceTray::DiceTray() {
	cup = DiceCup();
}

void DiceTray::rollOneDiceToTray() {
	Dice die = cup.rollOne();
	m_diceInTray.emplace_back(die);
}

void DiceTray::rollFiveDiceToTray() {
	for (int i = 0; i < 5; i++) {
		if (cup.diceNum() > 0) {
			rollOneDiceToTray();
		}
	}

}

void DiceTray::rollAllDiceToTray() {
	auto result = cup.rollDice();
	for (Dice& die : result) {
		m_diceInTray.emplace_back(die);
	}
}

void DiceTray::changeDiceSides()
{
	std::cout << "Choose a Number of Sides!: ";
	cup.setSides(inputSelection(1, 100));
}

void DiceTray::rerollDice() {
	std::cout << "Select What Side to Reroll!: ";
	int value = inputSelection(1, cup.getSides());
	sortDice();
	// Check for Values
	std::unordered_map<unsigned, size_t> counts;
	for (Dice& die : m_diceInTray) {
		++counts[die.getValue()];
	}
	// Add Values to Cup
	for (auto const& p : counts) {
		if (p.first == value) {
			addDiceToCup(p.second);
		}
	}

	// Erase and Restore Other Dice
	resetTray();

	for (auto const& p : counts) {
		if (p.first != value) {
			for (int i = 0; i < p.second; i++) {
				Dice d;
				d.setValue(p.first);
				addDiceToTray(d);
			}
		}
	}

	// Roll and Display
	rollAllDiceToTray();
	printDice();
	printStatus();
}

void DiceTray::sortDice()
{
	std::sort(m_diceInTray.begin(), m_diceInTray.end());
}

void DiceTray::printStatus()
{
	std::cout << "Number of Dice in Tray: " << m_diceInTray.size() << '\n';
	std::cout << "Number of Dice in Cup: " << getCup().diceNum() << '\n';
}

void DiceTray::changeDisplay()
{
	std::cout << "Change Display Type: \n\n";

	std::cout << "1. Individual Rolls \n";
	std::cout << "2. Sorted Rolls \n";
	std::cout << "3. Grouped Results \n";

	std::cout << "Display: ";
	displayType = inputSelection(0, 3);
}

void DiceTray::printDice() {
	switch (displayType) {
	case 1: // Print dice as rolled
		print();
		break;
	case 2: // Print dice individually, but sorted
		sortDice();
		print();
		break;
	case 3: // Print dice grouped as results
		sortDice();
		std::cout << "Dice In Tray: \n";
		std::unordered_map<unsigned, size_t> counts;
		for (Dice& die : m_diceInTray) {
			++counts[die.getValue()];
		}
		for (auto const& p : counts) {
			std::cout << p.first << "'s rolled: " << p.second << '\n';
		}
		break;
	}

}

void DiceTray::resetTray()
{
	std::cout << "Tray Reset!\n";
	m_diceInTray.resize(0);
	printStatus();
}

void DiceTray::print() {
	std::cout << "Dice In Tray: \n";
	for (Dice& die : m_diceInTray) {
		die.print();
	}
}

int DiceTray::inputSelection(int lowerBound, int upperBound)
{
	while (true) {
		int x{};
		std::cin >> x;

		try {
			if (x < lowerBound || x > upperBound) {
				throw "Invalid number. Please try again.";
			}
			return x;
		}
		catch (const char* exception) {
			std::cin.clear(); // Reset Buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Empty Buffer
			std::cerr << "Error: " << exception << '\n';
		}
	}
}

void DiceTray::menuSelection()
{
	bool menuSelecting = true;
	while (menuSelecting) {
		std::cout << "\n";
		std::cout << "1. Roll some dice.\n";
		std::cout << "2. Reroll dice.\n";
		std::cout << "3. Clear the tray.\n";
		std::cout << "4. Change Dice Size.\n";
		std::cout << "5. Change display options\n";

		std::cout << "Select: ";
		int x = inputSelection(1, 5);

			switch (x) {
			case 1:
				menuSelecting = false;
				break;
			case 2:
				rerollDice();
				break;
			case 3:
				resetTray();
				break;
			case 4:
				changeDiceSides();
				break;
			case 5:
				changeDisplay();
				break;
			}
		}

}

void DiceTray::menuStartRolling()
{
	bool rollingDice = true;


		std::cout << "Number of dice to add to cup: ";
		int x = inputSelection(0, 1000000); // Capped at 1m
			addDiceToCup(x);

	while (rollingDice) {
			std::cout << "How many would you like to roll?\n";
			std::cout << "1. Roll 1 Die\n";
			std::cout << "2. Roll 5 Die\n";
			std::cout << "3. Roll All Dice\n";

			std::cout << "Select: ";
			int y = inputSelection(1, 3);

			if (y == 1) {
				rollOneDiceToTray();
				if (cup.diceNum() <= 0) {
					rollingDice = false;
				}
			}
			else if (y == 2) {
				rollFiveDiceToTray();
				if (cup.diceNum() <= 0) {
					rollingDice = false;
				}
			}
			else {
				rollAllDiceToTray();
				rollingDice = false;
			}
			printDice();
			printStatus();

	}
}


