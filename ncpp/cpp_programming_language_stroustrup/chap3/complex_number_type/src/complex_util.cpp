// cpp file for "complex_util.hpp"

#include "../inc/complex_util.hpp"

Complex::Complex(double re, double im): _re(re), _im(im) {}
Complex::Complex(double re): _re(re), _im(0) {}
Complex::Complex(): _re(0), _im(0) {}

double Complex::real() const { return this->_re; }
double Complex::imag() const { return this->_im; }
void Complex::real(double re) { this->_re = re; }
void Complex::imag(double im) { this->_im = im; }

//Complex& Complex::operator+=(const Complex& z) {
	//this->_re += z.real();
	//this->_im += z.imag();
	//return *this;
//}

//Complex& Complex::operator-=(const Complex& z) {
	//this->_re -= z.real();
	//this->_im -= z.imag();
	//return *this;
//}

//Complex& Complex::operator*=(const Complex& z) {
	//this->_re *= z.real();
	//this->_im *= z.imag();
	//return *this;
//}

//Complex& Complex::operator/=(const Complex& z) {
	//this->_re /= z.real();
	//this->_im /= z.imag();
	//return *this;
//}


Complex& Complex::operator+=(Complex z) {
	this->_re += z.real();
	this->_im += z.imag();
	return *this;
}

Complex& Complex::operator-=(Complex z) {
	this->_re -= z.real();
	this->_im -= z.imag();
	return *this;
}

Complex& Complex::operator*=(Complex z) {
	this->_re *= z.real();
	this->_im *= z.imag();
	return *this;
}

Complex& Complex::operator/=(Complex z) {
	this->_re /= z.real();
	this->_im /= z.imag();
	return *this;
}

// return new copy without effecting callers copy
Complex operator+(const Complex& z1, const Complex& z2) {
	Complex temp;
	temp.real(z1.real() + z2.real());
	temp.imag(z1.imag() + z2.imag());
	return temp;
}
Complex operator-(const Complex& z1, const Complex& z2) {
	Complex temp;
	temp.real(z1.real() - z2.real());
	temp.imag(z1.imag() - z2.imag());
	return temp;
}
Complex operator-(const Complex& z) {
	Complex temp;
	temp.real(-z.real());
	temp.imag(-z.imag());
	return temp;
}
Complex operator*(const Complex& z1, const Complex& z2) {
	Complex temp;
	temp.real(z1.real() * z2.real());
	temp.imag(z1.imag() * z2.imag());
	return temp;
}
Complex operator/(const Complex& z1, const Complex& z2) {
	Complex temp;
	temp.real(z1.real() / z2.real());
	temp.imag(z1.imag() / z2.imag());
	return temp;
}

Complex* operator+(const Complex* z1, const Complex& z2) {
	Complex* temp = new Complex();
	temp->real(z1->real() + z2.real());
	temp->imag(z1->imag() + z2.imag());
	return temp;
}

bool operator==(const Complex& z1, const Complex& z2) {
	return z1.real() == z2.real() && z1.imag() == z2.imag();
}

bool operator!=(const Complex& z1, const Complex& z2) {
	return !(z1 == z2);
}

std::ostream& operator<<(std::ostream& out, const Complex& z) {
	out << z.real() << " + " << z.imag() << "i";
	return out;
}

// if not overloaded then it'll return the memory(heap) address
std::ostream& operator<<(std::ostream& out, const Complex* z) {
	out << z->real() << " + " << z->imag() << "i";
	return out;
}