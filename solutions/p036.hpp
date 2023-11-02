#ifndef P036_HPP
#define P036_HPP

#include "p000.hpp"
#include "../include/Timer.hpp"
#include "../include/numHelper.hpp"

#include <iostream>
#include <bitset>

class P036 : Solution {
private:
	int MAX = 1000000;
	int POWERS[20] = { 
						1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288 };
	std::vector<std::string> pal_bin;
public:

	void run() {
		precise_timer timer;

		// SOLUTION V1:
		//  Yes it did work, but it was taking almost a whole second, so doing a different one
		/*
		int ans = 0;
		for (int i = 0; i < MAX; ++i) {
			if (palindrome(i)) {
				// Only do the binary conversion if the base 10 number is palindromic
				std::string bin = dec_to_bin(i);
				if (palindrome(bin)) {
					ans += i;
				}
			}
		}
		*/
		
		
		// SOLUTION V2:
		// Also works, no time difference, but I wanted to make the new base_n_str function
		/*
		int ans = 0;
		for (int i = 1; i < 1000000; ++i) {
			if (!palindrome(i)) { continue; }
			//std::cout << i << " | " << base_n_str(i, 2) << "\n";
			if (palindrome(base_n_str(i, 2))) {
				ans += i;
				std::cout << i << "\n";
			}
		}
		*/

		/*
		SOLUTION V3:
		Okay bear with me, yes I checked that it wasn't bare, 1 million factorial is 0b1111010000|1001000000
		Which is 20 digits long, if the binary is palindromic, that means I just have to check 2 ^ 10 - 1 (1023) combinations
		-1 Because 0 and its binary is palindromic but they will not affect the result

		So I loop over every possible 10 bit binary number, slap a reversed copy on the front of it, convert it base 10, and then
		check if its palindromic

		Not going to work with odd digit length palindromes like 10101
		*/


		/*
		Solution V4:
		Okay bear a little bit more with me. I need to check up to 20 digit binary numbers
		Similarly to last time Im starting with the binary
		From there I'm going to generatr ONLY palindromes with whats gonna probably be some tree structure or something similar
		*/
		
		gen_palindromes("", '1', 20);

		int ans = 0;
		for (std::string& str : pal_bin) {
			int n = 0;
			for (int i = 0; i < str.size(); ++i) {
				n += (str[i] - '0') * POWERS[i];
			}

			if (palindrome(n)) {
				ans += n;
			}
		}
		
		

		int duration = timer.get_duration<int, std::chrono::milliseconds>();
		std::cout << "Solution: " << ans << "\n";
		std::cout << "Solution found in " << duration << " milliseconds";
		// Avg runtime: 8 milliseconds
	}

	void gen_palindromes(std::string cur, char insert, int depth) {
		int len = cur.length();

		if (len == depth) { return; }	// Base case

		// If the current size is odd, split the tree
		if (len % 2 == 1) {
			int middle = len / 2;
			cur = cur.substr(0, middle) + insert + cur.substr(middle);

			pal_bin.push_back(cur);

			gen_palindromes(cur, '0', depth);
			gen_palindromes(cur, '1', depth);
		}
		// If the current size is even, insert the middle character
		else {
			int middle = len / 2;
			cur = cur.substr(0, middle) + insert + cur.substr(middle);

			pal_bin.push_back(cur);

			gen_palindromes(cur, cur[middle], depth);
		}
		// Else
	}
};

#endif