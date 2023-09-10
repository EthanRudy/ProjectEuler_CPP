#include "../include/Timer.hpp"
#include "../include/numHelper.hpp"

#include <iostream>

void problem012() {
	precise_timer timer;

	int triNum = 0;
	int toAdd = 0;
	while (true) {
		triNum += ++toAdd;
		if (numOfFacts(triNum) > 500) { break; }
	}

	int duration = timer.get_duration<int, std::chrono::milliseconds>();
	std::cout << "Solution: " << triNum << "\n";
	std::cout << "Solution found in " << duration << " milliseconds";
	// Avg runtime: 70 milliseconds
}
