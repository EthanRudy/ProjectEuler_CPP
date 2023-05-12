#include <iostream>
#include "Timer.hpp"
#include "PrimeHelper.hpp"

int main() {
	timer timer;
	timer.start();
	
	std::vector<long long> primes;
	seiveOfEratosthenes(2000000, primes);
	long long sum = 0;
	for (long long i : primes) { sum += i; }

	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~19 Milliseconds
}
