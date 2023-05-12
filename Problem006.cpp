#include <iostream>
#include "Timer.hpp"

int main() {
	timer timer;
	timer.start();

	long long squaredSum = 0;
	long long sumSquares = 0;
	int limit = 100;

	for (int i = 1; i <= limit; ++i) {
		squaredSum += i;
		sumSquares += (i * i);
	}
	squaredSum *= squaredSum;

	timer.end();

	std::cout << "Answer: " << squaredSum - sumSquares << "\n";
	std::cout << "Found in: " << timer.duration(nanosecond) << " nanoseconds\n";

	// ~300 nanoseconds
}
