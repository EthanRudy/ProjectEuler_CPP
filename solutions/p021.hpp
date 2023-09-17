#ifndef P021_HPP
#define P021_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/numHelper.hpp"

#include <iostream>
#include <vector>

class P021 : Solution {
private:
	const int MAX = 10000;
public:

	void run() {
		precise_timer timer;

		int sum = 0;
		std::vector<int> found;

		for (int a = 1; a < MAX; ++a) {
			if (std::find(found.begin(), found.end(), a) != found.end()) { continue; }

			int dA = getD(a);
			if (a == dA) { continue; }

			int dB = getD(dA);

			if (dB == a) { // Amicable Pair found
				found.push_back(a);
				found.push_back(dA);

				sum += a + dA;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 145 milliseconds :(
	}

	int getD(int n) {
		int d = 0;

		std::vector<int> factsOfN = factors(n);
		for (int i : factsOfN) {
			d += i;
		}

		return d;
	}

};

#endif