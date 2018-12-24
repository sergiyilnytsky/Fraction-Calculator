#include "FractionFactory.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
	/*char choice = 1;
	char oper;
	char exit = 27;
	int numer;
	int denomin;
	char dummy;
	FractionFactory calculator;
	*/
	try 
	{
		/*
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
		}*/
		Fraction f1(1, 2);
		Fraction f2(2, 3);
		Fraction f3(2, 4);

		cout << boolalpha << (f1 > f2) << endl;
		cout << (f1 < f2) << endl;
		cout << (f1 != f2) << endl;
		cout << (f1 == f3) << endl;
		cout << (f2 == f3) << endl;

		cout << f1 << "+" << 2 << " = " << (f1 + 2) << endl;
		cout << f1 << "-" << 2 << " = " << (f1 - 2) << endl;
		cout << f1 << "*" << 2 << " = " << (f1 * 2) << endl;
		cout << f1 << "/" << 2 << " = " << (f1 / 2) << endl;

		cout << f2 << " += " << 1 << " = " << (f2 += 1) << endl;
		cout << f2 << " -= " << 1 << " = " << (f2 -= 1) << endl;
		cout << f2 << " *= " << 1 << " = " << (f2 *= 1) << endl;
		cout << f2 << " /= " << 1 << " = " << (f2 /= 1) << endl;

		cout << "++" << f1 << " = " << ++f1 << endl;
		cout << f3++ << "++  + " << f1 << " = " << (f3 + f1) << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << f3 << endl;
			f3++;
		}
		cout << "Negative: " << f1 << " = " << -f1 << endl;
	}
	catch (std::exception&)
	{
		cout << "Fraction has invalid denominator\n";
		system("pause");
	}

	system("pause");
	return 0;
}