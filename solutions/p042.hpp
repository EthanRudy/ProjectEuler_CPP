#ifndef P042_HPP
#define P042_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
	// Any other custom headers needed

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class P042 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		// Read words from file
		std::vector<std::string> words;
		std::ifstream file("./inputs/p042.txt");
		std::string line;
		while (std::getline(file, line)) { }

		int commaPos = 0;
		while ((commaPos = line.find(',')) != std::string::npos) {
			words.push_back(line.substr(1, commaPos - 2));
			line.erase(0, commaPos + 1);
		}
		words.push_back(line.substr(1, line.size() - 2));

		// Generate triangle numbers of to max sum = 192 (RESPONSIBILITY)
		int MAX = 192;
		std::vector<int> tri = { 0 };
		int size = 0;
		while (tri[size] < MAX) {
			++size;
			tri.push_back(nth_tri(size));
		}

		// Find number of triangle words
		int ans = 0;
		for (std::string& str : words) {
			int total = 0;
			for (char& c : str) {
				total += (c - 'A') + 1;
			}

			if (std::find(tri.begin(), tri.end(), total) != tri.end()) {
				++ans;
			}
		}

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 6 milliseconds
	}

};

#endif