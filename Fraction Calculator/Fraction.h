#pragma once
#include <iostream>

class Fraction
{
public:
	Fraction(int numerator);
	Fraction(int numerator, int denominator);
	//Fraction(const Fraction& right);
	//Fraction(const Fraction&& right);

	friend Fraction operator+ (const Fraction& left, const Fraction& right);
	friend Fraction operator+ (const Fraction& left, int num);
	friend Fraction operator+ (int num, const Fraction& right);
	friend Fraction operator- (const Fraction& left, const Fraction& right);
	friend Fraction operator- (const Fraction& left, int num);
	friend Fraction operator- (int num, const Fraction& right);
	friend Fraction operator* (const Fraction& left, const Fraction& right);
	friend Fraction operator* (const Fraction& left, int num);
	friend Fraction operator* (int num, const Fraction& right);
	friend Fraction operator/ (const Fraction& left, const Fraction& right);
	friend Fraction operator/ (const Fraction& left, int num);
	friend Fraction operator/ (int num, const Fraction& right);

	Fraction operator+= (const Fraction& right);
	Fraction operator-= (const Fraction& right);
	Fraction operator*= (const Fraction& right);
	Fraction operator/= (const Fraction& right);

	Fraction operator++ ();																	//++Fraction
	Fraction operator++ (int);																//Fraction++
	Fraction operator-- ();																	//--Fraction
	Fraction operator-- (int);																//Fraction--

	Fraction operator-() const;

	friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
	friend std::istream& operator>> (std::istream &in, Fraction &fraction);

	friend bool operator== (const Fraction &left, const Fraction &right);
	friend bool operator!= (const Fraction &left, const Fraction &right);
	friend bool operator< (const Fraction &left, const Fraction &right);
	friend bool operator<= (const Fraction &left, const Fraction &right);
	friend bool operator> (const Fraction &left, const Fraction &right);
	friend bool operator>= (const Fraction &first, const Fraction &second);
private:
	void compress();
	int m_numerator;
	int m_denominator;
	int m_gcd;
	int gcd(int, int);																		//Greatest Common Divisor function
};