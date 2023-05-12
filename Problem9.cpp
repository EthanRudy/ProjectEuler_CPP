#include <iostream>
#include "Timer.hpp"

int main() {
	timer timer;
	timer.start();

	int prod = 0;
	for (int a = 1; a < 998; ++a) {
		for (int b = 1; b < a; ++b) {
			int c = 1000 - a - b;
			if (a == b || a == c || b == c) { continue; }
			if (a > c || b > c) { continue; }
			if (a * a + b * b == c * c) {
				if (a + b + c == 1000) {
					prod = a * b * c;
					goto end;
				}
			}
		}
	}

	end:
	
	timer.end();

	std::cout << "Answer: " << prod << "\n";
	std::cout << "Found in: " << timer.duration(microsecond) << " microseconds\n";

	// ~155 Microseconds
}
