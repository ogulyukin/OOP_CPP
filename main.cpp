#include <iostream>
#include "math.h"
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
    double get_distance(double x, double y){
        double result = sqrt(pow(this->get_x() - x,2)+pow(this->get_y() - y,2));
        return result;
    }
    //Costructors:
    Point(double x = 0, double y = 0){
        this->x  = x;
        this->y = y;
        cout << "Constructor:\t" << this << endl;
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
    cout << "The distance between the points is : " << A.get_distance(B.get_x(),B.get_y()) << endl;
    //cout << "Checking : " << sqrt(2 * 2 + 5 * 5) << endl;
    return 0;
}
