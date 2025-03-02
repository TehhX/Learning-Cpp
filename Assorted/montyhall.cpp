/*
- Select a random door
- One of the other doors is revealed, specifically the incorrect one
- If revealed != correct, choose to swap or stay to non chosen/revealed door
- Win if chosen == correct, else lose
*/

#include <iostream>
#include <random>

// How many rounds should be simulated.
constexpr unsigned int runsPer { 1'000'000 };

// Gets a random integer from min to max (inclusive).
int randInt(const int min, const int max) {
	static std::random_device rd {};
    static std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    static std::mt19937 gen { ss };
    std::uniform_int_distribution dist { min, max };

    return dist(gen);
}

// Gets a random door of three.
int randDoor() {
    return randInt(0, 2);
}

// Gets a random door while excluding one possible door.
int randDoor(const int exclude) noexcept {
	if (exclude == 0)
		return randInt(1, 2);
	else if (exclude == 1)
		return (randInt(0, 1) == 0 ? 0 : 2);
	else
		return randInt(0, 1);
}

// Of three doors, gets the unchosen one with two chosen values.
int getUnchosen(const int first, int second) {
	const bool zeroTaken { first == 0 || second == 0 };
	const bool oneTaken  { first == 1 || second == 1 };
	const bool twoTaken  { first == 2 || second == 2 };
	
	if (first == second)
		return randDoor(first);
	else if (zeroTaken)
		return (oneTaken ? 2 : 1);
	else if (oneTaken)
		return 0;
	else
		return 2;
}

// Plays a round of monty hall, returns true if win, else false. Will swap doors if swap.
bool playRound(const bool swap) noexcept {
	const int correct { randDoor() };
	int chosen        { randDoor() };

	int revealed { getUnchosen(chosen, correct) };

	if (swap)
		return getUnchosen(revealed, chosen) == correct;

	return chosen == correct;
}

// Gets the percentage of a value out of runsPer.
constexpr int getPercent(const float value) noexcept {
	constexpr float divisor { runsPer / 100 };
	static_assert(divisor != 0);

	return value / divisor;
}

// Plays runsPer amount of rounds, prints each one's score at the end.
int main() {
	unsigned int stayWins { 0 };
	unsigned int swapWins { 0 };

	for (int i { 0 }; i < runsPer; i++) {
		stayWins += playRound(false);
		swapWins += playRound(true);

		// Progress dots, no impact on simulation.
		if (i % static_cast<int>(runsPer * 0.1f) == 0)
			std::cout << '.' << std::flush;
	}

	std::cout << "\nStay Wins: "       << stayWins << '/' << runsPer << '\n';
	std::cout << "Swap Wins: "         << swapWins << '/' << runsPer << '\n';
	std::cout << "Ratio (Stay:Swap): " << getPercent(stayWins) << ':' << getPercent(swapWins) << std::endl;
}
