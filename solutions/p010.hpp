#ifndef P010_HPP
#define P010_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>

class P010 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int MAX = 2000000;
		std::vector<int> primes = seiveofEratosthenes(MAX);
		long long sum = 0;

		for (int i : primes) {
			sum += i;
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 10 milliseconds
	}

};

#endif