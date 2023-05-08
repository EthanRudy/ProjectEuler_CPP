#include <iostream>
#include "Timer.hpp";

int main() {
	timer timer;
	timer.start();

	int term1 = 1, term2 = 2, term3 = 0, sum = 2;
	while (term3 < 4000000) {	// Loop all fibonacci terms < 4 million
		term3 = term2 + term1;
		term1 = term2;
		term2 = term3;

		if (term3 % 2 == 0) { sum += term3; }	// Check for divisibility by 2
	}

	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in " << timer.duration(nanosecond) << " nanoseconds\n";

	// 200-300 Nanoseconds
}
