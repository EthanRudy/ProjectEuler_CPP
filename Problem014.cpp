#include <iostream>
#include <vector>
#include "Timer.hpp"

const int MAX = 1000000;
std::vector<int> sequenceLength(MAX, -1);

int collatzLength(long long n);

int main() {
	timer timer;
	timer.start();

	long long longest = 0;
	int longestN;
	for (int i = 1; i < MAX; ++i) { 
		collatzLength(i);
		if (sequenceLength[i] > longest) {
			longest = sequenceLength[i];
			longestN = i;
		}
	}

	timer.end();

	std::cout << "Answer: " << longestN << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~46 Milliseconds
}

int collatzLength(long long n) {
	// N == 1 Base case
	if (n == 1) { return 1; }

	// Remaining sequence is already calculated
	if (n < MAX && sequenceLength[n] != -1) { return sequenceLength[n]; }

	// Remaining sequence is not calculated
	long long nextN;
	if (n % 2 == 0) { nextN = n / 2; }
	else { nextN = n * 3 + 1; }

	// Calculate the rest of the sequence
	long long res = 1 + collatzLength(nextN);
	// Fill the "cache" if it fits
	if (n < sequenceLength.size()) { sequenceLength[n] = res; }

	return res;
}
