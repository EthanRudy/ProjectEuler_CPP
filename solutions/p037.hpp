#ifndef P037_HPP
#define P037_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>
// Any other official headers needed

class P037 : Solution {
private:
	int MAX = 1000000;
public:

	void run() {
		precise_timer timer;

		int ans = 0;
		std::vector<int> primes;
		seiveofEratosthenes(MAX, primes);
		// Having a next prime right about now would be nice		

		int n = 0;

		for (int i = 4; i < primes.size(); ++i) {

			if (left(primes[i]) && right(primes[i])) {
				++n;
				ans += primes[i];
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 72 milliseconds
	}

	bool left(int n) {
		if (n < 10) { return prime(n); }
		return prime(n) && left(n / 10);
	}

	bool right(int n) {
		if (n < 10) { return prime(n); }

		std::string str = std::to_string(n);

		return prime(n) && right(std::stoi(str.substr(1)));
	}

};

#endif