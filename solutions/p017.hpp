#ifndef P017_HPP
#define P017_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P017 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int sum = 0;
		for (int i = 1; i <= 1000; ++i) {
			sum += numWordLength(i);
		}

		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 32 microseconds
	}

	// This is by far the worst code I've ever written
	int numWordLength(int n) {
		switch (n) {
		case 1: return 3;	// One
		case 2: return 3;	// Two
		case 3: return 5;	// Three
		case 4: return 4;	// Four
		case 5: return 4;	// Five
		case 6: return 3;	// Six
		case 7: return 5;	// Seven
		case 8: return 5;	// Eight
		case 9: return 4;	// Nine
		case 10: return 3;	// Ten
		case 11: return 6;	// Eleven
		case 12: return 6;	// Twelve
		case 13: return 8;	// Thirteen
		case 14: return 8;	// Fourteen
		case 15: return 7;	// Fifteen
		case 16: return 7;	// Sixteen
		case 17: return 9;	// Seventeen
		case 18: return 8;	// Eighteen
		case 19: return 8;	// Nineteen
		default: break;
		}

		if (n >= 20 && n < 100) {	// 2 digit < 100 not found yet
			int tens = n / 10;	// Tens place
			int ones = n % 10;	// Ones place
			switch (tens) {
			case 2:
				tens = 6;	// Twenty
				break;
			case 3:
				tens = 6;	// Thirty
				break;
			case 4:
				tens = 5;	// Forty
				break;
			case 5:
				tens = 5;	// Fifty
				break;
			case 6:
				tens = 5;	// Sixty
				break;
			case 7:
				tens = 7;	// Seventy
				break;
			case 8:
				tens = 6;	// Eighty
				break;
			case 9:
				tens = 6;	// Ninety
				break;
			default: break;
			}

			return tens + (ones != 0 ? numWordLength(ones) : 0);
		}

		if (n >= 100 && n < 1000) {
			int hundreds = n / 100;
			int tens = n % 100;

			return numWordLength(hundreds) + 7 + ((tens != 0) ? 3 + numWordLength(tens) : 0);	// +7 for the word "hundred" and +3 for word "and"
		}

		return 11;	// 1000
	}

};

#endif