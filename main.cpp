#include <iostream>
#include <ostream>
#include "Element.h"
#include "List.h"
using namespace std;
#define tab "\t"

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    int n;
    //cout << "Введите размер списка: "; cin >> n;
    /*List list;
    for (int i = 0; i < n; i++) {
        list.push_front(rand() % 100);
        system("sleep 1");
    }
    list.print();
    List list2(n);
    list2.print();
    list2[2] = rand()%100;
    cout << list2[2] << endl;
    List list3;
    list3 = list2;
    list3.print();*/
    List list4 = {3,23,8,1,4};
    //list4.print();
    for (int i : list4){
        cout << i << tab;
    }
    cout << endl;
    List list3 = {3,55,89};
    for(Iterator it = list3.begin(); it != list3.end(); it++)
        cout << *it << tab;
    cout << endl;
    List list5 = {1,1,1};
    cout << "____________________________________" << endl;
    List list6;
    list6 = list4 + list3 + list5;
    //list5 = list5;
    list6.print();
    cout << "____________________________________" << endl;

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
    list.print();
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
    //cout << endl;*/
    return 0;
}
