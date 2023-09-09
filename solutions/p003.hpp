#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>

void problem003() {
	precise_timer timer;

	long long n = 600851475143;
	std::vector<long long> pFactVec = primeFactors(n);

	int duration = timer.get_duration<int, std::chrono::microseconds>();
	std::cout << "Solution: " << pFactVec.back() << "\n";
	std::cout << "Solution found in " << duration << " microseconds";
	// Avg runtime: 16 microseconds
}