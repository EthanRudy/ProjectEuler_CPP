#pragma once

#include <algorithm>
#include "BigInt.hpp"
#include <string>
#include <vector>

bool palindrome(int n) {
	std::string rstr = std::to_string(n);
	std::string str = rstr;
	std::reverse(rstr.begin(), rstr.end());

	return (str == rstr);
}

bool palindrome(const std::string& str) {
	std::string rstr = str;
	std::reverse(rstr.begin(), rstr.end());
	
	return (rstr == str);
}


std::vector<int> factors(int n) {
	std::vector<int> factVec;

	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			factVec.push_back(i);
		}
	}

	return factVec;
}

int numOfFacts(int n) {
	int facts = 0;

	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			(i * i == n) ? ++facts : facts += 2;
		}
	}

	return facts;
}

int numOfFacts(long n) {
	int facts = 0;

	for (long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			(i * i == n) ? ++facts : facts += 2;
		}
	}

	return facts;
}

int numOfFacts(long long n) {
	int facts = 0;

	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			(i * i == n) ? ++facts : facts += 2;
		}
	}

	return facts;
}

int sumFacts(int n) {
	// Optimized to not use factors() function

	int sum = 1;	// Pre-add 1, bc its not in a pair with n

	for (int i = 2; i * i <= n; ++i) {
		div_t d = div(n, i);
		if (d.rem == 0) {
			sum += i;

			if (d.quot != i) {	// Perfect squares have mirrored factor pairs, but we only want one
				sum += d.quot;
			}
		}
	}

	return sum;
}

bool pandigital(std::string str) {
	int digits[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (char c : str) {
		++digits[(c - '0') - 1];
	}

	for (int i = 0; i < str.size(); ++i) {
		if (digits[i] != 1) { return false; }
	}

	return true;
}

bool pandigital(const std::string& str, int min, int max) {
	std::vector<int> digits(max - min + 1, 0);

	for (char c : str) {
		++digits[(c - '0') - min];
	}

	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] != 1) { return false; }
	}

	return true;
}

int gcd(int a, int b) {
	int res = (a > b) ? b : a;
	while (res > 0) {
		if (a % res == 0 && b % res == 0) { break; }
	}

	return res;
}

// Yes not a BigInt
int factorial(int n) {
	if (n < 2) { return n; }
	return n * factorial(n - 1);
}

// Ended up not using this in Problem 036 but maybe it'll get used, either way I'm saving it for my discrete math homework
std::string dec_to_bin(int n) {
	if (n == 0) { return "0"; }

	std::string bin = "";

	while (n > 0) {
		bin = std::to_string(n % 2) + bin;
		n /= 2;
	}

	return bin;
}

// Slay new base n converter (Go too high and the ascii skip will get wacky)
std::string base_n_str(int n, int base) {
	std::string res = "";

	while (n > 0) {
		int d = n % base;
		res += ((d >= 0 && d <= 9) ? d + '0' : d + 'A');
		n /= base;
	}
	
	std::reverse(res.begin(), res.end());
	return res;
}

int nth_tri(int n) {
	return 0.5f * (n * (n + 1));
}