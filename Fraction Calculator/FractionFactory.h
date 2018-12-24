#pragma once

#include "Fraction.h"
#include <memory>

class FractionFactory
{
public:
	std::unique_ptr<Fraction> createFraction(int, int);	
};

std::unique_ptr<Fraction> FractionFactory::createFraction(int numerator, int denominator)
{
	return std::unique_ptr<Fraction>(new Fraction(numerator, denominator));
}
