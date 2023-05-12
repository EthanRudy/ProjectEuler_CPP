#include <iostream>
#include "Timer.hpp"
#include "NumHelper.hpp"

int main() {
	timer timer;
	timer.start();

	int triNum = 0;
	int toAdd = 0;
	while (true) {
		triNum += ++toAdd;
		if (numOfFacts(triNum) > 500) { break; }
	}

	timer.end();

	std::cout << "Answer: " << triNum << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~117 Milliseconds
}
