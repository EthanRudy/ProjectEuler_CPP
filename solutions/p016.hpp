#ifndef P016_HPP
#define P016_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/BigInt.hpp"

#include <iostream>

class P016 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int BASE = 2;
		const int EXP = 1000;

		BigInt n(BASE);
		for (int i = 1; i < EXP; ++i) { n *= BASE; }

		int sum = 0;
		std::string str = n.toString();
		for (char c : str) {
			sum += (c - '0');
		}


		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 1.2 milliseconds
	}

};

#endif