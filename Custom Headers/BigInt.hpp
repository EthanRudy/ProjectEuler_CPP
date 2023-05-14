// TODO
/*
* File info
*/

#include <iostream>

#ifndef BIGINT_HPP
#define BIGINT_HPP

class BigInt {
	std::string val;
	char sig;

public:
	// Constructors
	BigInt();
	BigInt(const BigInt& n);
	BigInt(const long long& n);
	BigInt(const std::string& n);

	// Assignment Operator
	BigInt& operator=(const BigInt& n);
	BigInt& operator=(const long long& n);
	BigInt& operator=(const std::string& n);

	// Urnary Operators
	BigInt operator+() const;
	BigInt operator-() const;

	// Arithemetic Operators
	BigInt operator+(const BigInt& n) const;
	BigInt operator-(const BigInt& n) const;
	BigInt operator*(const BigInt& n) const;
	BigInt operator/(const BigInt& n) const;
	BigInt operator%(const BigInt& n) const;
	BigInt operator+(const long long& n) const;
	BigInt operator-(const long long& n) const;
	BigInt operator*(const long long& n) const;
	BigInt operator/(const long long& n) const;
	BigInt operator%(const long long& n) const;
	BigInt operator+(const std::string& n) const;
	BigInt operator-(const std::string& n) const;
	BigInt operator*(const std::string& n) const;
	BigInt operator/(const std::string& n) const;
	BigInt operator%(const std::string& n) const;

	// Arithemetic & Assignment Operators
	BigInt& operator+=(const BigInt& n);
	BigInt& operator-=(const BigInt& n);
	BigInt& operator*=(const BigInt& n);
	BigInt& operator/=(const BigInt& n);
	BigInt& operator%=(const BigInt& n);
	BigInt& operator+=(const long long& n);
	BigInt& operator-=(const long long& n);
	BigInt& operator*=(const long long& n);
	BigInt& operator/=(const long long& n);
	BigInt& operator%=(const long long& n);
	BigInt& operator+=(const std::string& n);
	BigInt& operator-=(const std::string& n);
	BigInt& operator*=(const std::string& n);
	BigInt& operator/=(const std::string& n);
	BigInt& operator%=(const std::string& n);

	// Increment and Decrement
	BigInt& operator++();	// Pre inc
	BigInt& operator--();	// Pre dec
	BigInt operator++(int);	// Post inc
	BigInt operator--(int);	// Post dec

	// Boolean operators
	bool operator<(const BigInt& n) const;
	bool operator>(const BigInt& n) const;
	bool operator<=(const BigInt& n) const;
	bool operator>=(const BigInt& n) const;
	bool operator==(const BigInt& n) const;
	bool operator!=(const BigInt& n) const;
	bool operator<(const long long& n) const;
	bool operator>(const long long& n) const;
	bool operator<=(const long long& n) const;
	bool operator>=(const long long& n) const;
	bool operator==(const long long& n) const;
	bool operator!=(const long long& n) const;
	bool operator<(const std::string& n) const;
	bool operator>(const std::string& n) const;
	bool operator<=(const std::string& n) const;
	bool operator>=(const std::string& n) const;
	bool operator==(const std::string& n) const;
	bool operator!=(const std::string& n) const;

	// I/O Operators
	friend std::istream& operator>>(std::istream& in, BigInt& n);
	friend std::ostream& operator<<(std::ostream& out, const BigInt& n);

	std::string to_string() const;
	// Add potential to_int and to_long, to_long_long
};

#endif BIGINT_HPP



#ifndef BIGINT_UTILS_HPP
#define BIGINT_UTILS_HPP

// Used mostly for division with quotient and remainder
#include <tuple>

/*
	Checks if a passed string is a valid representation of a number
*/
bool is_valid_num(const std::string& num) {
	for (char digi : num) {
		if (digi < '0' || digi > '9') { return false; }
	}
	return true;
}

/*
	Trims the leading insignificant zeros of the passed string
*/
void trim_leading_zeros(std::string& num) {
	size_t i;
	for (i = 0; i < num.size(); ++i) {
		if (num[i] != '0') { break; }
	}

	// Is zero case
	if (i == num.size()) { num = "0"; }
	// Trim
	else { num = num.substr(i); }
}

/*
	Adds padding zeros to the front of the passed string
*/
void add_front_padding(std::string& num, size_t nZeros) {
	num = std::string(nZeros, '0') + num;
}

/*
	Adds padding zeros to the back of the passed string
*/
void add_back_padding(std::string& num, size_t nZeros) {
	num += std::string(nZeros, '0');
}

/*
	Identifies the smaller and larger of the two passed integer and makes them the same length
*/
std::tuple<std::string, std::string> get_max_min(const std::string& n1, const std::string& n2) {
	std::string min, max;
	if (n1.size() > n2.size() || n1.size() == n2.size() && n1 > n2) {
		max = n1;
		min = n2;
	}
	else {
		max = n2;
		min = n1;
	}

	// Add padding to min to max the max
	add_front_padding(min, max.size() - min.size());

	return std::make_tuple(max, min);
}

/*
	Checks whether the passed string is a power of ten
	(For division optimization)
*/
bool is_pow10(const std::string& num) {
	if (num[0] != '1') { return false; }
	for (size_t i = 1; i < num.size(); ++i) {
		if (num[i] != '0') { return false; }
	}
	return true;
}

#endif BIGINT_UTILS_HPP


#ifndef BIGINT_CONSTRUCTORS_HPP
#define BIGINT_CONSTRUCTORS_HPP

#include <string>

// Default Constructor
BigInt::BigInt() {
	val = "0";
	sig = '+';
}

// Copy Constructor
BigInt::BigInt(const BigInt& n) {
	val = n.val;
	sig = n.sig;
}

// Integer Constructor
BigInt::BigInt(const long long& n) {
	val = std::to_string(std::abs(n));
	if (n < 0) { sig = '-'; }
	else { sig = '+'; }
}

// String Constructor
BigInt::BigInt(const std::string& n) {
	if (n[0] == '+' || n[0] == '-') {	// Sign specified
		std::string mag = n.substr(1);
		if (is_valid_num(mag)) {
			val = mag;
			sig = n[0];
		}
		else {
			throw std::invalid_argument("Expected an integer, got \'" + n + "\'");
		}
	}
	else {	// Sign not specified
		if (is_valid_num(n)) {
			val = n;
			sig = '+';
		}
		else {
			throw std::invalid_argument("Expected an integer, got \'" + n + "\'");
		}
	}
	trim_leading_zeros(val);
}


#endif BIGINT_CONSTRUCTORS_HPP


#ifndef BIGINT_CONVERSIONS_HPP
#define BIGINT_CONVERSIONS_HPP

// To String
std::string BigInt::to_string() const {
	// Cursed ass ternary return
	return this->sig == '-' ? '-' + this->val : this->val;
}

// TODO later, not really needed
// To int

// To long

// To long long

#endif BIGINT_CONVERSIONS_HPP


#ifndef BIGINT_ASSIGNMENT_OPERATORS_HPP
#define BIGINT_ASSIGNMENT_OPERATORS_HPP

// BigInt = BigInt
BigInt& BigInt::operator=(const BigInt& n) {
	val = n.val;
	sig = n.sig;

	return *this;
}

// BigInt = integer
BigInt& BigInt::operator=(const long long& n) {
	BigInt T(n);
	val = T.val;
	sig = T.sig;

	return *this;
}

// BigInt = string
BigInt& BigInt::operator=(const std::string& n) {
	BigInt T(n);
	val = T.val;
	sig = T.sig;

	return *this;
}

#endif BIGINT_ASSIGNMENT_OPERATORS_HPP


#ifndef BIGINT_URNARY_OPERATORS_HPP
#define BIGINT_URNARY_OPERATORS_HPP

BigInt BigInt::operator+() const {
	return *this;
}

BigInt BigInt::operator-() const {
	BigInt T;
	T.val = val;
	if (val != "0") {
		if (sig == '+') { T.sig = '-'; }
		else { T.sig = '+'; }
	}

	return T;
}


#endif BIGINT_URNARY_OPERATORS_HPP


#ifndef BIGINT_BOOLEAN_OPERATORS_HPP
#define BIGINT_BOOLEAN_OPERATORS_HPP

// BigInt == BigInt
bool BigInt::operator==(const BigInt& n) const {
	return (sig == n.sig) && (val == n.val);
}

// BigInt != BigInt
bool BigInt::operator!=(const BigInt& n) const {
	return !(*this == n);	// Sneaky beaky like
}

// BigInt < BigInt
bool BigInt::operator<(const BigInt& n) const {
	if (sig == n.sig) {	// Same sign
		if (sig == '+') {	// Pos
			if (val.length() == n.val.length()) {
				return val < n.val;
			}
			else {
				return val.length() < n.val.length();
			}
		}
		else {
			return -(*this) > -n;	// Urnary gaming
		}
	}
	else {
		return sig == '-';
	}
}

// BigInt > BigInt
bool BigInt::operator>(const BigInt& n) const {
	return !((*this < n) || (*this == n));
}

// BigInt <= BigInt
bool BigInt::operator<=(const BigInt& n) const {
	return (*this < n) || (*this == n);
}

// BigInt >= BigInt
bool BigInt::operator>=(const BigInt& n) const {
	return !(*this < n); // Oh ye bud
}


// BigInt == Integer
bool BigInt::operator==(const long long& n) const {
	return *this == BigInt(n);
}

// Integer == BigInt
bool operator==(const long long& l, const BigInt& n) {
	return BigInt(l) == n;
}

// BigInt != Integer
bool BigInt::operator!=(const long long& n) const {
	return !(*this == BigInt(n));
}

// Integer != BigInt
bool operator!=(const long long& l, const BigInt& n) {
	return BigInt(l) != n;
}

// BigInt < Integer
bool BigInt::operator<(const long long& n) const {
	return *this < BigInt(n);
}

// Integer < BigInt
bool operator<(const long long& l, const BigInt& n) {
	return BigInt(l) < n;
}

// BigInt > Integer
bool BigInt::operator>(const long long& n) const {
	return *this > BigInt(n);
}

// Integer > BigInt
bool operator>(const long long& l, const BigInt& n) {
	return BigInt(l) > n;
}

// BigInt <= Integer
bool BigInt::operator<=(const long long& n) const {
	return *this <= BigInt(n);
}

// Integer <= BigInt
bool operator<=(const long long& l, const BigInt& n) {
	return BigInt(l) <= n;
}

// BigInt >= Integer
bool BigInt::operator>=(const long long& n) const {
	return *this >= BigInt(n);
}

// Integer >= BigInt
bool operator>=(const long long& l, const BigInt& n) {
	return BigInt(l) >= n;
}


// BigInt == String
bool BigInt::operator==(const std::string& n) const {
	return *this == BigInt(n);
}

// String == BigInt
bool operator==(const std::string& s, const BigInt& n) {
	return BigInt(s) == n;
}

// BigInt != String
bool BigInt::operator!=(const std::string& n) const {
	return *this != BigInt(n);
}

// String != BigInt
bool operator!=(const std::string& s, const BigInt& n) {
	return BigInt(s) != n;
}

// BigInt < String
bool BigInt::operator<(const std::string& n) const {
	return *this < BigInt(n);
}

// String < BigInt
bool operator<(const std::string& s, const BigInt& n) {
	return BigInt(s) < n;
}

// BigInt > String
bool BigInt::operator>(const std::string& n) const {
	return *this > BigInt(n);
}

// String > BigInt
bool operator>(const std::string& s, const BigInt& n) {
	return BigInt(s) > n;
}

// BigInt <= String
bool BigInt::operator<=(const std::string& n) const {
	return *this <= BigInt(n);
}

// String <= BigInt
bool operator<=(const std::string& s, const BigInt& n) {
	return BigInt(s) <= n;
}

// BigInt >= String
bool BigInt::operator>=(const std::string& n) const {
	return *this >= BigInt(n);
}

// String >= BigInt
bool operator>=(const std::string& s, const BigInt& n) {
	return BigInt(s) >= n;
}

#endif BIGINT_BOOLEAN_OPERATORS_HPP

#ifndef BIGINT_MATH_HPP
#define BIGINT_MATH_HPP

#include <string>

// ABS
BigInt abs(const BigInt& n) {
	return n < 0 ? -n : n;	// Them unary overloads nutty
}

// Big pow10
BigInt big_pow10(size_t exp) {
	return BigInt("1" + std::string(exp, '0'));
}

// pow (BigInt, BigInt)
BigInt pow(const BigInt& base, BigInt exp) {
	if (exp < 0) {
		if (base == 0) {
			throw std::logic_error("Cannode divide by zero");
		}
		return abs(base) == 1 ? base : 0;
	}
	if (exp == 0) {
		if (base == 0) {
			throw std::logic_error("Zero cannot be raised to zero");
		}
		return 1;
	}

	BigInt res = base, res_odd = 1;
	while (exp > 1) {
		if (exp % 2 != 0) { res_odd *= res; }
		std::cout << "\tInside pow function: " << (exp - 1) / 2 << " more calls (Gets exponentially slower \\(o_o`)/)\n";
		res *= res;
		exp /= 2;
	}

	return res * res_odd;
}

// pow (BigInt)
BigInt pow(const BigInt& base, int exp) {
	if (exp < 0) {
		if (base == 0) {
			throw std::logic_error("Cannot divide by zero");
		}
		return abs(base) == 1 ? base : 0;
	}
	if (exp == 0) {
		if (base == 0) {
			throw std::logic_error("Zero cannot be raised to zero");
		}
		return 1;
	}

	BigInt res = base, res_odd = 1;
	while (exp > 1) {
		if (exp % 2) { res_odd *= res; }
		res *= res;
		exp /= 2;
	}

	return res * res_odd;
}

// pow (Integer)
BigInt pow(const long long& base, int exp) {
	return pow(BigInt(base), exp);
}

// pow (String)
BigInt pow(const std::string& base, int exp) {
	return pow(BigInt(base), exp);
}

// Sqrt
BigInt sqrt(const BigInt& n) {
	if (n < 0) {
		throw std::invalid_argument("Cannor compute square root of a negative integer");
	}

	// Optim for low inputs
	if (n == 0) { return 0; }
	else if (n < 4) { return 1; }
	else if (n < 9) { return 2; }
	else if (n < 16) { return 3; }

	BigInt prev = -1;
	BigInt curr = big_pow10(n.to_string().size() / 2 - 1);

	while (abs(curr - prev) > 1) {
		prev = curr;
		curr = (n / prev + prev) / 2;	// TODO fix if not auto resolved
	}

	return curr;
}

// GCD(BigInt, BigInt)
BigInt gcd(const BigInt& n1, const BigInt& n2) {
	BigInt abs_n1 = abs(n1);
	BigInt abs_n2 = abs(n2);

	// Base case(s)
	if (abs_n2 == 0) { return abs_n1; }
	if (abs_n1 == 0) { return abs_n2; }

	BigInt rem = abs_n2;
	while (rem != abs_n2) {
		rem = abs_n1 % abs_n2;
		abs_n1 = abs_n2;
		abs_n2 = rem;
	}

	return abs_n1;
}

// GCD(BigInt, Integer)
BigInt gcd(const BigInt& n1, const long long& n2) {
	return gcd(n1, BigInt(n2));
}

// GCD(BigInt, String)
BigInt gcd(const BigInt& n1, const std::string& n2) {
	return gcd(n1, BigInt(n2));
}

// GCD(Integer, BigInt)
BigInt gcd(const long long& n1, const BigInt& n2) {
	return gcd(BigInt(n1), n2);
}

// GCD(String, BigInt)
BigInt gcd(const std::string& n1, const BigInt& n2) {
	return gcd(BigInt(n1), n2);
}

// LCM(BigInt, BigInt)
BigInt lcm(const BigInt& n1, const BigInt& n2) {
	if (n1 == 0 || n2 == 0) { return 0; }

	return abs(n1 * n2) / gcd(n1, n2);
}

// LCM(BigInt, Integer)
BigInt lcm(const BigInt& n1, const long long& n2) {
	return lcm(n1, BigInt(n2));
}

// LCM(BigInt, String)
BigInt lcm(const BigInt& n1, const std::string& n2) {
	return lcm(n1, BigInt(n2));
}

// LCM(Integer, BigInt)
BigInt lcm(const long long& n1, const BigInt& n2) {
	return lcm(BigInt(n1), n2);
}

// LCM(String, BigInt)
BigInt lcm(const std::string& n1, const BigInt& n2) {
	return lcm(BigInt(n1), n2);
}

// Factorial
BigInt factorial(const BigInt& n) {
	if (n == 1) { return 1; }
	return n * factorial(n - 1);
}

#endif BIGINT_MATH_HPP

#ifndef BIGINT_ARITHMETIC_OPERATORS_HPP
#define BIGINT_ARITHMETIC_OPERATORS_HPP

#include <climits>
#include <cmath>
#include <string>

const long long FLOAT_SQRT_LLONG_MAX = 3037000499;

// BigInt + BigInt
BigInt BigInt::operator+(const BigInt& n) const {
	if (this->sig == '+' && n.sig == '-') {
		BigInt r = n;
		r.sig = '+';
		return *this - r;
	}
	else if (this->sig == '-' && n.sig == '+') {
		BigInt l = *this;
		l.sig = '+';
		return -(l - n);
	}

	// Max & Min
	std::string max, min;
	std::tie(max, min) = get_max_min(this->val, n.val);

	BigInt res;
	res.val = "";
	short carry = 0, sum;
	for (long i = max.size() - 1; i >= 0; --i) {
		sum = (max[i] - '0') + (min[i] - '0') + carry;
		res.val = std::to_string(sum % 10) + res.val;
		carry = sum / (short)10;
	}
	if (carry) {
		res.val = std::to_string(carry) + res.val;
	}

	if (this->sig == '-' && res.val != "0") {
		res.sig = '-';
	}

	return res;
}

// BigInt - BigInt
BigInt BigInt::operator-(const BigInt& n) const {
	if (this->sig == '+' && n.sig == '-') {
		BigInt r = n;
		r.sig = '+';
		return *this + r;
	}
	else if (this->sig == '-' && n.sig == '+') {
		BigInt l = *this;
		l.sig = '+';
		return -(l + n);
	}

	BigInt res;
	std::string max, min;
	if (abs(*this) > abs(n)) {
		max = this->val;
		min = n.val;

		if (this->sig == '-') {
			res.sig = '-';
		}
	}
	else {
		max = n.val;
		min = this->val;

		if (n.sig == '+') {
			res.sig = '-';
		}
	}

	add_front_padding(min, max.size() - min.size());

	res.val = "";
	short diff;
	long i, j;

	for (i = max.size() - 1; i >= 0; --i) {
		diff = max[i] - min[i];
		if (diff < 0) { // Carry (0_0)
			for (j = i - 1; j >= 0; --j) {
				if (max[j] != '0') {
					--max[j];
					break;
				}
			}
			++j;
			while (j != i) {
				max[j] = '9';
				++j;
			}
			diff += 10;
		}
		res.val = std::to_string(diff) + res.val;
	}
	trim_leading_zeros(res.val);

	if (res.val == "0") {
		res.sig = '+';
	}

	return res;
}

// BigInt * BigInt (Karatsuba)
BigInt BigInt::operator*(const BigInt& n) const {
	if (*this == 0 || n == 0) { return BigInt(0); }
	else if (*this == 1) { return n; }
	else if (n == 1) { return *this; }

	BigInt prod;
	if (abs(*this) <= FLOAT_SQRT_LLONG_MAX && abs(n) <= FLOAT_SQRT_LLONG_MAX) {
		prod = std::stoll(this->val) * std::stoll(n.val);
	}
	else if (is_pow10(this->val)) {
		prod.val = n.val;
		prod.val.append(this->val.begin() + 1, this->val.end());
	}
	else if (is_pow10(n.val)) {
		prod.val = this->val;
		prod.val.append(n.val.begin() + 1, n.val.end());
	}
	else {
		// KARATSUBA

		std::string max, min;
		std::tie(max, min) = get_max_min(this->val, n.val);

		size_t half_len = max.size() / 2;
		auto half_len_ceil = (size_t)ceil(max.size() / 2.0);

		BigInt n1_h, n1_l;
		n1_h = max.substr(0, half_len);
		n1_l = max.substr(half_len);

		BigInt n2_h, n2_l;
		n2_h = min.substr(0, half_len);
		n2_l = min.substr(half_len);

		BigInt prod_h, prod_m, prod_l;
		prod_h = n1_h * n2_h;
		prod_l = n1_l * n2_l;
		prod_m = (n1_h + n1_l) * (n2_h + n2_l) - prod_h - prod_l;

		// Shift
		add_back_padding(prod_h.val, 2 * half_len_ceil);
		add_back_padding(prod_m.val, half_len_ceil);

		trim_leading_zeros(prod_h.val);
		trim_leading_zeros(prod_m.val);
		trim_leading_zeros(prod_l.val);

		prod = prod_h + prod_m + prod_l;
	}
	trim_leading_zeros(prod.val);

	if (this->sig == n.sig) {
		prod.sig = '+';
	}
	else {
		prod.sig = '-';
	}
	return prod;
}

// BigInt / BigInt (Helper)
std::tuple<BigInt, BigInt> divide(const BigInt& dividend, const BigInt& divisor) {
	BigInt quotient, remainder, temp;

	temp = divisor;
	quotient = 1;
	while (temp < dividend) {
		quotient++;
		temp += divisor;
	}
	if (temp > dividend) {
		quotient--;
		remainder = dividend - (temp - divisor);
	}

	return std::make_tuple(quotient, remainder);
}

// BigInt / Bigint (The Fuckening has begun)
BigInt BigInt::operator/(const BigInt& n) const {
	// Prepare your anus

	BigInt abs_dividend = abs(*this);
	BigInt abs_divisor = abs(n);

	if (n == 0) { throw std::logic_error("Attempted division by zero"); }
	if (abs_dividend < abs_divisor) { return BigInt(0); }
	if (n == 1) { return *this; }
	if (n == -1) { return -(*this); }

	BigInt quotient;
	if (abs_dividend <= LLONG_MAX && abs_divisor <= LLONG_MAX) {
		quotient = std::stoll(abs_dividend.val) / std::stoll(abs_divisor.val);
	}
	else if (abs_dividend == abs_divisor) {
		quotient = 1;
	}
	else if (is_pow10(abs_divisor.val)) {
		size_t digits_in_quotient = abs_dividend.val.size() - abs_divisor.val.size() + 1;
		quotient.val = abs_dividend.val.substr(0, digits_in_quotient);
	}
	else {
		quotient.val = "";
		BigInt chunk, chunk_quotient, chunk_remainder;
		size_t chunk_index = 0;
		chunk_remainder.val = abs_dividend.val.substr(chunk_index, abs_divisor.val.size() - 1);
		chunk_index = abs_divisor.val.size() - 1;

		while (chunk_index < abs_divisor.val.size()) {
			chunk.val = chunk_remainder.val.append(1, abs_dividend.val[chunk_index]);
			chunk_index++;
			while (chunk < abs_divisor) {
				quotient.val += "0";
				if (chunk_index < abs_dividend.val.size()) {
					chunk.val.append(1, abs_dividend.val[chunk_index]);
					chunk_index++;
				}
				else { break; }
			}
			if (chunk == abs_divisor) {
				quotient.val += "1";
				chunk_remainder = 0;
			}
			else if (chunk > abs_divisor) {
				trim_leading_zeros(chunk.val);
				std::tie(chunk_quotient, chunk_remainder) = divide(chunk, abs_divisor);
				quotient.val += chunk_quotient.val;
			}
		}
	}

	trim_leading_zeros(quotient.val);

	if (this->sig == n.sig) {
		quotient.sig = '+';
	}
	else {
		quotient.sig = '-';
	}

	return quotient;
}

// BigInt % BigInt (The Fuckening: Part two)
BigInt BigInt::operator%(const BigInt& n) const {
	BigInt abs_dividend = abs(*this);
	BigInt abs_divisor = abs(n);

	if (abs_divisor == 0) { throw std::logic_error("Attended division by zero"); }
	if (abs_divisor == 1 || abs_divisor == abs_dividend) { return BigInt(0); }

	BigInt remainder;
	if (abs_dividend <= LLONG_MAX && abs_divisor <= LLONG_MAX) {
		remainder = std::stoll(abs_dividend.val) % std::stoll(abs_divisor.val);
	}
	else if (abs_dividend < abs_divisor) {
		remainder = abs_dividend;
	}
	else if (is_pow10(n.val)) {
		size_t no_of_zeros = n.val.size() - 1;
		remainder.val = abs_dividend.val.substr(abs_dividend.val.size() - no_of_zeros);
	}
	else {
		BigInt quotient = abs_dividend / abs_divisor;
		remainder = abs_dividend - quotient * abs_divisor;
	}

	trim_leading_zeros(remainder.val);

	remainder.sig = this->sig;
	if (remainder.val == "0") {
		remainder.sig = '+';
	}

	return remainder;
}


// BigInt + Integer
BigInt BigInt::operator+(const long long& n) const {
	return *this + BigInt(n);
}

// Integer + BigInt
BigInt operator+(const long long& l, const BigInt& n) {
	return BigInt(l) + n;
}

// BigInt - Integer
BigInt BigInt::operator-(const long long& n) const {
	return *this - BigInt(n);
}

// Integer - BigInt
BigInt operator-(const long long& l, const BigInt& n) {
	return BigInt(l) - n;
}

// BigInt * Integer
BigInt BigInt::operator*(const long long& n) const {
	return *this * BigInt(n);
}

// Integer * BigInt
BigInt operator*(const long long& l, const BigInt& n) {
	return BigInt(l) * n;
}

// BigInt / Integer
BigInt BigInt::operator/(const long long& n) const {
	return *this / BigInt(n);
}

// Integer / BigInt
BigInt operator/(const long long& l, const BigInt& n) {
	return BigInt(l) / n;
}

// BigInt % Integer
BigInt BigInt::operator%(const long long& n) const {
	return *this % BigInt(n);
}

// Integer % BigInt
BigInt operator%(const long long& l, const BigInt& n) {
	return BigInt(l) % n;
}


// BigInt + String
BigInt BigInt::operator+(const std::string& n) const {
	return *this + BigInt(n);
}

// String + BigInt
BigInt operator+(const std::string& l, const BigInt& n) {
	return BigInt(l) + n;
}

// BigInt - String
BigInt BigInt::operator-(const std::string& n) const {
	return *this - BigInt(n);
}

// String - BigInt
BigInt operator-(const std::string& l, const BigInt& n) {
	return BigInt(l) - n;
}

// BigInt * String
BigInt BigInt::operator*(const std::string& n) const {
	return *this * BigInt(n);
}

// String * BigInt
BigInt operator*(const std::string& l, const BigInt& n) {
	return BigInt(l) * n;
}

// BigInt / String
BigInt BigInt::operator/(const std::string& n) const {
	return *this / BigInt(n);
}

// String / BigInt
BigInt operator/(const std::string& l, const BigInt& n) {
	return BigInt(l) / n;
}

// BigInt % String
BigInt BigInt::operator%(const std::string& n) const {
	return *this % BigInt(n);
}

// String % BigInt
BigInt operator%(const std::string& l, const BigInt& n) {
	return BigInt(l) % n;
}

#endif BIGINT_ARITHMETIC_OPERATORS_HPP

#ifndef BIGINT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP
#define BIGINT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP

// BigInt += BigInt
BigInt& BigInt::operator+=(const BigInt& n) {
	*this = *this + n;

	return *this;
}

// BigInt -= BigInt
BigInt& BigInt::operator-=(const BigInt& n) {
	*this = *this - n;

	return *this;
}

// BigInt *= BigInt
BigInt& BigInt::operator*=(const BigInt& n) {
	*this = *this * n;

	return *this;
}

// BigInt /= BigInt
BigInt& BigInt::operator/=(const BigInt& n) {
	*this = *this / n;

	return *this;
}

// BigInt %= BigInt
BigInt& BigInt::operator%=(const BigInt& n) {
	*this = *this % n;

	return *this;
}


// BigInt += Integer
BigInt& BigInt::operator+=(const long long& n) {
	*this = *this + BigInt(n);

	return *this;
}

// BigInt -= Integer
BigInt& BigInt::operator-=(const long long& n) {
	*this = *this - BigInt(n);

	return *this;
}

// BigInt *= Integer
BigInt& BigInt::operator*=(const long long& n) {
	*this = *this * BigInt(n);

	return *this;
}

// BigInt /= Integer
BigInt& BigInt::operator/=(const long long& n) {
	*this = *this / BigInt(n);

	return *this;
}

// BigInt %= Integer
BigInt& BigInt::operator%=(const long long& n) {
	*this = *this % BigInt(n);

	return *this;
}


// BigInt += String
BigInt& BigInt::operator+=(const std::string& n) {
	*this = *this + BigInt(n);

	return *this;
}

// BigInt -= String
BigInt& BigInt::operator-=(const std::string& n) {
	*this = *this - BigInt(n);

	return *this;
}

// BigInt *= String
BigInt& BigInt::operator*=(const std::string& n) {
	*this = *this * BigInt(n);

	return *this;
}

// BigInt /= String
BigInt& BigInt::operator/=(const std::string& n) {
	*this = *this / BigInt(n);

	return *this;
}

// BigInt %= String
BigInt& BigInt::operator%=(const std::string& n) {
	*this = *this % BigInt(n);

	return *this;
}

#endif BIGINT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP

#ifndef BIGINT_INCREMENT_DECREMENT_OPERATORS_HPP
#define BIGINT_INCREMENT_DECREMENT_OPERATORS_HPP

BigInt& BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt& BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt BigInt::operator++(int) {
	BigInt temp = *this;
	*this += 1;
	return temp;
}

BigInt BigInt::operator--(int) {
	BigInt temp = *this;
	*this -= 1;
	return temp;
}
#endif BIGINT_INCREMENT_DECREMENT_OPERATORS_HPP

#ifndef BIGINT_IOSTREAM_OPERATORS_HPP
#define BIGINT_IOSTREAM_OPERATORS_HPP

std::istream& operator>>(std::istream& in, BigInt& n) {
	std::string input;
	in >> input;
	n = BigInt(input);

	return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& n) {
	if (n.sig == '-') { out << n.sig; }
	out << n.val;

	return out;
}

#endif BIGINT_IOSTREAM_OPERATORS_HPP
