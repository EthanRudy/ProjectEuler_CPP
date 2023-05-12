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

void seiveOfEratosthenes(int n, std::vector<long long>& res) {
	bool* prime = (bool*)malloc(sizeof(bool) * n);
	memset(prime, true, sizeof(bool) * n);

	for (int p = 2; p * p <= n; ++p) {
		if (prime[p]) {
			for (int i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}

	std::vector<long long> primes;

	for (int i = 2; i <= n; ++i) {
		if (prime[i]) { res.push_back(i); }
	}
}

void prime_factors(long long n, std::vector<long long>& factVec) {
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
}
