#include "../include/Timer.hpp"
#ifndef P002_HPP
#define P002_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>

class P002 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int MAX = 4000000;
		int n1 = 1, n2 = 2, n3 = 0;
		int sum = 2; // Includes 2, which is already given

		while (n3 <= MAX) {
			// Generate next value and shift
			n3 = n2 + n1;
			n1 = n2;
			n2 = n3;

			if (n3 % 2 == 0) { sum += n3; }
		}

		int duration = timer.get_duration<int, std::chrono::nanoseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " nanoseconds";
		// Avg runtime: 300 nanoseconds
	}

};

#endif