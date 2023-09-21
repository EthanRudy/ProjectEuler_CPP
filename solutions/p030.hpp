#ifndef P030_HPP
#define P030_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P030 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int POWER = 5;
		int max = pow(10, POWER + 1);	// idk random guess

		int sum = 0;
		for (int i = 2; i < max; ++i) {
			if (sumPower(i, POWER) == i) {
				sum += i;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 233 milliseconds
	}

	int sumPower(int n, int p) {
		int sum = 0;

		while (n > 0) {
			div_t d = div(n, 10);
			sum += pow(d.rem, p);
			n = d.quot;
		}

		return sum;
	}

};

#endif