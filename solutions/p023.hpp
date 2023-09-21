#ifndef P023_HPP
#define P023_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/numHelper.hpp"

#include <iostream>
#include <set>

class P023 : Solution {
private:
	const int MAX = 28124;
	std::set<int> abundants;
public:

	void run() {
		precise_timer timer;

		/*
			This is the first problem that I don't remember the actual solution too so I actually have to think now

			1st method:
				Step 1: generate all the abundant numbers from 1 to 28123
				Step 2: Calculate all unique sums of the the abundant numbers
				Step 3: Sum the numbers that weren't marked as sums of abundants
				Notes: 
					After some tests, there are like a handful of odd abudant numbers so I have to check them :(
					This is kinda slow ngl

			2nd method: (Chosen method)
				Step 1: generate all the abundant numbers from 1 to 28123
				Step 2: Check if its possible for it to be a sum
				Step 3: If its not a sum, add to the total
				Notes:
					No need for a boolean array to store if the number is a sum or not, instead everything is handled by the set
		*/

		// Starting from the given starting point to save like 11 iterations lol
		for (int i = 12; i < MAX; ++i) {
			if (sumFacts(i) > i) { abundants.insert(i); }
		}

		int sum = 0;
		for (int i = 0; i < MAX; ++i) {
			if (!abundantSum(i)) { sum += i; }
		}


		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 1200 milliseconds
	}

	bool abundantSum(int n) {
		if (n >= MAX) { return true; } // Given in the problem description

		for (int a : abundants) {
			if (a >= n) { return false; } // Cant make a sum of a + b == n if a >= n

			int b = n - a;
			if (abundants.count(b) == 0) { continue; }

			return true;	// No possible b was found for n = a + b
		}
		
		return false;	// Don't crash the program plz
	}

};

#endif