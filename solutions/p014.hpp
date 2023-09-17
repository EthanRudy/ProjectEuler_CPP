#ifndef P014_HPP
#define P014_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>
#include <vector>

class P014 : Solution {
private:
	const int MAX = 1000000;
	std::vector<int> sequenceLen;
public:

	P014() {
		sequenceLen.resize(MAX, -1);
	}

	void run() {
		precise_timer timer;

		int longest = 0, longestN;
		for (int i = 1; i < MAX; ++i) {
			collatz_len(i);
			if (sequenceLen[i] > longest) {
				longest = sequenceLen[i];
				longestN = i;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << longestN << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 40 milliseconds
	}

	int collatz_len(long long n) {
		if (n == 1) { return 1; }	// Sequence Ends

		if (n < MAX && sequenceLen[n] != -1) { return sequenceLen[n]; }	// Sequence already calculated, use the stored value

		long long nextN;
		if (n % 2 == 0) { nextN = n / 2; }	// Calculate next number in sequence
		else { nextN = n * 3 + 1; }

		long long len = 1 + collatz_len(nextN);

		if (n < sequenceLen.size()) { sequenceLen[n] = len; }

		return len;
	}
};

#endif