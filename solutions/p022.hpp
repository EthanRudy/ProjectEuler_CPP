#ifndef P022_HPP
#define P022_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class P022 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		std::vector<std::string> names;

		std::ifstream file("./inputs/p022.txt");
		std::string line;
		while (std::getline(file, line)) { }

		int commaPos = 0;
		while ((commaPos = line.find(',')) != std::string::npos) {
			names.push_back(line.substr(1, commaPos - 2));
			line.erase(0, commaPos + 1);
		}
		names.push_back(line.substr(1, line.size() - 2));

		std::sort(names.begin(), names.end());


		long long sum = 0;
		for (int i = 0; i < names.size(); ++i) {
			sum += (i + 1) * nameScore(names[i]);
		}



		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << sum << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 45 milliseconds YUCK
	}

	long long nameScore(std::string& str) {
		long long score = 0;
		for (char i : str) {
			score += (i - 64);
		}
		return score;
	}

};

#endif