//
// Created by oleg on 20.02.2021.
//

#include "List.h"

Element* List::get_Head(){
    return Head;
}
int List::get_list_size()const{
    return size;
}
Iterator List::begin(){
    return Head;
}
Iterator List::begin()const{
    return Head;
}
Iterator List::end(){
    return nullptr;
}
Iterator List::end()const{
    return nullptr;
}
List::List(){
    Head = nullptr; //Если голова содержит 0 значит список пуст
    size = 0;
    cout << "LConstructor:\t" << this << endl;
}
List::List(int count){
    size = 0;
        if (count <= 0 || count > 30){
            cout << "Invalid quantity of elements!!!" << endl;
            Head = nullptr;
        }else {
            Head = new Element(0);
            size++;
            Element* temp = Head;
            for (int i = 1; i < count; i++){
                temp->pNext = new Element(0);
                temp = temp->pNext;
                size++;
            }
        }
        cout << "LConstructor with count\t" << this << endl;
    }
List::List(const initializer_list<int> &list): List(){
    size = 0;
    cout <<typeid(list.begin()).name() << endl;
    for (int const* it = list.begin(); it != list.end(); it++){
        push_back(*it);
    }
        cout << "Initilaser_list Constructor" << this << endl;
    }
List::List(const List &list): List(){
    this->size = 0;
     Element* temp = list.Head;
        while(temp){
            this->push_back(temp->Data);
            temp = temp->pNext;
        };

        //recursion method
        //copy_elements(list.Head);
        cout << "Copy LConstructor\t" << this << endl;
    }
List::List(List&& list){
    this->size = list.size;
    this->Head = list.Head;
    list.Head = nullptr;
    cout << "Move LConstructor\t" << this << endl;
}
List::~List(){
    while (Head)
        pop_front();
        cout  << "LDestructor:\t" << this << endl;
    }
    //Добавление элемента
    void List::push_front(int Data){
        /*
        //1)Создаем новый элемент
        Element* New = new Element(Data);
        //2) Присоединяем новый элемент к списку
        New->pNext = Head;
        //3) В голову пишем адрес нового элемента Новый элемент теперь начало списка.
        Head = New;
         */
        Head = new Element(Data, Head);
        size++;
    }
    void List::push_back(int Data){
        Element* Temp = Head;
        if (Head == nullptr){
            push_front(Data);
            return;
        }
        //нашли новый элемент
        while(Temp->pNext != nullptr){
            Temp = Temp->pNext;
        }
        //создаем и связываем последний элемент
        Temp->pNext = new Element(Data);
        size++;
    }
    //Methods
    void List::print(){
       for(Iterator Temp = Head; Temp != nullptr; Temp++)
           //cout << this << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
           cout << *Temp <<endl;
        cout << "Количество элементов списка: " << size << endl;
}
    void List::insert(int Index, int Data){
        Element* Temp = Head;
        for (int i = 0; i < Index - 1; i++){
            Temp = Temp->pNext;
            if (Temp->pNext == nullptr){
                cout << "ERROR! entered not a valid index!" << endl;
                return;
            }
        }
        Temp->pNext = new Element(Data, Temp->pNext);
        size++;
    }
    void List::pop_front(){
        Element* temp = Head;
        Head = Head->pNext;
        delete temp;
        size--;
    }
    void List::pop_back(){
        Element* temp = Head;
        while (temp->pNext->pNext != nullptr){
            temp = temp->pNext;
        }
        delete temp->pNext;
        temp->pNext = nullptr;
        size--;
    }
    void List::sort(){
        int data = Head->Data;
        int count = 0;
        int current_count;
        int found = 0;
        int size = get_size();
        Element* temp = Head;
        while(count < size){
            temp = Head;
            current_count = 0;
            found = 0;
            while(temp != nullptr){
                if (current_count > count){
                    if (data > temp->Data){
                        found = current_count;
                        data = temp->Data;
                    }
                }else if(current_count == count){
                    data = temp->Data;
                }
                temp = temp->pNext;
                current_count++;
                //cout << "Count: " << count << "\tCurrent_Count: " << current_count << endl;
            }
            if (found > 0){
                //cout << "found: " << count << "\t" << found << endl;
                replace(count, found);
            }
            count++;
        }
    }
    int List::get_size(){
        Element* temp = Head;
        int count = 0;
        while(temp != nullptr){
            temp = temp->pNext;
            count++;
        }
        return count;
    }
    void List::replace(int one, int two){
        int count = 0;
        Element* temp = Head;
        Element* temp2 = Head;
        while (count < one){
            temp = temp->pNext;
            temp2 = temp2->pNext;
            count++;
        }
        while(count < two){
            temp2 = temp2->pNext;
            count++;
        }
        count = temp->Data;
        temp->Data = temp2->Data;
        temp2->Data = count;
    }
    void List::erase(int index){
        Element* temp = Head;
        for (int i = 0; i < index; i++){
            if (temp->pNext == nullptr){
                cout << "Invalid index!!!" << endl;
                return;
            }
            temp = temp->pNext;
        }
        Element *temp2 = temp->pNext;
        if (temp2 == nullptr){
            this->pop_back();
        }else {
            temp->pNext = temp2->pNext;
        }
        delete temp2;
    }
    void List::erase_elements(Element *element, Element *element1){
        if(element1->pNext != nullptr)
            erase_elements(element1, element1->pNext);
        delete element1;
        element->pNext = nullptr;
    }
    void List::copy_elements(Element* element){
        if(element->pNext != nullptr) {
            copy_elements(element->pNext);
        }
        this->push_front(element->Data);
    }
    List* List::operator=(const List &list){
        if (this == &list)return this;
    while (this->Head)
            pop_front();
        for(Element* Temp = list.Head; Temp != nullptr; Temp = Temp->pNext)
            push_back(Temp->Data);
        //this->copy_elements(list.Head);
        cout << "Copy Assigment\t" << this << endl;
        return this;
    }
    List& List::operator=(List&& list){
        while(Head)pop_front();
        this->Head = list.Head;
        list.Head = nullptr;
        cout << "Move Assigment\t" << this << endl;
        return *this;
    }
    int& List::operator[](const int index){//проверит
        Element* temp = Head;
        if (index >= size || index < 0)
            throw std::exception();
        for (int i=0; i < index; i++){
            temp = temp->pNext;
        }
        return temp->Data;
}

ostream& operator<<(ostream &is, List &list){
    Element* temp = list.get_Head();
    while (temp != nullptr){
        is << temp << tab << temp->get_Data() << tab << temp->get_pNext() << endl;
        temp = temp->get_pNext();
    }
    is << "Количество элементов: " << list.get_list_size() << endl;
    return is;
}
List operator+(const List &left, const List &right){
    List cat = left;
    for(Iterator it = right.begin(); it != right.end(); it++)
        cat.push_back(*it);
    return cat;
}