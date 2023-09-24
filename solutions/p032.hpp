#ifndef P032_HPP
#define P032_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>
#include <string>

class P032 : Solution {
private:
public:

	void run() {
		precise_timer timer;
		
		// 1 - 9 pandiigital
		std::vector<int> pandigitals;

		int a = 1, b = 0, c = 0;
		std::string str = "000";
		while (a < 1000){
			b = a, c = 0;
			str = "";
			while (str.length() <= 9) {
				++b;
				c = a * b;
				str = std::to_string(a) + std::to_string(b) + std::to_string(c);
				if (str.size() != 9) {  continue;  }
				if (pandigital(str) && std::find(pandigitals.begin(), pandigitals.end(), c) == pandigitals.end()) {
					pandigitals.push_back(c);
				}
			}
			++a;
		}

		int sum = 0;
		for (int i : pandigitals) {
			sum += i;
		}
	

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 100 milliseconds :(
	}

};

#endif