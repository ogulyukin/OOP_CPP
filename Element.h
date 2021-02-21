//
// Created by oleg on 20.02.2021.
//
#ifndef OOP_CPP_ELEMENT_H
#define OOP_CPP_ELEMENT_H
#pragma once
#include <iostream>
using namespace std;
class Element {
    int Data;       //Значение элемента
    Element* pNext; //Адрес следующего элемента
    static int count; //количество элементов
public:
    Element* get_pNext();
    int get_Data()const;
    int get_count()const;
    Element(int Data, Element* pNext = nullptr);
    ~Element();
    friend class List;
    friend class Iterator;
};
class Iterator{
    Element* Temp;
public:
    Iterator(Element* Temp): Temp(Temp){
        //cout << "Iterator constructor\t" << this << endl;
    }
    ~Iterator(){
        //cout << "Iterator destructor\t" << this << endl;
    }
    Iterator& operator++(){
        Temp = Temp->pNext;
        return *this;
    }
    Iterator operator++(int){
        Iterator old = *this;
        Temp = Temp->pNext;
        return old;
    }
    bool operator==(const Iterator& other){
        return (this->Temp == other.Temp);
    }
    bool operator!=(const Iterator& other){
        return (this->Temp != other.Temp);
    }
    int& operator*(){
        return Temp->Data;
    }
};

#endif //OOP_CPP_ELEMENT_H
