#ifndef P041_HPP
#define P041_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P041 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int digits = 9;
		int largest = 0;
		while (digits > 1) {

			std::string MAX = "", str = "";
			for (int i = 0; i < digits; ++i) {
				str += (i + 1) + '0';
				MAX = std::to_string(i + 1) + MAX;
			}

			while (str != MAX) {
				int i = std::stoi(str);
				
				if (prime(i)) {
					if (i > largest) {
						largest = i;
					}
				}

				std::next_permutation(str.begin(), str.end());
			}
			--digits;
		}


		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << largest << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 175 milliseconds
	}

};

#endif