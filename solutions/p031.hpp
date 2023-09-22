#ifndef P031_HPP
#define P031_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P031 : Solution {
private:
	const int denoms[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	const int N = 200;
	const int LENGTH = 8;
public:

	void run() {
		precise_timer timer;

		std::cout << combinations(LENGTH, N) << "\n";

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << "ans" << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 29 milliseconds
	}

	int combinations(int n, int amount) {
		// I had this code in a old folder on my hard drive from my old CP2 class 4 years ago lol

		if (amount == 0) { return 1; }
		if (amount < 0 || n <= 0) { return 0; }

		return combinations(n, amount - denoms[n - 1]) + combinations(n - 1, amount);
	}

};

#endif