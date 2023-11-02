#ifndef P039_HPP
#define P039_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P039 : Solution {
private:
	int MAX = 1000;
public:

	void run() {
		precise_timer timer;

		int count[1000];
		std::memset(count, 0, sizeof(int) * MAX);

		// Brute force but im eepy
		for (int n = 12; n < MAX; ++n) {
			for (int a = 1; a < n; ++a) {
				for (int b = a; b < n - a; ++b) {
					int c = n - a - b;
					if (c < b) { continue; }
					if (a * a + b * b == c * c) {
						++count[a + b + c];
					}
					
				}
			}
		}
		int largest = 0;
		int index = 0;
		for (int i = 0; i < MAX; ++i) {
			if (count[i] > largest) {
				largest = count[i];
				index = i;
			}
		}


		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << index << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 33 milliseconds
	}

};

#endif