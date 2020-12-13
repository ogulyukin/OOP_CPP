//
// Created by oleg on 13.12.2020.
//
#pragma once
#include <iostream>
#ifndef OOP_CPP_FRACTION_H
#define OOP_CPP_FRACTION_H
//#include "Fraction.h"
using namespace  std;
using std::cout;
using std::cin;
using std::endl;
class Fraction;
inline Fraction operator*(Fraction left, Fraction right);
inline Fraction operator/(Fraction left, Fraction right);
inline Fraction operator-(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);
bool operator==(const Fraction& left, const Fraction& right);

//begin class definition
class HouseNumber{
    int number;
public:
    int get_number() const{
        return this->number;
    }
    void Print_House_number()const{
        cout << number << endl;
    }
    HouseNumber(int number){
        this->number = number;
    }
};

class Fraction{
    int integer;
    int numerator;
    int denomenator;
public:
    int get_integer()const;
    int get_numerator()const;
    int get_denominator()const;
    void set_integer(int integer);
    void set_numenator(int numenator);
    void set_denomenator(int denomenator);
    void print_fraction()const;
    void print_adress()const;
    Fraction& to_proper();
    void to_improper();
    Fraction inverted();
    Fraction& reduce();
    //Constructors
    Fraction();
    Fraction(int integer);
    Fraction(int numerator, int denumerator);
    Fraction(int integer , int numerator, int denumerator);
    Fraction(const Fraction& other);
    ~Fraction();
    //Operators:
    Fraction& operator=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction other);
    //increment/decrement
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    //Type cast operator
    explicit operator int();
    explicit operator double();
    //operator HouseNumber();
};
//End of class declaration


#endif //OOP_CPP_FRACTION_H
