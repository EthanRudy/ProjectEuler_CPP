#include <iostream>
#include "Timer.hpp";

int main() {
	timer timer;
	timer.start();

	int sum = 0;
	for (int i = 3; i < 1000; ++i) {
		if (i % 3 == 0|| i % 5 == 0) {
			sum += i;
		}
	}

	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in " << timer.duration(microsecond) << " microseconds\n";
  
  // 2-3 Microseconds
}
