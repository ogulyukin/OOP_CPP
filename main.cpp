#include <iostream>
#include "string.h"
using namespace std;
class String{
    int size;
    char* str;
public:
    const int get_size()const{
        return size;
    }
    const char* get_str()const{
        return str;
    }
    char* get_str(){
        return str;
    }
    explicit String(int size = 80){
        this->size = size;
        this->str = new char[size]{};
        cout << "Default Constructor\t" << this << endl;
    }
    String(const char str[]){
        this->size =  strlen(str)+1;
        this->str = new char[size]{};
        for (int i = 0; str[i]; i++){
            this->str[i] = str[i];
        }
        cout << "String Constructor\t" << this << endl;
    }
    String(const String& other){
        this->size =  other.size;
        this->str = new char[size]{};
        for (int i = 0; other.str[i]; i++){
            this->str[i] = other.str[i];
        }
        cout << "Copy Constructor\t" << this << endl;
    }
    String(String&& other){
        this->size = other.size;
        this->str = other.str;
        other.str = nullptr;
        cout << "Move constructor\t" << this << endl;
    }
    ~String(){
        delete[] str;
        cout << "Destructor\t" << this << endl;
    }
    //      Metods
    void print()const{
        cout << "Size  :\t" << size << endl;
        cout << "String:\t" << str << endl;
    }
    //operators
    String& operator=(const String& other){
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
    String& operator=(String&& other){
        delete[] this->str;
        this->size = other.size;
        this->str = other.str;
        other.str = nullptr;
        cout << "Move assigment" << endl;
        return *this;
    }
    const char& operator[](int i)const{
        return str[i];
    }
    char& operator[](int i){
        return str[i];
    }
};
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
  String str2 = "World";
  cout << str1 << endl;
  cout << str2 << endl;
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
    return 0;
}
