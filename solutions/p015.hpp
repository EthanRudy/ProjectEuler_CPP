#include "../include/Timer.hpp"

#include <iostream>

void problem015() {
	precise_timer timer;

	const int WIDTH = 20;
	std::vector<std::vector<long long>> pascals = { { 1 } };

	// Calculate pascal's triangle 2*Width x 2*Width
	// in the example it'd be 4 x 4 and in the solutions it's 40 x 40

	for (int i = 0; i < WIDTH * 2; ++i) {
		std::vector<long long> row(2, 1);
		for (int prevI = 0; prevI < pascals[i].size() - 1; ++prevI) {	// Loop only the middle bits
			row.insert(row.end() - 1, pascals[i][prevI] + pascals[i][prevI + 1]);
		}
		pascals.push_back(row);
	}

	long long res = pascals[WIDTH * 2][WIDTH];	// Answer is the middle of the base of the triangle
	

	int duration = timer.get_duration<int, std::chrono::microseconds>();
	std::cout << "Solution: " << res << "\n";
	std::cout << "Solution found in " << duration << " microseconds";
	// Avg runtime: 450 microseconds
}