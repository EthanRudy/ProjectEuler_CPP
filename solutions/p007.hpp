#ifndef P007_HPP
#define P007_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>

class P007 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int target = 10001;

		int primeNum = 6;
		int n = 13;	// Start just past whats given
		while (primeNum < target) {
			n += 2;	// Check only odd numbers
			if (prime(n)) { ++primeNum; }

		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << n << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 3 milliseconds
	}

};

#endif