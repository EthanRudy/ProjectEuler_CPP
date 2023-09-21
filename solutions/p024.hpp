#ifndef P024_HPP
#define P024_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class P024 : Solution {
private:
public:

	void run() {
		precise_timer timer;

		int duration = timer.get_duration<int, std::chrono::seconds>();
		std::cout << "Solution: " << "ANSWER" << "\n";
		std::cout << "Solution found in " << duration << " seconds";
		// Avg runtime: 1 seconds
	}

};

#endif