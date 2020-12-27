//
// Created by oleg on 27.12.2020.
//
#include <iostream>
#include "string.h"
#pragma once
class String;
using namespace std;
String operator+(const String &left, const String &right);
istream& operator>>(istream& is, String& obj);
istream& operator>>(istream& ist, String& str);
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