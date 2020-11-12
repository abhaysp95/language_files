#ifndef FRACUTIL_HPP
#define FRACUTIL_HPP

#include <iostream>

class Fraction {
	private:
		int denom, numera, denomp, nump;
	public:
		Fraction(int a, int b);
		int fraction(int a, int b);
		int find_gcd(int n1, int n2);
		void reduce_fraction(int nump, int denomp);
		Fraction& operator+(const Fraction& n);
		Fraction& operator-(const Fraction& n);
		friend std::ostream& operator<<(std::ostream &os, const Fraction& n);
		friend std::istream& operator>>(std::istream &os, const Fraction& n);
};

#endif
