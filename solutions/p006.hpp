#ifndef P006_HPP
#define P006_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>

class P006 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int MAX = 100;

		int sum = 0;
		int sumOfSquares = 0;
		for (int i = 1; i <= MAX; ++i) {
			sum += i;
			sumOfSquares += (i * i);
		}
		int diff = (sum * sum) - sumOfSquares;

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << diff << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 1 microseconds
	}

};

#endif