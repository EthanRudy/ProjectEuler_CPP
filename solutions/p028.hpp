#ifndef P028_HPP
#define P028_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P028 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int limit = 1001 * 1001;

		int n = 1, sum = 1, jumps = 0, jumpDistance = 2;
		while (n < limit) {
			n += jumpDistance;
			++jumps;

			if (jumps == 4) {
				jumpDistance += 2;
				jumps = 0;
			}

			sum += n;
		}

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 2 microseconds
	}

};

#endif