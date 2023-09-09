#include "../include/Timer.hpp"

#include <iostream>

void problem001() {
	precise_timer timer;

	int sum = 0;

	for (uint16_t i = 3; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	int duration = timer.get_duration<int, std::chrono::nanoseconds>();
	std::cout << "Solution: " << sum << "\n";
	std::cout << "Solution found in " << duration << " nanoseconds";
	// Avg runtime: 1.2 - 1.3 microseconds
}