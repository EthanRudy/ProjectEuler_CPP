#include <iostream>
#include "Timer.hpp"

int main() {
	timer timer;
	timer.start();

	int amt = 20;
	long long ans = 0;

	while (true) {
		ans += amt;
		for (int i = 2; i <= amt; ++i) {
			if (ans % i != 0) { break; }
			if (i == amt) {
				goto end;
			}
		}
	}

	end:
	timer.end();

	std::cout << "Answer: " << ans << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~97 Milliseconds
}
