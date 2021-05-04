/*!
  @file
  @brief Файл с описание методов класса Complex */
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;
/*!
  @file
  @brief Конструктор класса
  @param aRe действительная составляющая
  @param aIm Мнимая составляющая */
Complex :: Complex (double aRe  , double   aIm)
{
    Re = aRe;
    Im = aIm;
}
/*!
    @brief Конструктор класса
    @param complex_num Комплексное число
*/
Complex :: Complex (const Complex & aRval)  // описание конструктора копирования (передача по ссылке)

{
    Re = aRval.Re;              // записи параметров действительной и мнимой части
    Im = aRval.Im;
}
/*!
    @brief Деструктор класса
*/
Complex :: ~Complex()           // описание деструктора класса, очистка памяти
{
    Re =0.0;
    Im= 0.0;
}

void Complex ::  Set(  double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}
/*!
    @brief Возвращает модуль комплексного числа
    @return Модуль комплексного числа
*/
Complex :: operator double()
{
    return abs();
}

double Complex :: abs()
{
    return sqrt(Re*Re+Im*Im);
}
/*!
    @brief Оператор сложения
    @param Result комплексная переменная
*/
Complex Complex ::  operator+ (const Complex & aRval )  // описание оператора сложения, комплексная переменная
{
    Complex Result;                 // создание и запись её Re и Im частей, переменной Result класса Complex
    Result.Re=Re+ aRval. Re;
    Result.Im =Im + aRval.Im ;
    return Result;
}
/*!
    @brief Оператор вычитания
*/
Complex Complex :: operator- ( const Complex & aRval)   // описание оператора вычитания
{
    Complex Result;
    Result.Re = Re-aRval.Re;
    Result.Im = Im-aRval.Im;
    return Result;
}

Complex Complex :: operator+ (const double & aval)
{
    Complex Result;
    Result.Re= Re +aval;
    Result.Im = Im;
    return Result;
}

Complex Complex :: operator- (const  double & aRval)
{
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

Complex Complex  :: operator* ( const Complex & aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}
/*!
    @brief Оператор умножения
*/
Complex Complex :: operator* (const double & aRval)
{
    Complex Result;
    Result.Re = Re*aRval;
    Result.Im = Im*aRval;
    return Result;
}
/*!
    @brief Оператор деления
*/
Complex Complex :: operator/ (const double & aRval)
{
    Complex Result;
    Result.Re = Re/aRval;
    Result.Im = Im/aRval;
    return Result;
}
/*!
    @brief Оператор сравнения(больше или равно)
*/
Complex & Complex :: operator+= ( const Complex &  aRval)
{
    Re+= aRval.Re;
    Im+= aRval.Im;
    return * this;
}
/*!
    @brief Оператор сравнения(меньше или равно)
*/
Complex & Complex :: operator-= (const Complex & aRval)
{
    Re-= aRval.Re;
    Im-= aRval.Im;
    return *this;
}

Complex & Complex :: operator*= (const Complex & aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

Complex & Complex :: operator+= (const double & aRval)
{
    Re+= aRval;
    return *this;
}

Complex & Complex :: operator-= (const double & aRval)
{
    Re -= aRval;
    return *this;
}

Complex & Complex :: operator*= (const double & aRval)
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

Complex & Complex :: operator/= (const double & aRval)
{
    Re/= aRval;
    Im/= aRval;
    return *this;
}

Complex & Complex :: operator = (const Complex & aRval)
{
    Re= aRval.Re;
    Im= aRval.Im;
    return *this;
}

Complex & Complex :: operator = (const double & aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

istream & operator >> (istream & stream, Complex & aRval)
{
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

ostream & operator << (ostream & stream, Complex & aRval)
{
    stream << a.Re;
    if( !(a.Im < 0) )
    stream << '+';
    stream << a.Im << 'i';
    return stream;
}

Complex operator+ (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval+aRval.Re;
    Result. Im = aRval.Im;
    return Result;
}

Complex operator- (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

Complex operator* (const double & aLval, const Complex & aRval) // описание оператора умножения
{ Complex r;                                              // "complex r" создание переменной r класса Complex
   r.Re =aLval* a.Re;                                     // r.Re запись переменной r параметра действительной части
 r.Im =aLval *a.Im;                                       // r.Im  запись переменной r параметра мнимой части 
  return r;                                               //  return возвращение записанных параметров

}
