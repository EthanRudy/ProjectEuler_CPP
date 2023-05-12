#include <iostream>
#include <fstream>
#include "Timer.hpp"
#include "BigInt.hpp"

int main() {
	timer timer;
	timer.start();

	std::ifstream input("p013.txt");
	std::string line;

	BigInt sum(0);
	while (std::getline(input, line)) {
		sum += line;
	}

	timer.end();

	std::cout << "Answer: " << sum.to_string().substr(0, 10) << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~8 Milliseconds
}
