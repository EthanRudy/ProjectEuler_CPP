#include <string>

bool palindrome(long long n) {
	std::string rStr = std::to_string(n);
	std::string nStr = rStr;
	std::reverse(rStr.begin(), rStr.end());

	return (nStr == rStr);
}
