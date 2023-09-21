#ifndef P026_HPP
#define P026_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
#include <iomanip>
// Any other official headers needed

class P026 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int longest = 0;
		int longestDen;
		for (int i = 2; i < 1000; ++i) {
			int seqLen = sequenceLength(i);
			if (seqLen > longest) {
				longest = seqLen;
				longestDen = i;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << longestDen << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 50 milliseconds
	}

	int sequenceLength(int den) {
		int num = 1;

		std::vector<int> digits;
		int digitNum = 0;

		while (num != 0) {
			num *= 10;
			div_t d = div(num, den);
			num = d.rem;
			
			if (num == 0) { return 0; }	// No repeating sequence

			std::vector<int>::iterator pos = std::find(digits.begin(), digits.end(), num);
			if (pos != digits.end()) {
				// A repeated digit has been found
				return digitNum - (pos - digits.begin());
			}

			++digitNum;
			digits.push_back(num);
		}
	}

};

#endif