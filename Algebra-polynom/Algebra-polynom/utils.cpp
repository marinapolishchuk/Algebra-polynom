#include "utils.h"

#include <vector>
namespace utils {
	/* 2 Euclidean algorithm */
	std::vector<long long> euclideanAlgorithm(long long a, long long b, int prime) {
		std::vector<long long> answer;
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(0);
		if (b > a) {
			long long pocket = a;
			a = b;
			b = pocket;
		}
		if (b == 0) {
			answer[0] = a;
			answer[1] = 1;
			answer[2] = 0;
			return answer;
		}
		long long x2 = 1, x1 = 0,
			y2 = 0, y1 = 1;
		while (b >= 1) {
			long long q{ 0 };
			q = a / b;
			long long r = a - q * b;
			answer[1] = x2 - q * x1;
			answer[2] = y2 - q * y1;
			a = b;
			b = r;
			x2 = x1;
			x1 = answer[1];
			y2 = y1;
			y1 = answer[2];
		}
		a %= prime;
		x2 %= prime;
		y2 %= prime;
		if (a < 0) a += prime;
		if (x2 < 0) x2 += prime;
		if (y2 < 0) y2 += prime;
		answer[0] = a;
		answer[1] = x2;
		answer[2] = y2;
		return answer;
	}

	/*! #9
	* @brief Function to check if n is prime or not
	*/
	bool isPrime(int n) {
		if (n < 2)
			return false;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}

	/*! #9
	* @brief Mobius Function
	*/
	int mobius(int N) {
		// Base Case
		if (N == 1)
			return 1;
		// For a prime factor i check if i^2 is also
		// a factor.
		int p = 0;
		for (int i = 1; i <= N; i++) {
			if (N % i == 0 && isPrime(i)) {
				// Check if N is divisible by i^2
				if (N % (i * i) == 0)
					return 0;
				else
					// i occurs only once, increase p
					p++;
			}
		}
		// All prime factors are contained only once
		// Return 1 if p is even else -1
		return (p % 2 != 0) ? -1 : 1;
	}

	/*! #6
	* @brief Inverse for numbers
	*/
	long long inverse(long long number, long long prime) {
		long long a = number;
		long long b = prime;
		long long a_1 = 1;
		long long b_1 = 0;
		long long result = 0;
		while ((a != 1) && (b != 1)) {
			if ((a == 0) || (b == 0)) {
				return 0;
			}
			if (a >= b) {
				while (a >= b) {
					a -= b;
					a_1 -= b_1;
				}
			}
			else {
				while (b >= a) {
					b -= a;
					b_1 -= a_1;
				}
			}
		}
		if (a == 1) {
			result = a_1;
		}
		else {
			result = b_1;
		}
		result %= prime;
		if (result < 0) {
			result += prime;
		}
		return result;
	}

	/*! #6
	* @brief Division for numbers in field
	*/
	long long division_for_numbers(long long a, long long b, long long prime) {
		a *= inverse(b, prime);
		return a;
	}
}
