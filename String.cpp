//
// Created by oleg on 27.12.2020.
//
//////////////////Определение класса String////////////////////////
#include "String.h"
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
