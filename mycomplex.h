#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_///<Library for working with complex numbers
#include <iostream>

using namespace std;

class Complex//class creation Complex

{
      double Re;
	  double Im;
public:

      Complex (double aRe = 0, double aIm = 0);///Create complex number
      Complex (const Complex & );
     ~Complex();

void Set (double aRe, double aIm = 0);/// Assigns the complex number a new value.
      operator double();
      double abs();

friend istream & operator >> (istream &, Complex &);
friend ostream & operator << (ostream &, Complex &);

      Complex operator + (const Complex &);
      Complex operator - (const Complex &);
      Complex operator + (const double &);

friend Complex operator + (const double &, const Complex &);
      Complex operator - (const double &);

friend Complex operator - (const 	double &, const Complex &);
      Complex operator * (const Complex &);
      Complex operator * (const double &);

friend Complex operator * (const double &, const Complex &);
      Complex operator / (const double &);

      Complex & operator += (const Complex &);/// Adds a number to the target complex number, where the number to add is complex.
      Complex & operator -= (const Complex &);
      Complex & operator *= (const Complex &);
      Complex & operator += (const double &);
      Complex & operator -= (const double &);
      Complex & operator *= (const double &);
      Complex & operator /= (const double &);
      Complex & operator = (const Complex &);
      Complex & operator = (const double &);
};
#endif
