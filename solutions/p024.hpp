#ifndef P024_HPP
#define P024_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>
#include <string>
#include <algorithm>

class P024 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		std::string digits = "0123456789";
		int targetPerm = 1000000;
		while (--targetPerm) {
			std::next_permutation(digits.begin(), digits.end());	// Super cheap, but hey, its included ;)
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << digits << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 300 milliseconds
	}

};

#endif