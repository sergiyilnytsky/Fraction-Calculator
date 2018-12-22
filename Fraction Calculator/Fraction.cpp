#include "Fraction.h"
#include <utility>									// for swap

//Fraction constructor 1
Fraction::Fraction(int numerator) : m_numerator(numerator), m_denominator(1)
{
	m_gcd = 1;
}

//Fraction constructor 2
Fraction::Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
{
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
	//TO DO Divide Zero excepsion

	return Fraction((left.m_numerator * right.m_denominator), (left.m_denominator * right.m_numerator));
}

Fraction operator/(const Fraction& left, int num)
{
	//TO DO Divide Zero excepsion

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

}