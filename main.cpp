#include <iostream>
#include <ostream>
//#include <initializer_list>
using namespace std;
#define tab "\t"
class Element{
    int Data;       //Значение элемента
    Element* pNext; //Адрес следующего элемента
public:
    Element* get_pNext(){
        return pNext;
    }
    int get_Data()const{
        return Data;
    }
    Element(int Data, Element* pNext = nullptr): Data(Data), pNext(pNext){
        cout << "EConstructor:\t" << this << endl;
    }
    ~Element(){
        cout << "EDestructor:\t" << this << endl;
    }
    friend class List;
};
class List{
    Element* Head; //на начальный элемент списка
public:
    Element* get_Head(){
        return Head;
    }
    List(){
        Head = nullptr; //Если голова содержит 0 значит список пуст
        cout << "LConstructor:\t" << this << endl;
    }
    List(int count){
        if (count <= 0 || count > 30){
            cout << "Invalid quantity of elements!!!" << endl;
            Head = nullptr;
        }else {
            Head = new Element(0);
            Element* temp = Head;
            for (int i = 1; i < count; i++){
                temp->pNext = new Element(0);
                temp = temp->pNext;
            }
        }
        cout << "LConstructor with count\t" << this << endl;
    }
    List(const initializer_list<int> &list): List(list.size()){
        bool if_begin = true;
        Element* temp = Head->pNext;
        for (int element : list){
            if (if_begin){
                Head->Data = element;
                if_begin = false;
            }else{
                temp->Data = element;
                temp = temp->pNext;
            }
        }
        cout << "Initilaser_list Constructor" << this << endl;
    }
    List(const List &list): List(){
        /* regular method
        this->Head = list.Head;
        Element* copy_temp = list.Head;
        Element* list_temp = this->Head;
        while(copy_temp->pNext != nullptr){
            copy_temp = copy_temp->pNext;
            list_temp->pNext = new Element(copy_temp->Data);
            list_temp = list_temp->pNext;
        };
         */
        //recursion method
        copy_elements(list.Head);
        cout << "Copy LConstructor\t" << this << endl;
    }
    List(List &&list): List(){
        erase_all();
        this->Head = list.Head;
        list.Head = nullptr;
        cout << "Move LConstructor\t" << this << endl;
    }
    ~List(){
        cout  << "LDestructor:\t" << this << endl;
    }
    //Добавление элемента
    void push_front(int Data){
        /*
        //1)Создаем новый элемент
        Element* New = new Element(Data);
        //2) Присоединяем новый элемент к списку
        New->pNext = Head;
        //3) В голову пишем адрес нового элемента Новый элемент теперь начало списка.
        Head = New;
         */
        Head = new Element(Data, Head);
    }
    void push_back(int Data){
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
    }
    //Methods
    void print(){
        Element* Temp = Head; //Temp - это итератор
        while(Temp != nullptr){
            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            Temp = Temp->pNext;
        }
    }
    void insert(int Index, int Data){
        Element* Temp = Head;
        for (int i = 0; i < Index - 1; i++){
            Temp = Temp->pNext;
            if (Temp->pNext == nullptr){
                cout << "ERROR! entered not a valid index!" << endl;
                return;
            }
        }
        Temp->pNext = new Element(Data, Temp->pNext);
    }
    void pop_front(){
        if(Head->pNext == nullptr)
            return;
        Head = Head->pNext;
    }
    void pop_back(){
        Element* temp = Head;
        Element* temp2;
        while (temp->pNext != nullptr){
            temp2 = temp;
            temp = temp->pNext;
        }
        delete temp;
        temp2->pNext = nullptr;
    }
    void sort(){
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
    int get_size(){
        Element* temp = Head;
        int count = 0;
        while(temp != nullptr){
            temp = temp->pNext;
            count++;
        }
        return count;
    }
    void replace(int one, int two){
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
    void erase(int index){
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
    void erase_elements(Element *element, Element *element1){
        if(element1->pNext != nullptr)
            erase_elements(element1, element1->pNext);
        delete element1;
        element->pNext = nullptr;
    }
    void copy_elements(Element* element){
        if(element->pNext != nullptr) {
            copy_elements(element->pNext);
        }
        this->push_front(element->Data);
    }
    void erase_all(){
        if (this->Head == nullptr)
            return;
        if (this->Head->pNext == nullptr){
            Head = nullptr;
            return;
        }
        erase_elements(Head, Head->pNext);
        Head = nullptr;
    }
    List* operator=(const List &list){
        if(Head != nullptr)
            erase_all();
        this->copy_elements(list.Head);
        /* код без рекурсии закоментирован
        Element* this_temp = Head;
        Element* copy_temp = list.Head;
        while(copy_temp->pNext != nullptr){
            copy_temp = copy_temp->pNext;
            this_temp->pNext = new Element(copy_temp->Data);
            this_temp = this_temp->pNext;
        };*/
        cout << "Copy Assigment\t" << this << endl;
        return this;
    }
    List* operator=(List &&list){
        erase_all();
        this->Head = list.Head;
        list.Head = nullptr;
        cout << "Move Assigment\t" << this << endl;
        return this;
    }
    Element* operator[](int index){//проверить
        if (index < 0){
            cout << "Invalid index!!! First element is:" << endl;
            return Head;
        }
        Element* temp = Head;
        for (int i=0; i < index; i++){
            if (temp->pNext == nullptr){
                cout << "Invalid index!!! Last element is:" << endl;
                return temp;
            }
            temp = temp->pNext;
        }
        return temp;
    }
    List operator+(const List &other){//проверить
        if(other.Head == nullptr)
            return *this;
        Element* temp = Head;
        while(temp->pNext != nullptr){
            temp = temp->pNext;
        }
        Element* temp2 = other.Head;
        do{
            temp->pNext = new Element(temp2->Data);
            temp = temp->pNext;
            temp2 = temp2->pNext;
        }while(temp2 != nullptr);
        return *this;
    }
};
ostream& operator<<(ostream &is, List &list){
    Element* temp = list.get_Head();
    while (temp != nullptr){
        is << temp << tab << temp->get_Data() << tab << temp->get_pNext() << endl;
        temp = temp->get_pNext();
    }
    return is;
}
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    int n;
    cout << "Введите размер списка: "; cin >> n;
    List list;
    for (int i = 0; i < n; i++) {
        list.push_front(rand() % 100);
        system("sleep 1");
    }
    list.print();
    /*
    cout << "Push_back----------------------------------" << endl;
    //list.push_back(101);
    list.print();
    cout << "Insert----------------------------------" << endl;
    int index, data;
    cout << "Введите индекс: "; cin >> index;
    cout << "Введите значение: "; cin >> data;
    list.insert(index,data);
    list.print();
    cout << "Pop_front----------------------------------" << endl;
    list.pop_front();
    list.print();
    cout << "Pop_back----------------------------------" << endl;
    list.pop_back();
    list.print();
    cout << "Erase----------------------------------" << endl;
    cout << "Введите индекс: "; cin >> index;
    list.erase(index);
    list.print();
    cout << "Copy----------------------------------" << endl;
    List list2 = list;
    list2.print();
    cout << "Assinment---------------------------------" << endl;
    List list3;
    list3 = list2;
    list3.print();

    cout << "Erase_all---------------------------------" << endl;
    list.erase_all();
    list.print();*/
    cout << "Assigned_recursion---------------------------------" << endl;
    List list2;
    list2 = list;
    cout << list2 << endl;
    cout << "Moving---------------------------------" << endl;
    List list3 = list + list2;
    cout << list3;
    cout << "Ininializer_list---------------------------------" << endl;
    List list4 = {3,23,8,1,4};
    cout << list4;
    cout << "Sorting!!!---------------------------------" << endl;
    list4.sort();
    cout << list4;
    //for(int i:list4)
    //    cout << i << tab;
    //cout << endl;
    return 0;
}
