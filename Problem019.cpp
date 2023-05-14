#include <iostream>
#include "Timer.hpp"

int zeller(int day, int month, int year);

int main() {
    timer timer;
    timer.start();

    int sundays = 0;
    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 1; month < 13; ++month) {
            if (zeller(1, month, year) == 1) { ++sundays; }
        }
    }

    timer.end();

    std::cout << "Answer: " << sundays << "\n";
    std::cout << "Found in: " << timer.duration(microsecond) << " microseconds\n";

    // ~9 Microseconds
}

int zeller(int day, int month, int year) {
    if (month == 1) {
        month = 13;
        --year;
    } else if (month == 2) {
        month = 14;
        --year;
    }
    int k = year % 100;
    int j = year / 100;
    return (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}
