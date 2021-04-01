#include <iostream>
#include <initializer_list>
using namespace std;
#define tab "\t"
#define delimiter "--------------------------------"
//#define basecheck
//#define iterators_check
#define INDEX_VS_OPERATOR
class List{
    class Element{
        int Data;
        Element* pNext;
        Element* pPrev;
    public:
        Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data),
        pNext(pNext), pPrev(pPrev){
            //cout << "EConstructor\t" << this << endl;
        }
        ~Element(){
            //cout << "EDestructor\t" << this << endl;
        }
        friend class List;
    };
    Element* Head;
    Element* Tail;
    int size;
public:
    int get_size()const{
        return size;
    }
    class Iterator{
        Element* Temp;
    public:
        Iterator(Element* Temp) : Temp(Temp){
            //cout << "IConstructor\t" << this << endl;
        }
        ~Iterator(){
            //cout << "IDestructor\t" << this << endl;
        }
        int& operator *(){
            return Temp->Data;
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
        bool operator==(const Iterator& other)const{
            return this->Temp == other.Temp;
        }
        bool operator!=(const Iterator& other)const{
            return this->Temp != other.Temp;
        }
        Iterator& operator--(){
            Temp = Temp->pPrev;
            return *this;
        }
        Iterator operator--(int){
            Iterator old = *this;
            Temp = Temp->pPrev;
            return old;
        }
        friend class List;
    };
    Iterator begin(){
        return Head;
    }
    Iterator end(){
        return nullptr;
    }
    Iterator rbegin(){
        return Tail;
    }
    Iterator rend(){
        return nullptr;
    }
    List(){
        Head = Tail = nullptr;
        size = 0;
        //cout  << "LConstructor\t" << this << endl;
    }
    List(int size): List(){
        while(size--){
            push_back(rand()%100);
            //system("sleep .1");
        }
    }
    List(const initializer_list<int> &il) : List(){
        for (int const* it = il.begin(); it != il.end(); it++){
            push_back(*it);
        }
    }
    ~List(){
        while (Head)
            pop_back();
        //cout  << "LDestructor\t" << this << endl;
    }
    //Adding elements
    void push_front(int Data){
        if(Head == nullptr && Tail == nullptr){
            Head = Tail = new Element(Data);
        }else{
            Head = Head->pPrev = new Element(Data, Head);
        }
        size++;
    }
    void push_back(int Data){
        if(Head == nullptr && Tail == nullptr){
            Head = Tail = new Element(Data);
        }else{
            Tail = Tail->pNext = new Element(Data, nullptr, Tail);
        }
        size++;
    }
    void insert(int Index, int Data){
        if (empty()){
            push_front(Data);
            return;
        }
        if (Index == 0){
            push_front(Data);
            return;
        }
        if(Index < 0 || Index > size)
            return;
        Element* Temp;
        if (Index < size /2){
            Temp = Head;
            for(int i = 0; i < Index; i++)
                Temp = Temp->pNext;
        }else{
            Temp = Tail;
            for(int i = 0; i < size - Index; i++)
                Temp = Temp->pPrev;
        }
        Temp->pPrev = Temp->pPrev->pNext = new Element(Data,Temp, Temp->pPrev);
        size++;
    }
    //removing elements
    void pop_front(){
        if(empty())
            return;
        if(Head == Tail){
            delete Head;
            Head = Tail = nullptr;
        }else{
            Head = Head->pNext;
            delete Head->pPrev;
            Head->pPrev = nullptr;
        }
        size--;
    }
    void pop_back(){
        if(empty())
            return;
        if(Head == Tail){
            delete Head;
            Head = Tail = nullptr;
        }else{
            Tail = Tail->pPrev;
            delete Tail->pNext;
            Tail->pNext = nullptr;
        }
        size--;
    }
    //Methods:
    void print()const{
        for(Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext){
            //cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            cout << Temp->Data << tab;
        }
        cout << "\nSize: " << size << endl;
    }
    bool empty()const{
         return Head == nullptr && Tail == nullptr;
    }
    void print_reverse()const{
        for(Element* Temp = Tail; Temp != nullptr; Temp = Temp->pPrev){
            //cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            cout << Temp->Data << tab;
        }
        cout << endl << "Size: " << size << endl;
    }
    //operators
    int& operator[](int index){
        if(index >= size){
            throw exception();
        }
        Element* Temp;
        if(index < size / 2) {
            Temp = Head;
            for (int i = 0; i < index; i++) {
                Temp = Temp->pNext;
            }
        }else{
                Temp = Tail;
                for(int i = 0; i < size - index -1; i++){
                    Temp = Temp->pPrev;
                }
            }
        return Temp->Data;
        }
};
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
#ifdef basecheck
    int n;
    cout << "Введите размер списка: "; cin >> n;
    List list;
    for(int i = 0; i < n; i++){
        list.push_front(rand()%100);
        system("sleep 1");
    }
    list.print();
    cout << delimiter << endl;
    list.print_reverse();
    cout << delimiter << endl;
    list.push_back(101);
    list.print();
    cout << delimiter << endl;
    int val;
    cout << "Введи индекс добавляемого элемента: "; cin  >> n;
    cout << "Введи значение добавляемого элемента: "; cin  >> val;
    list.insert(n, val);
    list.print();
    cout << delimiter << endl;
    list.print_reverse();
#endif
    int s;
    cout << "Введите число елементов: "; cin >> s;
    List list2(s);
    //list2.print();
#ifdef INDEX_VS_OPERATOR
    cout << "Список создан, загружаем данные\t" << endl;
    /*
    for (int i = 0; i < s; i++){
        list2[i] = rand()% 100;
    }*/
    for(List::Iterator it = list2.begin(); it != list2.end(); it ++){
        *it = rand()%100;
        //system("sleep .1");
    }
    cout << "Данные загружены" << endl;
    //list2.print();

    #endif/*
    cout << "Введите индекс: "; cin >> s;
    cout << list2[s] << endl;*/
#ifdef iterators_check
    List list = {3,5,8,13,21};
    list.print();
    for (int i : list){
        cout << i << tab;
    }
    cout << endl;
    for(List::Iterator it = list.begin(); it != list.end(); it ++){
        *it = rand()%1000;
        system("sleep .1");
    }
    cout << delimiter << endl;
    list.print();
    for (List::Iterator it = list.rbegin(); it != list.rend(); --it){
        cout << *it << tab;
    }
    cout << endl;
    cout << delimiter << endl;
    list.print();
#endif

    return 0;
}
