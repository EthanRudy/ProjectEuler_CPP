#ifndef P018_HPP
#define P018_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class P018 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int HEIGHT = 15;
		std::vector<std::vector<int>> pyramid;

		std::ifstream file("./inputs/p018.txt");
		std::string line;
		int rowSize = 1;
		while (std::getline(file, line)) {
			std::vector<int> row(rowSize);
			for (int i = 0; i < rowSize; ++i) {
				row[i] = std::stoi(line.substr(0, 2));
				line = line.substr(line.size() == 2 ? 2 : 3);
			}

			pyramid.insert(pyramid.begin(), row);
			++rowSize;
		}

		for (int y = 1; y < HEIGHT; ++y) {
			for (int x = 0; x < pyramid[y].size(); ++x) {
				pyramid[y][x] += max(pyramid[y - 1][x], pyramid[y - 1][x + 1]);
			}
		}

		int res = pyramid[HEIGHT - 1][0]; // Last element is the max sum of the pyramid

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << res << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 425 microseconds
	}

	int max(int a, int b) { return (a > b) ? a : b; }

};

#endif