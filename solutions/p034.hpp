#ifndef P034_HPP
#define P034_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P034 : Solution {
private:
	// Provide facorial digits
	int FACTORIAL[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
public:

	void run() {
		precise_timer timer;

		int MAX = 7 * factorial(9);

		int ans = 0;
		for (int i = 3; i < MAX; ++i){
			int n = factDigis(i);

			if (n == i) { ans += i; }
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 20 milliseconds
	}

	int factDigis(int n) {
		int sum = 0;

		while (n != 0) {
			sum += FACTORIAL[n % 10];
			n /= 10;
		}

		return sum;
	}

};

#endif