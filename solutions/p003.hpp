#ifndef P003_HPP
#define P003_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>
#include <vector>

class P003 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		long long n = 600851475143;
		std::vector<long long> pFactVec = primeFactors(n);

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << pFactVec.back() << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 16 microseconds
	}

};

#endif