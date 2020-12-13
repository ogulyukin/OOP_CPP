#include <iostream>
#include "Fraction.h"
//#include "Fraction.cpp"
using  namespace std;


//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

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
