#include <iostream>
#include <array>
#include <random>

constexpr int peoplePerSample { 2 };
constexpr int sampleSize { 100'000 };
constexpr int daysPerYear { 365 };

int randomInt(const int min, const int max) {
	static std::random_device rd {};
	static std::seed_seq seq { rd(), rd(), rd(), rd(), rd() };
	static std::mt19937 gen { seq };
	
	std::uniform_int_distribution dist { min, max };
	
	return dist(gen);
}

int randomDay() {
	return randomInt(0, daysPerYear - 1);
}

bool executeSample() {
	std::array<bool, daysPerYear> seenArray {};
	
	for (int i { 0 }; i < peoplePerSample; i++) {
		const int day { randomDay() };
		
		if (seenArray[ day ])
			return true;
		else
			seenArray[ day ] = true;
	}
				
	return false;
}

constexpr float getPercent(const int value) {
	constexpr float divisor { sampleSize / 100 };
	static_assert(divisor != 0);
	
	return value / divisor;
}

int main() {
	int matches { 0 };
	
	for (int i { 0 }; i < sampleSize; i++)
		matches += executeSample();
	
	std::cout << getPercent(matches) << "% match with " << peoplePerSample << " people per sample and a \nsample size of " << sampleSize << ".\n";
}