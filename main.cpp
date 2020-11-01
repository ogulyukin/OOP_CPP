#include <iostream>
using namespace  std;
//#define BASICS
class Point{
    double x;
    double y;
public:
    double get_x() const{
        return x;
    }
    double get_y() const{
        return y;
    }
    void set_x(double x){
        this->x = x;
    }
    void set_y(double y){
        this->y = y;
    }
    void print(){
        cout << "X = " << this->x << "\tY = " << this->y << endl;
    }
    //Costructors:
    Point(){
        x = y = double();
        cout << "DefaultConstructor:\t" << this << endl;
    }
    Point(double x, double y){
        this->x  = x;
        this->y = y;
        cout << "Constructor with two parametrs:\t" << this << endl;
    }
    Point(double x){
        this->x = x;
        this->y = double();
        cout << "Constructor with one parametr:\t" << this << endl;
    }
    ~Point(){
        cout << "Destructor:\t" << this << endl;
    }
};
int main() {
    setlocale(LC_ALL, "");
    Point A;
    A.print();
    Point B(2,5);
    B.print();
    Point C = 5;
    C.print();
#ifdef BASICS
    A.set_x(2);
    A.set_y(5);
    cout << A.get_x() << "\t" << A.get_y() << endl;
    Point* pA = &A;
    cout << pA->get_x() << "\t" <<  pA->get_y() << endl;
#endif
    return 0;
}
