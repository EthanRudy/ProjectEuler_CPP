#pragma once
#include <string>
#include <algorithm>
#include <vector>

bool palindrome(int n) {
	std::string rstr = std::to_string(n);
	std::string str = rstr;
	std::reverse(rstr.begin(), rstr.end());

	return (str == rstr);
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