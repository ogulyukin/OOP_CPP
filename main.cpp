#include <iostream>
using  namespace std;
class Fraction{
    int integer;
    int numerator;
    int denomenator;
public:
    int get_integer()const{
        return this->integer;
    }
    int get_numerator()const{
        return this->numerator;
    }
    int get_denominator()const{
        return this->denomenator;
    }
    void set_integer(int integer){
        this->integer = integer;
    }
    void set_numenator(int numenator){
        this->numerator = numenator;
    }
    void set_denomenator(int denomenator){
        this->denomenator = denomenator ? denomenator : 1;
    }
    void print_fraction()const{
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
    void print_adress()const{
        cout << "Object:\t\t" << this << endl;
        cout << "Integer:\t\t" << &integer << endl;
        cout << "Numenator:\t\t" << &numerator << endl;
        cout << "Denomerator:\t" << &denomenator << endl;
    }
    //Constructors
    Fraction(){
        this->integer = this->numerator = 0;
        this->denomenator = 1;
        cout << "Default Constructor:\t" << this << endl;
    }
    Fraction(int integer){
        this->integer = integer;
        this->numerator = 0;
        this->denomenator = 1;
        cout << "1 arg. Constructor:\t" << this << endl;
    }
    Fraction(int numerator, int denumerator){
        this->integer = 0;
        this->numerator = numerator;
        this->denomenator = denumerator;
        cout << "2 arg. Constructor:\t" << this << endl;
    }
    Fraction(int integer , int numerator, int denumerator){
        this->set_integer(integer);
        this->set_numenator(numerator);
        this->set_denomenator(denumerator);
        cout << "3 arg. Constructor:\t" << this << endl;
    }
    Fraction(const Fraction& other){
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denomenator = other.denomenator;
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Fraction(){
        cout << "Destrictor:\t" << this << endl;
    }
    //Operators:
    Fraction& operator=(const Fraction& other){
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denomenator = other.denomenator;
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
    }
};
//#define CONSRUCTORS_CHECK
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
    return 0;
}
