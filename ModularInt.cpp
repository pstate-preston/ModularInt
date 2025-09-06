/**
 * public implementation for the ModInt class
 * @author Duncan, Preston Gautreaux
 * @see ModularInt.h
 * <pre>
 * File: ModularInt.cpp
 * Date: 09/23/2024
 * Course: csc 1254 section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <cmath>
#include "ModularInt.h"



int ModInt::gCF(int m, int n)
{
    if (m == 0)
    {
        if (n == 0)
            throw invalid_argument("gcf(0,0) = nan");
        return abs(n);
    }
    else if (n == 0)
        return abs(m);
    else
    {
        m = abs(m);
        n = abs(n);
        int rem = m % n;
        while (rem != 0)
        {
            m = n;
            n = rem;
            rem = m % n;
        }
        return n;
    }
}



ModInt::ModInt()
{
    number = 0;
    base = 1;
}



ModInt::ModInt(int n, int b)
{
    number = n;
    base = b;

    if (b <= 0)
    {
        throw invalid_argument("The modulus of an integer must be a positive integer");
    }
}



int ModInt::getNumber() const
{
    return number;
}



int ModInt::getBase() const
{
    return base;
}



bool ModInt::congruent(const ModInt& m)
{
    int mod1 = number % base;
    int mod2 = m.number % m.base;

    if (mod1 == mod2)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool ModInt::invertible() const
{
    int n = number; 
    int m = base;    

    if (n == 0)
    {
        return false;
    }

    n = abs(n);      
    int remainder = m % n;
    
    while (remainder != 0)
    {
        m = n;
        n = remainder;
        remainder = m % n;
    }

    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}



ModInt ModInt::inverse() const
{
    int k = 0;
    int test_mod;

    if (invertible() == false)
    {
        throw invalid_argument("This modular number is not invertible");
    }
    else
    {
        do
        {
            k++;
            test_mod = (k * number) % base;
        } while (test_mod != 1);
    }

    ModInt result(k, base);

    if(result.number < 0)
    {
       result.number += result.base;
    }
    return result;
}



ostream& operator<<(ostream& out, const ModInt& m)
{
    out << m.number << "[" << m.base << "]";
    return out;
}



bool operator==(ModInt& m, ModInt& n)                              
{
    bool result;
    if (m.base != n.base)
    {
        result = false;
    }

    int mod1 = m.number % m.base;
    int mod2 = n.number % n.base;
    if (mod1 = mod2)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}



ModInt operator+(const ModInt& m, const ModInt& n)
{
    if (m.base != n.base)
        throw invalid_argument("Only modular numbers of the same base can be added.");
    ModInt result((m.number % m.base + n.number % m.base) % m.base, m.base);
    if (result.number < 0)
        result.number += m.base;
    return result;
}



ModInt operator-(const ModInt& m, const ModInt& n)
{
    if (m.base != n.base)
    {
        throw invalid_argument("To compute the difference of a modular number, they must have the same base");
    }
    ModInt result((m.number % m.base - n.number % m.base) % m.base, m.base);
    if (result.number < 0)
    {
        result.number += m.base;
    }
    return result;
}



ModInt operator/(const ModInt& m, const ModInt& n)
{
    if (m.base != n.base)
    {
        throw invalid_argument("To perform division on modular numbers, the numerator and denominator must have the same modular base");
    }
    if (n.invertible() != true)
    {
        throw invalid_argument("To perform division on modular numbers, the numberator must be invertible.");
    }

    ModInt inverted_n = n.inverse();
    ModInt result(((m.number % m.base) * (inverted_n.number % n.base)) % n.base, n.base);
    if (result.number < 0)
    {
        result.number += m.base;
    }
    return result;
}



ModInt operator*(const ModInt& m, const ModInt& n)
{
    if (m.base != n.base)
    {
        throw invalid_argument("To multiply two modular numbers, they must have the same base.");
    }
    ModInt result(((m.number % m.base) * (n.number % n.base)) % n.base, n.base);
    if (result.number < 0)
    {
        result.number += m.base;
    }
    return result;
}



ModInt pow(const ModInt& m, int n)
{
    int i = 1;
    ModInt product;
    ModInt result;
    ModInt zeroth(1,m.base);
    
    if (n < 0)
    {
        if (m.invertible() == false)
        {
            throw invalid_argument("To perform exponentiation on a modular number, the modular number must be invertible.");
        }
        else
        {
            result = m.inverse();
            for (i; i < abs(n); i++)
            {
                product = result * m.inverse();
                result = product;
            }
            if (result.number < 0)
            {
                result.number += result.base;
            }
        }
    }

    if (n == 0)
    {
        return zeroth;
    }

    if(n > 0)
    {
        result = m;
        for (i; i < n; i++)
        {
            product = result * m;
            result = product;
        }
        if (result.number < 0)
        {
            result.number += result.base;
        }
    }

        return result;
}