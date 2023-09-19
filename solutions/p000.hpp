/*
	This is the partent (super) class for the problems found in this folder, there isn't any real code
*/

#ifndef P000_HPP
#define P000_HPP

#include <iostream>

class Solution {
private:
	// This is where constants and stuff will go
public:

	// If I have to fill something, it will be filled in a constructor

	void run() {
		std::cout << "If you're seeing this, you did something wrong :P\n";
	};	// This will actually run the solution
};

#endif

/*

File Template

#ifndef PXXX_HPP
#define PXXX_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
// Any other custom headers needed

#include <iostream>
// Any other official headers needed

class PXXX : Solution {
private:
public:

	void run(){
		precise_timer timer;

		int duration = timer.get_duration<int, std::chrono::seconds>();
		std::cout << "Solution: " << "ANSWER" << "\n";
		std::cout << "Solution found in " << duration << " seconds";
		// Avg runtime: 1 seconds
	}

};

#endif

*/