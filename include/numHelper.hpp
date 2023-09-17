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