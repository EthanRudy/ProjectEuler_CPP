#ifndef P029_HPP
#define P029_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/BigInt.hpp"

#include <iostream>
#include <set>

class P029 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		std::set<std::string> terms;

		for (int a = 2; a <= 100; ++a) {
			for (int b = 2; b <= 100; ++b) {
				BigInt n = big_pow(a, b);

				terms.insert(n.toString());	// Using strings because theres some bug in BigInt that I can't figure out
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << terms.size() << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 850 milliseconds, yikes thats close lol
	}

	BigInt big_pow(int b, int e) {
		BigInt res(b);

		while (e > 1) {
			res *= b;
			--e;
		}

		return res;
	}

};

#endif