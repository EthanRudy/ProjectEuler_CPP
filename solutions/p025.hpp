#ifndef P025_HPP
#define P025_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/BigInt.hpp"

#include <iostream>

class P025 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int index = 0;
		std::vector<BigInt> fibSeq = { BigInt(1), BigInt(1) };

		bool found = false;
		while (!found) {
			fibSeq.push_back(fibSeq[index] + fibSeq[index + 1]);

			if (fibSeq.back().toString().length() == 1000) { 
				found = true; 
				index += 2;	// Account for 0th index being used to find 2nd term
			}

			++index;
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << index << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 640 milliseconds
	}

};

#endif