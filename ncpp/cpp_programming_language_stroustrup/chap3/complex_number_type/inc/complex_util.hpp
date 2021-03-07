// header file

#ifndef _GUARD_COMPLEX_UTIL_HPP_
#define _GUARD_COMPLEX_UTIL_HPP_

#include <iostream>

class Complex {
	private:
		double _re, _im;
	public:
		Complex(double re, double im);
		Complex(double re);
		Complex();

		double real() const;
		double imag() const;
		void real(double re);
		void imag(double im);

		Complex& operator+=(Complex z);
		Complex& operator-=(Complex z);
		Complex& operator*=(Complex z);
		Complex& operator/=(Complex z);
};

Complex operator+(const Complex& z1, const Complex& z2);
Complex operator-(const Complex& z1, const Complex& z2);
Complex operator-(const Complex& z);
Complex operator*(const Complex& z1, const Complex& z2);
Complex operator/(const Complex& z1, const Complex& z2);

// now, it is said that operator function must either be a member of a class or have
// atleast one parameter of the class type
Complex* operator+(const Complex* z1, const Complex& z2);
Complex* operator-(const Complex* z1, const Complex& z2);
Complex* operator*(const Complex* z1, const Complex& z2);
Complex* operator/(const Complex* z1, const Complex& z2);
// also, const before * means you can't change the value pointed by pointer

bool operator==(const Complex& z1, const Complex& z2);
bool operator!=(const Complex& z1, const Complex& z2);

std::ostream& operator<<(std::ostream& out, const Complex& z);
std::ostream& operator<<(std::ostream& out, const Complex* z);

#endif