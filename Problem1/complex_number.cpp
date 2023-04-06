#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
#define M_PI  3.1415926535f 

Complex::Complex() : real{0.0f}, imag{0.0f}
{}

Complex::Complex(float r, float i) {
	real = r; imag = i;
}

float Complex::getImag() const
{
	return this->imag;
}

float Complex::getReal() const
{
	return this->real;
}

void Complex::setImag(float i) {
	imag = i;
}
void Complex::setReal(float r) {
	real = r;
}

DisplayType Complex::DISPLAY_TYPE{ DisplayType::POLAR_FORM };

DisplayType Complex::getDisplayType() {
	return DISPLAY_TYPE;
}

void Complex::setDisplayType(DisplayType dt) {
	DISPLAY_TYPE = dt;
}

Complex Complex::conjugate() {
	Complex s;
	s.real = real;
	s.imag = -imag;
	return s;
}

Complex Complex::add(const Complex& c) {
	return Complex(c.real + real, c.imag + imag);
}



Complex Complex::subtract(const Complex& c) {
	return Complex(real - c.real, imag - c.imag);
}



Complex Complex::multiply(const Complex& c) const { //(a+bi)(c+di)=ac+adi+cbi+bdii=ac-bd+i(ad+cb)
	return Complex(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
}




void Complex::multiply(float c) {
	real = c * real;
	imag = c * imag;
}

bool Complex::equals(const Complex& c) const {
	if (real == c.real && imag == c.imag)
		return true;
	return false;
}

float Complex::magnitude() const {
	return float(sqrt(real * real + imag * imag));
}
float Complex::phase() const {
	float phase;
	if (this->real > 0 && this->imag > 0) { // C I
		phase = atan(this->imag / this->real);
		return phase;
	}
	else if (this->real < 0 && this->imag > 0) { // C II
		phase = atan(this->imag / this->real) + M_PI;
		return phase;
	}
	else if (this->real < 0 && this->imag < 0) {  // CIII
		phase = atan(this->imag / this->real) - M_PI;
		return phase;
	}
	else if (this->real > 0 && this->imag < 0) { // CIV
		phase = atan(this->imag / this->real);
		return phase;
	}
	else {
		return 0;
	}
}
void Complex::toPolar(float* r, float* theta) const {
	*r = magnitude();
	*theta = phase();
}

Complex Complex::operator+(const Complex& other)  //operator addition
{
	return add(other);
}

Complex Complex::operator-(const Complex& other)  //operator subtraction
{
	return subtract(other);
}

Complex operator*(const Complex& c1, const Complex& c2) //operator multiplication
{
	float real = c1.real * c2.real - c1.imag * c2.imag;
	float imag = c1.real * c2.imag + c1.imag * c2.real;
	return Complex(real, imag);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	//os << "(" << std::setprecision(2) << std::fixed << c.real << ", " << c.imag << ")";
	ostringstream sstr;
	sstr << std::setprecision(2) << std::fixed;
	float v = 10.50f;
	sstr << v;
	string result = sstr.str();
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
	is >> c.real >> c.imag;
	return is;

}



