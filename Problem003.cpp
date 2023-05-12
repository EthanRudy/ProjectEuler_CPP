#include <iostream>
#include "Timer.hpp";
#include "PrimeHelper.hpp";

int main() {
	timer timer;
	timer.start();

	long long num = 600851475143;
	std::vector<long long> primeFactors = prime_factors(num);

	timer.end();

	std::cout << "Answer: " << primeFactors.back() << "\n";
	std::cout << "Found in " << timer.duration(microsecond) << " microseconds\n";

	// 20-30 Microseconds
}
