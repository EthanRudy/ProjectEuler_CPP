#include "../include/Timer.hpp"

#include <iostream>
#include <string>
#include <fstream>

void problem011() {
	// Loading the input before the timer starts, as this computation isn't worth timing
	int grid[20][20];

	std::ifstream file("./inputs/p011.txt");
	std::string line = "";

	int y = 0;
	while (getline(file, line)) {
		int start = 0;
		for (int i = 0; i < 20; ++i) {
			grid[y][i] = stoi(line.substr(start, 2));
			start += 3;
		}
		++y;
	}

	precise_timer timer;

	
	int largest = 0, prod;
	for (y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			if (y < 17) {	// Down Limit
				prod = grid[y][x] * grid[y + 1][x] * grid[y + 2][x] * grid[y + 3][x];
				if (prod > largest) { largest = prod; }
			}
			if (x < 17) {	// Right Limit
				prod = grid[y][x] * grid[y][x + 1] * grid[y][x + 2] * grid[y][x + 3];
				if (prod > largest) { largest = prod; }
			}
			if (x < 17 && y < 17) { // Right Diagonal Limit
				prod = grid[y][x] * grid[y + 1][x + 1] * grid[y + 2][x + 2] * grid[y + 3][x + 3];
				if (prod > largest) { largest = prod; }
			}
			if (x > 2 && y < 17) {	// Left Diagonal Limit
				prod = grid[y][x] * grid[y + 1][x - 1] * grid[y + 2][x - 2] * grid[y + 3][x - 3];
				if (prod > largest) { largest = prod; }
			}
		}
	}
	

	int duration = timer.get_duration<int, std::chrono::microseconds>();
	std::cout << "Solution: " << largest << "\n";
	std::cout << "Solution found in " << duration << " microseconds";
	// Avg runtime: 1 microsecond
}