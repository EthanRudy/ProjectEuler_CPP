#ifndef P033_HPP
#define P033_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>

class P033 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		// Took me like 20 minutes of debugging to realize I needed floats for the .25 ratio
		float numerator = 1, denominator = 1;
		for (int num = 12; num < 100; ++num) {
			for (int den = (num % 10) * 10; den > num && den < 100; ++den) {
				if (num % 10 != den / 10) { continue; }

				int nNum = num / 10;
				int nDen = den % 10;
				
				float quot = num / float(den);
				float nQuot = nNum / float(nDen);

				if (quot == nQuot) {
					float f = gcd(num, den);
					numerator *= num / f;
					denominator *= den / f;
				}
			}
		}

		int ans = denominator / gcd(numerator, denominator);


		int duration = timer.get_duration<int, std::chrono::microseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " microseconds";
		// Avg runtime: 5 microseconds :p
	}

};

#endif