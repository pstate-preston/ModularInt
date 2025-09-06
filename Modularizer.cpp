/**
 * A program to test the ModInt class implementation
 * @author Duncan, Preston Gautreaux
 * @see ModularInt.h
 * <pre>
 * File: Modularizer.cpp
 * Date: 09/23/2024
 * Course: csc 1254 section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <iostream>
#include <cmath>
#include "ModularInt.h"

using namespace std;

int main()
{
	try
	{
		int base, num;
		cout << "Enter the number and base of the first modular integer -> ";
		cin >> num >> base;
		ModInt m1(num, base);
		cout << "Enter the number and base of the second modular integer -> ";
		cin >> num >> base;
		ModInt m2(num, base);
		cout << m1 << " + " << m2 << " = " << m1 + m2 << endl;
		cout << m1 << " x " << m2 << " = " << m1 * m2 << endl;
		cout << m1 << " - " << m2 << " = " << m1 - m2 << endl;
		cout << m2 << "^-1 = " << m2.inverse() << endl;
		cout << m1 << " / " << m2 << " = ";
		if (m2.invertible())
			cout << m1 / m2;
		else
			cout << "nan";
		cout << endl;
		cout << "Is m2 ~= m2 + base(m2)? ";
		cout << (m2.congruent(ModInt(m2.getNumber() + m2.getBase(), m2.getBase())) ? "true" : "false") << endl;
		cout << m2 << "^2 = " << pow(m2, 2) << endl;
		cout << m2 << "^-2 = " << pow(m2, -2) << endl;                                                            
		cout << "Is m1^3 equal val(m1)^3 mod(base(m1))? "
			<< (pow(m1, 3).getNumber() == (int)pow(m1.getNumber(), 3) % m1.getBase() ? "true" : "false") << endl;
		cout << "Is m1^3 equal val(m1)^3 mod (base(m1)^3)? "
			<< (pow(m1, 3).getNumber() == (int)pow(m1.getNumber(), 3) % (int)pow(m1.getBase(), 3) ? "true" : "false") << endl;
		
		
		/*
		* (A) Prompt the user to enter three non-negative integers p, q, and r.
		* 	  Evaluate and display (p - q)(p^2 + pq + q^2) mod r  in the format:
		* 	  (p - q)(p^2 + pq + q^2) mod r = ... 
		*/
		int p, q, r;
		cout << "Please enter three non-negative integers" << endl;
		cin >> p >> q >> r;
		if ((r) == 0)
		{
			throw invalid_argument("Cannot divide by zero. Please choose a greater number for r.");
		}
		else if ((p | q | r) < 0)
		{
			throw invalid_argument("Please enter a non-negative integer as prompted.");
		}
		ModInt user_entry(((p - q) * ((p * p) + (p * q) + (q * q))) % r, r);
		cout << "(p - q)(p^2 + pq + q^2) mod r = " << user_entry << endl;

		
		/*
		* (B) Write an if statement that determines whether:
		*	  rq^(p-1) is congruent to r modulo p. The output should be in the
		*	  format:
		*	  rq^(p-1) ~= r mod p? ...
		*	  where ... is replaced with either true or false.
		*/
		int expression = r * pow(q, (p - 1));
		if ((expression % p) == (r % p))
		{
			cout << "rq^(p-1) ~= r mod p? true" << endl;
		}
		else
		{
			cout << "rq^(p-1) ~= r mod p? false" << endl;
		}

	}
	catch (const invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
