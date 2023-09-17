#ifndef PXXX_HPP
#define PXXX_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/BigInt.hpp"

#include <iostream>

class P020 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int n = 100;
		BigInt fact(1);

		for (; n > 1; --n) {
			fact *= n;
		}

		int sum = 0;
		std::string str = fact.toString();
		for (char c : str) {
			sum += (c - '0');
		}

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 275 microseconds
	}

};

#endif