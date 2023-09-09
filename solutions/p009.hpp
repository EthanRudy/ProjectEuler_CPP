#include "../include/Timer.hpp"

#include <iostream>
#include <string>

void problem009() {
	precise_timer timer;

	const int MAX = 1000;
	int prod = 0;

	for (int b = 1; b < MAX - 2; ++b) { // MAX - 2 because a and c need to fit
		for (int a = 1; a < b; ++a) {	// Triplet rule "a < b"
			int c = MAX - a - b;
			if (a > c || b > c) { continue; }
			if (a * a + b * b == c * c) {
				prod = a * b * c;
				break;
			}
		}

	}

	int duration = timer.get_duration<int, std::chrono::microseconds>();
	std::cout << "Solution: " << prod << "\n";
	std::cout << "Solution found in " << duration << " microseconds";
	// Avg runtime: 190 microseconds
}