//
// Created by oleg on 20.02.2021.
//
#ifndef OOP_CPP_ELEMENT_H
#define OOP_CPP_ELEMENT_H
#pragma once

class Element {
    int Data;       //Значение элемента
    Element* pNext; //Адрес следующего элемента
public:
    Element* get_pNext();
    int get_Data()const;
    Element(int Data, Element* pNext = nullptr);
    ~Element();
    friend class List;
};


#endif //OOP_CPP_ELEMENT_H
