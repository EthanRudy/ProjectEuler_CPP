#ifndef P004_HPP
#define P004_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/numHelper.hpp"

#include <iostream>

class P004 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		const int MIN = 100, MAX = 1000;
		int smallestNum = 100;

		int largestPal = 0;
		for (int n1 = MAX; n1 > smallestNum; --n1) {
			for (int n2 = MAX; n2 > smallestNum; --n2) {
				int prod = n1 * n2;
				if (palindrome(prod) && largestPal < prod) {
					largestPal = prod;
					smallestNum = n2;	// Reduces runtime 75x
				}
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << largestPal << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 10 milliseconds
	}

};

#endif