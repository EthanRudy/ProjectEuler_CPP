#include <string>
#include <vector>

bool palindrome(long long n) {
	std::string rStr = std::to_string(n);
	std::string nStr = rStr;
	std::reverse(rStr.begin(), rStr.end());

	return (nStr == rStr);
}

void factors(long long n, std::vector<int>& factVec) {
	for (long long i = 1; i <= n; ++i) {
		if (n % i == 0) {
			factVec.push_back(i);
		}
	}
}

int numOfFacts(long long n) {
	int facts = 0;
	for (int i = 1; i * i < n; ++i) {
		if (n % i == 0) { facts += 2; }
	}
	return facts;
}
