#include "Fraction.h"
#include <utility>									// for swap
#include <stdexcept>								// for std::runtime_error

//Fraction constructor 1
Fraction::Fraction(int numerator) : m_numerator(numerator), m_denominator(1)
{
	m_gcd = 1;
}

//Fraction constructor 2
Fraction::Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
{
	if (denominator == 0)
		throw std::runtime_error("Invalid denominator");
	m_gcd = gcd(m_numerator, m_denominator);
	this->compress();
}

//Finding the Greatest Common Divisor, Euclidean algorithm
int Fraction::gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0 || b == 0)
		return 1;

	if (a == b)
		return a;

	if (a > b)
	{
		std::swap(a, b);
	}

	return gcd(a, b - a);
}

//Function for fraction compressing
void Fraction::compress()
{
	if (m_gcd == 1)
		return;
	else
	{
		m_numerator = m_numerator / m_gcd;
		m_denominator = m_denominator / m_gcd;
		m_gcd = 1;
	}
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	if (left.m_denominator == right.m_denominator)
	{
		return Fraction((left.m_numerator + right.m_numerator), left.m_denominator);
	}
	else
	{
		return Fraction((left.m_numerator * right.m_denominator + right.m_numerator * left.m_denominator), left.m_denominator * right.m_denominator);
	}
}

Fraction operator+(const Fraction& left, int num)
{
	Fraction tmp(num);
	return (left + tmp);
}

Fraction operator+(int num, const Fraction& right)
{
	return (right + num);
}

Fraction operator- (const Fraction& left, const Fraction& right)
{
	if (left.m_denominator == right.m_denominator)
	{
		return Fraction((left.m_numerator - right.m_numerator), left.m_denominator);
	}
	else
	{
		return Fraction((left.m_numerator * right.m_denominator - right.m_numerator * left.m_denominator), left.m_denominator * right.m_denominator);
	}
}

Fraction operator-(const Fraction& left, int num)
{
	Fraction tmp(num);
	return (left - tmp);
}

Fraction operator-(int num, const Fraction& right)
{
	Fraction tmp(num);
	return (tmp - right);
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	return Fraction((left.m_numerator * right.m_numerator), (left.m_denominator * right.m_denominator));
}

Fraction operator*(const Fraction& left, int num)
{
	if (num == 0)
		return Fraction(0, 1);

	return Fraction((left.m_numerator * num), left.m_denominator);
}

Fraction operator*(int num, const Fraction& right)
{
	return (right * num);
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	if (right.m_denominator == 0)
		throw std::runtime_error("Invalid denominator in the right fraction");

	return Fraction((left.m_numerator * right.m_denominator), (left.m_denominator * right.m_numerator));
}

Fraction operator/(const Fraction& left, int num)
{
	if (num == 0)
		throw std::runtime_error("Cannot be divided by zero");

	Fraction tmp(num);
	return (left / tmp);
}

Fraction operator/(int num, const Fraction& right)
{
	if (num == 0)
		return Fraction(0, 1);

	Fraction tmp(num);
	return (tmp / right);
}

Fraction Fraction::operator+= (const Fraction& right)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	return (tmp + right);
}

Fraction Fraction::operator-= (const Fraction& right)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	return (tmp - right);
}

Fraction Fraction::operator*= (const Fraction& right)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	return (tmp * right);
}

Fraction Fraction::operator/= (const Fraction& right)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	return (tmp / right);
}

Fraction Fraction::operator++()
{
	return *this = (*this + 1);
}

Fraction Fraction::operator++(int)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	++(*this);
	return tmp;
}

Fraction Fraction::operator--()
{
	return *this = (*this - 1);
}

Fraction Fraction::operator--(int)
{
	Fraction tmp(this->m_numerator, this->m_denominator);
	--(*this);
	return tmp;
}

Fraction Fraction::operator-() const
{
	return Fraction(-(this->m_numerator), this->m_denominator);
}

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
	return out;
}

std::istream& operator>> (std::istream &in, Fraction &fraction)
{
	char dummy;
	in >> fraction.m_numerator >> dummy >> fraction.m_denominator;
	return in;
}

bool operator== (const Fraction &left, const Fraction &right)
{
	if (left.m_denominator == right.m_denominator)
		return (left.m_numerator == right.m_numerator) ? true : false;
	else
		return ((left.m_numerator * right.m_numerator) == (right.m_numerator * left.m_denominator)) ? true : false;
}

bool operator!= (const Fraction &left, const Fraction &right)
{
	return (left == right) ? false : true;
}

bool operator< (const Fraction &left, const Fraction &right)
{
	if (left.m_denominator == right.m_denominator)
		return (left.m_numerator < right.m_numerator) ? true : false;
	else
		return ((left.m_numerator * right.m_numerator) < (right.m_numerator * left.m_denominator)) ? true : false;
}

bool operator<= (const Fraction &left, const Fraction &right)
{
	if (left.m_denominator == right.m_denominator)
		return (left.m_numerator <= right.m_numerator) ? true : false;
	else
		return ((left.m_numerator * right.m_numerator) <= (right.m_numerator * left.m_denominator)) ? true : false;
}

bool operator> (const Fraction &left, const Fraction &right)
{
	if (left.m_denominator == right.m_denominator)
		return (left.m_numerator > right.m_numerator) ? true : false;
	else
		return ((left.m_numerator * right.m_numerator) > (right.m_numerator * left.m_denominator)) ? true : false;
}

bool operator>= (const Fraction &left, const Fraction &right)
{
	if (left.m_denominator == right.m_denominator)
		return (left.m_numerator >= right.m_numerator) ? true : false;
	else
		return ((left.m_numerator * right.m_numerator) >= (right.m_numerator * left.m_denominator)) ? true : false;
}