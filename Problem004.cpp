#include <iostream>
#include "Timer.hpp"
#include "NumHelper.hpp"

int main() {
	timer timer;
	timer.start();

	long long largest = 0;
	for (int i = 999; i > 99; --i){
		for (int ii = 999; ii > 99; --ii) {
			long long prod = i * ii;
			if (palindrome(prod)) {
				if (largest < prod) { largest = prod; }
			}
		}
	}

	timer.end();
	
	std::cout << "Answer: " << largest << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// 1057  Milliseconds
}
