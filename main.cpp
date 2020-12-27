#include <iostream>
#include "string.h"
using namespace std;

//////////////////ОБЪЯВЛЕНИЕ КЛАССА String ///////////////////
class String;
String operator+(const String &left, const String &right);
class String{
    int size;
    char* str;
public:
    const int get_size()const;
    const char* get_str()const;
    char* get_str();
    explicit String(int size = 80);
    String(const char str[]);
    String(const String& other);
    String(String&& other);
    ~String();
    //      Metods
    void print()const;
    //operators
    String& operator=(const String& other);
    String& operator=(String&& other);
    const char& operator[](int i)const;
    char& operator[](int i);
    String& operator+=(const String& other);
};
//////////////////Конец ОБЪЯВЛЕНИЕ КЛАССА String ///////////////////

//////////////////Определение класса String////////////////////////
const int String::get_size()const{
    return size;
}
const char* String::get_str()const{
    return str;
}
char* String::get_str(){
    return str;
}
String::String(int size):size(size), str(new char[size]{})//Делегирование конструктора
{
    //this->size = size;
    //this->str = new char[size]{};
    cout << "Default Constructor\t" << this << endl;
}
String::String(const char str[]):String(strlen(str)+1)//Делегирование конструктора
{
    //this->size =  strlen(str)+1;
    //this->str = new char[size]{};
    for (int i = 0; str[i]; i++){
        this->str[i] = str[i];
    }
    cout << "String Constructor\t" << this << endl;
}
String::String(const String& other):String(other.str)
{
    //this->size =  other.size;
    //this->str = new char[size]{};
    //for (int i = 0; other.str[i]; i++){
    //    this->str[i] = other.str[i];
    //}
    cout << "Copy Constructor\t" << this << endl;
}
String::String(String&& other):size(other.size),str(other.str){
//this->size = other.size;
//this->str = other.str;
other.str = nullptr;
cout << "Move constructor\t" << this << endl;
}
String::~String(){
    delete[] str;
    cout << "Destructor\t" << this << endl;
}
//      Metods
void String::print()const{
    cout << "Size  :\t" << size << endl;
    cout << "String:\t" << str << endl;
}
//operators
String& String::operator=(const String& other){
    if (this == &other)return *this;
    this ->size = other.size;
    delete[] this->str;
    this->str = new char[size]{};
    for (int i = 0; i < size; i++) {
        this->str[i] = other.str[i];
    }
    cout << "Copy assigment" << endl;
    return *this;
}
String& String::operator=(String&& other){
    delete[] this->str;
    this->size = other.size;
    this->str = other.str;
    other.str = nullptr;
    cout << "Move assigment" << endl;
    return *this;
}
const char& String::operator[](int i)const{
    return str[i];
}
char& String::operator[](int i){
    return str[i];
}
String& String::operator+=(const String& other){
    return (*this = *this + other);
}

//////////////////Конец Определение класса String////////////////////////
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
