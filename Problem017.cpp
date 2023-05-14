#include <iostream>
#include <map>
#include "Timer.hpp"

std::map<int, int> ones = {
	{1, 3}, // One
	{2, 3}, // Two
	{3, 5}, // Three
	{4, 4},	// Four
	{5, 4},	// Five
	{6, 3},	// Six
	{7, 5}, // Seven
	{8, 5},	// Eight
	{9, 4}, // Nine
};
std::map<int, int> teens = {
	{10, 3},	// Ten
	{11, 6},	// Eleven
	{12, 6},	// Twelve
	{13, 8},	// Thirteen
	{14, 8},	// Fourteen
	{15, 7},	// Fifteen
	{16, 7},	// Sixteen
	{17, 9},	// Seventeen
	{18, 8},	// Eighteen
	{19, 8},	// Nineteen
};
std::map<int, int> tens = {
	{2, 6},	// Twenty
	{3, 6},	// Thirty
	{4, 5},	// Forty
	{5, 5},	// Fifty
	{6, 5},	// Sixty
	{7, 7},	// Seventy
	{8, 6},	// Eighty
	{9, 6},	// Ninety
};

int getStringLength(int n);

int main() {
	timer timer;
	timer.start();

	int ans = 0;
	for (int i = 1; i < 1001; ++i) {
		ans += getStringLength(i);
	}

	timer.end();

	std::cout << "Answer: " << ans << "\n";
	std::cout << "Found in: " << timer.duration(microsecond) << " microseconds\n";

	// ~330 Microseconds
}

int getStringLength(int n) {
	if (n == 0) { return 4; }
	else if (n == 1000) { return 11; }
	int length = 0;

	if (n > 99) {
		// Hundreds are present
		length += ones[n / 100] + 7;
		n %= 100;
		if (n != 0) { length += 3; }	// Handle the and
	}
	if (n > 19) {
		length += tens[n / 10];
		n %= 10;
	}
	else if (n > 10) {
		length += teens[n];
		n = 0;
	}
	else if (n == 10) { length += 3; }
	if (n != 0) { length += ones[n]; }

	return length;
}
