#ifndef P040_HPP
#define P040_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P040 : Solution {
private:
	int MAX = 1000001;
public:

	void run() {
		precise_timer timer;

		std::string str = "";
		int i = 0;
		while (str.length() < MAX) {
			str += std::to_string(i);
			++i;
		}

		int pos = 1;
		int ans = 1;
		for (int i = 0; i < 7; ++i) {
			ans *= (str[pos] - '0');
			pos *= 10;
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 66 milliseconds
	}


};

#endif