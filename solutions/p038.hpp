#ifndef P038_HPP
#define P038_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P038 : Solution {
private:
	int MAX = 987654321;
public:

	void run() {
		precise_timer timer;


		std::string ans;
		// The idea is to start high, so 9999 * 1 + 9999 * 2, etc
		// Over and over until a pandigital number is concatonated, aka the answer
		for (int n = 9999; n > 0; --n) {
			std::string concat = "";

			int i = 1;
			while (concat.length() < 9) {
				concat += std::to_string(n * i);

				++i;
			}

			if (concat.length() == 9 && pandigital(concat)) {
				ans = concat;
				break;
			}
		}

		
		

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 900 microseconds
	}

};

#endif