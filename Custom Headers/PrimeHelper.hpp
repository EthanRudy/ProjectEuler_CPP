#include <vector>

bool prime(long long n) {
	if (n == 1) { return false; }

	long long i = 2;
	while (i * i <= n) {
		if (n % i == 0) { return false; }
		i += 1;
	}

	return true;
}

std::vector<long long> factors(long long n) {
	std::vector<long long> factVec;
	for (long long i = 1; i <= n; ++i) {
		if (n % i == 0) {
			factVec.push_back(i);
		}
	}

	return factVec;
}

std::vector<long long> prime_factors(long long n) {
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
