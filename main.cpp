#include <iostream>
#include "string.h"
#include "String.h"
using namespace std;

ostream& operator<<(ostream& ost, const String& str){
    return ost << str.get_str();
}
istream& operator>>(istream& ist, String& str){
    return ist >> str.get_str();
}
String operator+(const String &left, const String &right){
    String cat(left.get_size()+right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        cat[i] = left[i];
    for (int i = 0; i < right.get_size(); i++)
        cat[i+left.get_size()-1] = right[i];
    return cat;
}
/* Через арифметику указателей
String operator+(const String &left, const String &right){
    String cat(left.get_size()+right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        *(cat.get_str()+i) = *(left.get_str()+i);
    for (int i = 0; i < right.get_size(); i++)
        *(cat.get_str()+i+left.get_size()) = *(right.get_str()+i);
    return cat;
}
 */
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define OPERATOR_PLUS_CHECK

#define delimetr "\n_________________________________________\n"
int main() {
    setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
    String str01;
    str01.print();
    String str02 = "Hello!";
    String str03; //default constuctor
    str03 = str02; //Copy assigment
    str03.print();
#endif
#ifdef ASSIGMENT_CHECK
  String str1, str2, str3;
  str1 = str2 = str3 = "Hello!";
  str1.print();
  str2.print();
  str3.print();
  str1 = str1;
  str1.print();
#endif
  String str1 = "Hello";
    cout << delimetr;
  String str2 = "World";
    cout << delimetr;
    String str3 = str2;
    cout << delimetr;
    String str4;
    str4 = str1 + str2;
  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  cout << str4 << endl;

#ifdef OPERATOR_PLUS_CHECK
  str1.print();
  /*String name;
  cout << "Enter your name: "; cin >> name;
  cout << name << endl;
  name.print();*/
  cout << delimetr;
  //String str3 = str1 + " " + str2; //move constructor
  String str3;
  str3 = str1 + str2;
  cout << delimetr;
  cout << str3 << endl;
  cout << delimetr;
  cout << (str1 + str2) << endl;
  cout << delimetr;
  cout << (str1 += str3) << endl;
#endif

    return 0;
}
