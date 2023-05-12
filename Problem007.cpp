#include <iostream>
#include "Timer.hpp"
#include "PrimeHelper.hpp"

int main() {
	timer timer;
	timer.start();

	int num = 3, primes = 1;
	while (true) {
		if (prime(num)) { 
			++primes; 
			if (primes == 10001) { break; }
		}
		num += 2;
	}

	timer.end();

	std::cout << "Answer: " << num << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~6 Milliseconds
}
