#include <iostream>
#include <vector>
#include "Timer.hpp"

int main() {
	timer timer;
	timer.start();

	// This is just Pascal's Triangle
	std::vector<std::vector<long long>> triangle;
	triangle.push_back(std::vector<long long>(1, 1));

	// This is officially the worst piece of code I've ever written
	const int gridSize = 40;
	for (int i = 0; i < gridSize; ++i) {
		std::vector<long long> newRow(1, 1);
		for (int prevI = 0; prevI < triangle[i].size() - 1; ++prevI) {
			newRow.push_back(triangle[i][prevI] + triangle[i][prevI + 1]);
		}
		newRow.push_back(1);
		triangle.push_back(newRow);
	}

	timer.end();

	std::cout << "Answer: " << triangle[40][20] << "\n";
	std::cout << "Found in: " << timer.duration(microsecond) << " microseconds\n";

	// ~330 Microseconds lol
}
