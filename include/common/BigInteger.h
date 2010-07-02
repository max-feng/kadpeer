/*
 * Author: Devil Wang
 * Data: 01-21-2010
 * Notes: Template For BigInteger
 */
#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class DividedByZeroException{};

class BigInteger
{
private:
     vector<char> digits; 
     bool sign;          //  true for positive, false for negitive
     void trim();        //  remove zeros in tail, but if the value is 0, keep only one:)
public:
     BigInteger(int);    // construct with a int integer
     BigInteger(string&) ;
     BigInteger();
     BigInteger (const BigInteger&);
     BigInteger operator=(const BigInteger& op2);

     BigInteger      abs() const;
     BigInteger    pow(int a);

     //binary operators
        
     friend BigInteger operator+=(BigInteger&,const BigInteger&);
     friend BigInteger operator-=(BigInteger&,const BigInteger&);
     friend BigInteger operator*=(BigInteger&,const BigInteger&);
     friend BigInteger operator/=(BigInteger&,const BigInteger&) throw(DividedByZeroException);
     friend BigInteger operator%=(BigInteger&,const BigInteger&) throw(DividedByZeroException);       

     friend BigInteger operator+(const BigInteger&,const BigInteger&);
     friend BigInteger operator-(const BigInteger&,const BigInteger&);
     friend BigInteger operator*(const BigInteger&,const BigInteger&);
     friend BigInteger operator/(const BigInteger&,const BigInteger&) throw(DividedByZeroException);
     friend BigInteger operator%(const BigInteger&,const BigInteger&) throw(DividedByZeroException);
   

     //uniary operators
     friend BigInteger operator-(const BigInteger&);   //negative

     friend BigInteger operator++(BigInteger&);        //++v
     friend BigInteger operator++(BigInteger&,int);    //v++
     friend BigInteger operator--(BigInteger&);        //--v
     friend BigInteger operator--(BigInteger&,int);    //v--

     friend bool operator>(const BigInteger&,const BigInteger&);
     friend bool operator<(const BigInteger&,const BigInteger&);
     friend bool operator==(const BigInteger&,const BigInteger&);
     friend bool operator!=(const BigInteger&,const BigInteger&);
     friend bool operator>=(const BigInteger&,const BigInteger&);
     friend bool operator<=(const BigInteger&,const BigInteger&);

     friend ostream& operator<<(ostream&,const BigInteger&);    //print the BigInteger
     friend istream& operator>>(istream&, BigInteger&);         // input the BigInteger

public:
     static const BigInteger ZERO;
     static const BigInteger ONE;
     static const BigInteger TEN;
};


#endif
