#pragma once
#include <vector>

/*
	Writing some basic functions, don't want to work with templates and exceptions just yet
*/

bool prime(int n) {
	if (n < 2) { return false; }

	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

bool prime(long n) {
	if (n < 2) { return false; }

	long i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

bool prime(long long n) {
	if (n < 2) { return false; }

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

std::vector<int> seiveofEratosthenes(int max) {
	if (max < 1) { throw std::invalid_argument("Argument must be positive and nonzero."); }
	bool* prime = (bool*)malloc(sizeof(bool) * max);
	memset(prime, true, sizeof(bool) * max);

	for (int p = 2; p * p<= max; ++p) {
		if (prime[p]) {
			for (int i = p * p; i <= max; i += p) {
				prime[i] = false;
			}
		}
	}

	std::vector<int> primes;
	for (int i = 2; i < max; ++i) {
		if (prime[i]) { primes.push_back(i); }
	}

	return primes;
}