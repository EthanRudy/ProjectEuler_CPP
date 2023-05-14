#include <iostream>
#include "Timer.hpp"
#include "BigInt.hpp"

int main() {
	timer timer;
	timer.start();

	int sum = 0;
	BigInt num = factorial(100);
	std::string str = num.to_string();
	for (char c : str) { sum += (c - '0'); }
	
	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~220 Milliseconds
}
