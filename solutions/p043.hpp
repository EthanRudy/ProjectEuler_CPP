#ifndef P043_HPP
#define P043_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P043 : Solution {
private:
	int primes[7] = { 2, 3, 5, 7, 11, 13, 17 };
public:

	void run() {
		precise_timer timer;

		unsigned long long ans = 0;
		std::string str = "0123456789";

		// Yeah I know that do whiles aren't recommened in a lot of styling guides but its perfect here
		do {
			bool found = true;
			//std::cout << str << " | " << to_int(str) << "\n";
			for (int i = 0; i < 7; ++i) {
				std::string sub = str.substr(i + 1, 3);
				if (to_num(sub) % primes[i] != 0) {
					found = false;
					break;
				}
			}
			if (found) {
				ans += to_num(str);
			}
		} while (std::next_permutation(str.begin(), str.end()));

		int duration = timer.get_duration<int, std::chrono::seconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " seconds";
		// Avg runtime: 3 seconds
	}

	// Fix for the ston errors with zeros
	unsigned long long to_num(const std::string& str) {
		unsigned long long n = 0;
		for (char c : str) {
			n *= 10;
			n += (c - '0');
		}
		return n;
	}

};

#endif