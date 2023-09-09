#pragma once
#include <vector>

/*
	Writing some basic functions, don't want to work with templates and exceptions just yet
*/

bool prime(int n) {
	if (n == 1) { return false; }

	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

bool prime(long n) {
	if (n == 1) { return false; }

	long i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

bool prime(long long n) {
	if (n == 1) { return false; }

	long long i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

std::vector<int> primeFactors(int n) {
	std::vector<int> factVec;

	while (n % 2 == 0) {
		n /= 2;
		if (factVec.size() == 0) { factVec.push_back(2); }
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			factVec.push_back(i);
			n /= i;
		}
	}

	if (n > 2) { factVec.push_back(n); }

	return factVec;
}


std::vector<long> primeFactors(long n) {
	std::vector<long> factVec;

	while (n % 2 == 0) {
		n /= 2;
		if (factVec.size() == 0) { factVec.push_back(2); }
	}

	for (long i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			factVec.push_back(i);
			n /= i;
		}
	}

	if (n > 2) { factVec.push_back(n); }

	return factVec;
}


std::vector<long long> primeFactors(long long n) {
	std::vector<long long> factVec;

	while (n % 2 == 0) {
		n /= 2;
		if (factVec.size() == 0) { factVec.push_back(2); }
	}

	for (long long i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			factVec.push_back(i);
			n /= i;
		}
	}

	if (n > 2) { factVec.push_back(n); }

	return factVec;
}