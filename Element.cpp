//
// Created by oleg on 20.02.2021.
//
#include <iostream>
#include "Element.h"
using namespace std;
Element* Element::get_pNext(){
    return pNext;
}
int Element::get_Data()const{
    return Data;
}
Element::Element(int Data, Element* pNext): Data(Data), pNext(pNext){
    cout << "EConstructor:\t" << this << endl;
}
Element::~Element(){
    cout << "EDestructor:\t" << this << endl;
}