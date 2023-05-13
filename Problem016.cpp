#include <iostream>
#include "Timer.hpp"
#include "BigInt.hpp"

int main() {
	timer timer;
	timer.start();

	// New lib is goated
	BigInt num = pow(BigInt(2), 1000);
	std::string numStr = num.to_string();

	int ans = 0;
	for (char c : numStr) { ans += (c - '0'); }

	timer.end();

	std::cout << "Answer: " << ans << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~47 Milliseconds (o_0)
}
