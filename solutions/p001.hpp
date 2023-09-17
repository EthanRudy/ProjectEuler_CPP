#ifndef P001_HPP
#define P001_HPP


#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>

class P001 : Solution {
private: // Normally there won't be a private section unless there are constants I need
public:

	void run() {
		precise_timer timer;

		int sum = 0;

		for (int i = 3; i < 1000; ++i) {
			if (i % 3 == 0 || i % 5 == 0) {
				sum += i;
			}
		}

		int duration = timer.get_duration<int, std::chrono::nanoseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " nanoseconds";
		// Avg runtime: 1.2 - 1.3 microseconds
	}

};

#endif