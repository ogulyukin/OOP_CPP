//
// Created by oleg on 20.02.2021.
//
#include "Element.h"
using namespace std;
Element* Element::get_pNext(){
    return pNext;
}
int Element::get_Data()const{
    return Data;
}
Element::Element(int Data, Element* pNext): Data(Data), pNext(pNext){
    count++;
    //cout << "EConstructor:\t" << this << endl;
}
Element::~Element(){
    count--;
    //cout << "EDestructor:\t" << this << endl;
}
int Element::count = 0;
