/**
 * This class describes a number in an integer modulo base
 * @author Duncan, Preston Gautreaux
 * <pre>
 * File: ModularInt.h
 * Date: 09/23/2024
 * Course: csc 1254 section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <iostream>

#ifndef MODINT_H
#define MODINT_H

using namespace std;

/* YOUR TASK HERE IS TO GIVE THE COMPLETE DEFINITION OF
   THE class ModInt AS DESCRIBED IN THE PROJECT HANDOUT.
   BE SURE TO INCLUDE A DESCRIPTION OF EACH FUNCTION.
   YOU WILL PROVIDE ONLY THE PUBLIC INTERFACE OF THE MEMBER
   AND FRIEND FUNCTIONS, NOT THEIR DEFINITIONS.
   THE MEMBER AND FRIEND FUNCTIONS WILL BE DEFINED IN THE
   IMPLEMENTATION FILE.

   DEFINE THE CLASS BELOW.
*/

class ModInt
{
private:

	/*
	* Variables to store user data as number(mod base), where number is the modular integer, and base is the modulus.
	*/
	int number;
	int base;

	/*
	* Implemented by Dr. Duncan.
	* Private static function that returns the greatest common factor of integers a and b, its parameters.
	* @param integer a
	* Aparam integer b
	*/
	int gCF(int a, int b);

public:

	/*
	* Contructor that creates 0(mod1); sets the number to 0 and modulus to 1.
	*/
	ModInt();

	/*
	* Constructor that creates n(modb); sets number to n and modulus to b. 
	* Throws invalid_argument exception when b is less than or equal to zero.
	* @param integer n (number)
	* @param integer b (base)
	*/
	ModInt(int n, int b);

	/*
	* Accessor to return the value of the modulus integer (number).
	*/
	int getNumber() const;
	
	/*
	* Accessor to returns the value of the modulus (base).
	*/
	int getBase() const;

	/*
	* Returns true when its parameter is congruent to ModInt class member m, otherwise false. 
	* @param modular number m
	*/
	bool congruent(const ModInt& m);

	/*
	* Returns true when its parameter, a modular number, is invertible. Otherwise returns false.
	*/
	bool invertible() const;

	/*
	* Returns simplified version of the inverse of its parameter (a modular number of the ModInt class).
	* Throws an "invalid_argument" exception when its parameter is not invertible. 
	*/
	ModInt inverse() const;

	/*
	* Function to simplify modular numbers performing exponentiation.
	* Should throw invalid_argument exception when n is negative and m is not invertible.
	* Includes solution for a mod number to the 0th power (1mod n).
	* @param integer n
	* @param modular number m
	*/
	friend ModInt pow(const ModInt& m, int n);

	/*
	* Returns formatted string of modular number
	* @param string stream out
	* @param modular number m
	*/
	friend ostream& operator<<(ostream& out, const ModInt& m);

	/*
	* Determines if two modular numbers are equal
	* @param modular number m
	* @param modular number n
	*/
	friend bool operator==(ModInt& m, ModInt& n);

	/*
	* Implemented by Dr. Duncan.
	* Binary arithmetic operator: addition (+)
	* Instructs proper addition of two modular numbers
	* @param modular number m
	* @param modular number n
	*/
	friend ModInt operator+(const ModInt& m, const ModInt& n);

	/*
	* Binary arithmetic operator: subtraction (-)
	* Instructs proper subtraction of two modular numbers
	* @param modular number m
	* @param modular number n
	*/
	friend ModInt operator-(const ModInt& m, const ModInt& n);

	/*
	* Binary arithmetic operator: division (/)
	* Instructs proper division of two modular numbers
	* @param modular number m
	* @param modular number n
	*/
	friend ModInt operator/(const ModInt& m, const ModInt& n);

	/*
	* Binary arithmetic operator: mulitplication (*)
	* Instructs proper mulitplication of two modular numbers
	* @param modular number m
	* @param modular number n
	*/
	friend ModInt operator*(const ModInt& m, const ModInt& n);


};

#endif MODINT_H