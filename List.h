//
// Created by oleg on 20.02.2021.
//
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <exception>
#include "Element.h"
#define tab "\t"
using namespace std;
class List{
    Element* Head; //на начальный элемент списка
    int size;
public:
    Element* get_Head();
    int get_list_size()const;
    Iterator begin();
    Iterator begin() const;
    Iterator end();
    Iterator end() const;
    List();
    explicit List(int count);
    List(const initializer_list<int> &list);
    List(const List &list);
    List(List&& list);
    ~List();
    //Добавление элемента
    void push_front(int Data);
    void push_back(int Data);
    //Methods
    void print();
    void insert(int Index, int Data);
    void pop_front();
    void pop_back();
    void sort();
    int get_size();
    void replace(int one, int two);
    void erase(int index);
    void erase_elements(Element *element, Element *element1);
    void copy_elements(Element* element);
    List* operator=(const List &list);
    List& operator=(List&& list);
    int& operator[](int index);

};
ostream& operator<<(ostream &is, List &list);
List operator+(const List &left, const List &right);
