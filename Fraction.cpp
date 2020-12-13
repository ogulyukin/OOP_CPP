//
// Created by oleg on 13.12.2020.
//
#include "Fraction.h"
//Class Definition
int Fraction::get_integer()const{
    return this->integer;
}
int Fraction::get_numerator()const{
    return this->numerator;
}
int Fraction::get_denominator()const{
    return this->denomenator;
}
void Fraction::set_integer(int integer){
    this->integer = integer;
}
void Fraction::set_numenator(int numenator){
    this->numerator = numenator;
}
void Fraction::set_denomenator(int denomenator){
    this->denomenator = denomenator ? denomenator : 1;
}
void Fraction::print_fraction()const{
    //cout << this->integer << " " << this->numerator << "/" << this->denomenator << endl;
    if (integer)cout << integer;
    if (numerator){
        if(integer)cout << "(";
        cout << numerator << "/" << denomenator;
        if(integer)cout << ")";
    }
    if(integer == 0 && numerator == 0)cout << 0;
    cout << endl;
}
void Fraction::print_adress()const{
    cout << "Object:\t\t" << this << endl;
    cout << "Integer:\t\t" << &integer << endl;
    cout << "Numenator:\t\t" << &numerator << endl;
    cout << "Denomerator:\t" << &denomenator << endl;
}
Fraction& Fraction::to_proper(){
    integer += numerator / denomenator;
    numerator %= denomenator;
    return *this;
}
void Fraction::to_improper(){
    numerator += integer * denomenator;
    integer = 0;
}
Fraction Fraction::inverted(){
    this->to_improper();
    return Fraction(denomenator,numerator);
}
Fraction& Fraction::reduce(){
    if (!numerator){
        return *this;
    }
    int more,less,rest;
    if(numerator < denomenator){
        less = numerator;
        more = denomenator;
    }else{
        less = denomenator;
        more = numerator;
    }/*
        do{
            rest = more%less;
            more = less;
            less = rest;
        }while(rest);*/
    for(rest = 1;rest;more = less,less = rest)rest = more%less;
    int GCD = more; //GCD Greatest Common Dividor(Наибольший общий делитель)
    numerator /=GCD;
    denomenator /=GCD;
    return *this;
}
//Constructors
Fraction::Fraction(){
    this->integer = this->numerator = 0;
    this->denomenator = 1;
    cout << "Default Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer){
    this->integer = integer;
    this->numerator = 0;
    this->denomenator = 1;
    cout << "1 arg. Constructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denumerator){
    this->integer = 0;
    this->numerator = numerator;
    this->denomenator = denumerator;
    cout << "2 arg. Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer , int numerator, int denumerator){
    this->set_integer(integer);
    this->set_numenator(numerator);
    this->set_denomenator(denumerator);
    cout << "3 arg. Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other){
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denomenator = other.denomenator;
    cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction(){
    cout << "Destrictor:\t" << this << endl;
}
//Operators:
Fraction& Fraction::operator=(const Fraction& other){
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denomenator = other.denomenator;
    cout << "CopyAssignment:\t" << this << endl;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& other){
    return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction other){
    return *this = *this / other;
}
//increment/decrement
Fraction& Fraction::operator++(){//Prefix increment
    integer++;
    return *this;
}
Fraction Fraction::operator++(int){//Prefix increment
    Fraction old = *this;
    integer++;
    return old;
}
Fraction& Fraction::operator--(){
    integer--;
    return *this;
}
//Type cast operator
Fraction::operator int(){
    return this->to_proper().integer;
}
Fraction::operator double(){
    to_proper();
    return integer +(double)numerator / denomenator;
}
//operator Fraction::HouseNumber(){

//}
// class definition end
inline Fraction operator*(Fraction left, Fraction right){
    left.to_improper();
    right.to_improper();
    Fraction result(left.get_numerator() * right.get_numerator(),left.get_denominator() * right.get_denominator());
    //result.set_numenator(left.get_numerator() * right.get_numerator());
    //result.set_denomenator(left.get_denominator() * right.get_denominator());
    result.to_proper();
    return result.to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right){
    return left*right.inverted();
}
inline Fraction operator-(Fraction left, Fraction right){
    Fraction result(
            left.get_integer() - right.get_integer(),
            left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
            right.get_denominator() * left.get_denominator()
    );
    return result.to_proper().reduce();//.to_proper().reduce();
}
ostream& operator<<(ostream& os, const Fraction& obj){
    if (obj.get_integer())cout << obj.get_integer();
    if (obj.get_numerator()){
        if(obj.get_integer())cout << "(";
        cout << obj.get_numerator() << "/" << obj.get_denominator();
        if(obj.get_integer())cout << ")";
    }
    if(obj.get_integer() == 0 && obj.get_numerator() == 0)cout << 0;
    return os;
}
bool operator==(const Fraction& left, const Fraction& right){
    return left.get_integer()==right.get_integer()&&
           left.get_numerator() == right.get_numerator()&&
           left.get_denominator() == left.get_denominator();
}