#include <iostream>
#include <vector>
#include "Timer.hpp"
#include "NumHelper.hpp"

int factSum(int n);

int main() {
	timer timer;
	timer.start();

	int sum = 0;
	std::vector<int> checked;
	for (int a = 1; a < 10000; ++a) {
		if (std::find(checked.begin(), checked.end(), a) == checked.end()) {
			int b = factSum(a);
			if (factSum(b) == a && a != b) {	// Ammicable
				sum += a + b;
				checked.push_back(a);
				checked.push_back(b);
			}
		}
	}

	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~246 milliseconds
}

int factSum(int n) {
	std::vector<int> factVec;
	factors(n, factVec);

	int sum = 0;
	for (int i : factVec) { 
		sum += i;
	}
	
	return sum;
}
