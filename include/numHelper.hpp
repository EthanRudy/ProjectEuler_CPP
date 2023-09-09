#pragma once
#include <string>
#include <algorithm>

bool palindrome(int n) {
	std::string rstr = std::to_string(n);
	std::string str = rstr;
	std::reverse(rstr.begin(), rstr.end());

	return (str == rstr);
}