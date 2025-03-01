/*
- Select a random door
- Either one of the other doors is revealed
- If revealed != correct, choose to swap or stay to non chosen/revealed door
- Win if chosen == correct, else lose
*/

#include <iostream>
#include <random>

constexpr int runsPer { 1000000 };

int getRandomInt(const int min, const int max) {
    static std::random_device rd {};
    static std::seed_seq ss { rd(), rd(), rd(), rd(), rd() };
    static std::mt19937 gen { ss };
    std::uniform_int_distribution dist { min, max };

    return dist(gen);
}

bool playRound(const bool swap) {
	const int correct { getRandomInt(0, 2) };
	int chosen { getRandomInt(0, 2) };
	
	if (correct == chosen)
		return true;
	
	int revealed;
	if (chosen == 0)
		revealed = getRandomInt(1, 2);
	else if (chosen == 1)
		revealed = (getRandomInt(0, 1) == 0 ? 0 : 2);
	else if (chosen == 2)
		revealed = getRandomInt(0, 1);
	
	if (revealed == correct)
		return false;
	
	if (swap) {
		const bool zeroTaken = revealed == 0 || chosen == 0;
		const bool oneTaken  = revealed == 1 || chosen == 1;
		const bool twoTaken  = revealed == 2 || chosen == 2;
		
		if (zeroTaken)
			chosen = (oneTaken ? 2 : 1);
		else if (oneTaken)
			chosen = 0;
		else
			chosen = 1;
	}
	
	return chosen == correct;
}

constexpr int getPercent(const float value) {
	return value / runsPer * 100;
}

int main() {	
	int stayWins { 0 };
	int swapWins { 0 };
	
	for (int i { 0 }; i < runsPer; i++) {
		stayWins += playRound(false);
		swapWins += playRound(true);
	}
	
	std::cout << "Stay Wins: "         << stayWins << '/' << runsPer << '\n';
	std::cout << "Swap Wins: "         << swapWins << '/' << runsPer << '\n';
	std::cout << "Ratio (Stay:Swap): " << getPercent(stayWins) << ':' << getPercent(swapWins) << std::endl;
}