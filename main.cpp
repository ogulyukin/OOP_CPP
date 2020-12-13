#include <iostream>
using  namespace std;
using std::cout;
using std::cin;
using std::endl;
class Fraction;
inline Fraction operator*(Fraction left, Fraction right);
inline Fraction operator/(Fraction left, Fraction right);
inline Fraction operator-(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);
bool operator==(const Fraction& left, const Fraction& right);
//////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define CONSRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICKS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_CHECK
#define delimeter "\n--------------------------\n"
int main() {
    setlocale(LC_ALL,"Russian");
#ifdef CONSRUCTORS_CHECK
    Fraction myfract00;
    myfract00.print_fraction();
    myfract00.print_adress();
    Fraction myfract01(2);
    myfract01.print_fraction();
    myfract01.print_adress();
    Fraction myfract02(2,3);
    myfract02.print_fraction();
    myfract02.print_adress();
    Fraction myfract03(2,3,4);
    myfract03.print_fraction();
    myfract03.print_adress();
    cout << sizeof(Fraction) << endl;
#endif
#ifdef ASSIGNMENT_CHECK
    /*Fraction A(3,4);
    A.print_fraction();
    Fraction B(4,5);
    B.print_fraction();
    Fraction C ;
    C = A;
    C.print_fraction();*/
    Fraction A,B,C;
    cout << "\n__________________________________________\n";
    A = B = C = Fraction(1,2,3);
    cout << "\n__________________________________________\n";
#endif
#ifdef ARITHMETICKS_CHECK
    Fraction A(2,3,4);
    Fraction B(5, 7,8);
    //Fraction C = A / B;
    //C.print_fraction();
    A /= B;
    A.print_fraction();
    A.reduce().print_fraction();
    //A.print_fraction();
#endif
#ifdef INCREMENT_CHECK
    for (double i = 0.25; i< 15; i++){
        cout << i << "\t";
    }
    Fraction I(1,2);
    Fraction J = I++;
    I.print_fraction();
    J.print_fraction();
    cout << "\n--------------------------------------------------\n";
    (Fraction(2,4) - Fraction(1,4)).print_fraction();
    cout << "\n--------------------------------------------------\n";
#endif
#ifdef COMPARISON_CHECK
    //Fraction A(1,2);
    //cout << delimeter;
    //cout << A << endl;
    //cout << delimeter;
    Fraction A(4,1,2);
    Fraction B = A;
    cout << (A==B) << endl;
#endif
    /*
    double a = 2.5;
    cout  << (int)a << endl; //C like natation
    cout  << int(a)<< endl; //C++like natation
    int b = a;
    cout << b << endl;
    cout << typeid(2+3.5).name() << endl;
    */
     Fraction A = 5;
    cout << A << endl;
    Fraction B;
    B = 8;
    cout << B << endl;
    Fraction C(2,1,2);
    double d = (double)C;
    cout << d << endl;
    return 0;
}
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