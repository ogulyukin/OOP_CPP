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
    String(int size = 80){
        this->size = size;
        this->str = new char[size]{};
        cout << "Default Constructor\t" << this << endl;
    }
    String(const char str[]){
        this->size =  strlen(str);
        this->str = new char[size];
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
    ~String(){
        delete[] str;
        cout << "Destructor\t" << this << endl;
    }
    //      Metods
    void print()const{
        cout << "Size  :\t" << size << endl;
        cout << "String:\t" << str << endl;
    }
};
int main() {
    setlocale(LC_ALL, "");
    String str01;
    str01.print();
    String str02 = "Hello!";
    String str03 = str02;
    //str02 = str02;
    str03.print();
    return 0;
}
