#ifndef P027_HPP
#define P027_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>

class P027 : Solution {
private:
	int MAX = 1000;
public:

	void run() {
		precise_timer timer;

		// Yes its brute force but its like 12 pm on a thursday and I want to make lunch

		int mostPrimes = 0;
		int prod = 0;
		for (int a = -MAX + 1; a < MAX; ++a) {
			for (int b = -MAX; b <= MAX; ++b) {
				int n = 0;
				int nPrimes = 0;
				while (true) { 
					if (prime((n * n) + (a * n) + b)) { nPrimes++; }
					else { break; }
					++n;
				}

				if (nPrimes > mostPrimes) {
					mostPrimes = nPrimes;
					prod = a * b;
				}
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << prod << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 30 milliseconds
	}

};

#endif