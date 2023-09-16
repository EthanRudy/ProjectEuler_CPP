#include "../include/Timer.hpp"

#include <iostream>

int zellers(int year, int month, int day); // Looking for a return value of 1

void problem019() {
	precise_timer timer;

	int count = 0;
	for (int year = 1901; year < 2001; ++year) {
		for (int month = 1; month < 13; ++month) {
			if (zellers(year, month, 1) == 1) {
				++count;
			}
		}
	}

	int duration = timer.get_duration<int, std::chrono::microseconds>();
	std::cout << "Solution: " << count << "\n";
	std::cout << "Solution found in " << duration << " microseconds";
	// Avg runtime: 5 microseconds
}

int zellers(int year, int month, int day) {
	if (month < 3) {	// Part of Zeller's congruence, january and february count as the 13th and 14th month of the previous year \(o_o)/
		--year;
		month += 12;
	}

	return (day + ((13 * (month + 1)) / 5) + year + (year / 4) - (year / 100) + (year / 400)) % 7;
}
