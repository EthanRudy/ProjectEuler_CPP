#ifndef P035_HPP
#define P035_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/primeHelper.hpp"

#include <iostream>
// Any other official headers needed

class P035 : Solution {
private:
public:

	void run(){
		precise_timer timer;

		std::vector<int> primes;
		seiveofEratosthenes(1000000, primes);
		int ans = 0;

		for (int i = 0; i < primes.size(); ++i) {
			bool circular = true;

			//std::cout << primes[i] << "\n";

			std::string current = std::to_string(primes[i]);
			std::string next = rotate(current);
			while (current != next) {

				//std::cout << "\t" << next << "\n";

				if (!prime(std::stoi(next))) {
					circular = false;
					break;
				}

				next = rotate(next);
			}

			if (circular) {
				++ans;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 175 milliseconds D: Its alright its like 2:30 am on hallween
	}

	std::string rotate(std::string str) {
		char c = str[0];
		str = str.substr(1);

		return str + c;
	}

};

#endif