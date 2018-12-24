#include "FractionFactory.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
	char choice = 1;
	char oper;
	char exit = 27;
	int numer;
	int denomin;
	char dummy;
	FractionFactory calculator;
	
	
	while (choice != exit)
	{
		cout << "Enter first fraction (1/2): ";
		cin >> numer >> dummy >> denomin;
		auto first = calculator.createFraction(numer, denomin);
		cout << "Enter second fraction (1/2): ";
		cin >> numer >> dummy >> denomin;
		auto second = calculator.createFraction(numer, denomin);
		cout << "Enter operator: ";
		cin >> oper;
		auto result = calculator.createFraction(0, 1);
		switch (oper)
		{
		case '+':
		{
			*result = *first + *second;
			break; 
		}
		case '-':
		{
			*result = *first - *second;
			break;
		}
		case '*':
		{
			*result = *first * (*second);
			break;
		}
		case '/':
		{
			*result = *first / (*second);
			break;
		}
		}
		cout << "Result is: " << *result << endl;
		cout << "To continue - press any key\nTo exit - press ESC\n";
		choice = _getch();
	}

	return 0;
}