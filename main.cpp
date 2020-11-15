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
    void print() const{
        cout << "X = " << this->x << "\tY = " << this->y << endl;
    }
    double get_distance(double x, double y) const{
        double result = sqrt(pow(this->get_x() - x,2)+pow(this->get_y() - y,2));
        return result;
    }
    double get_distance_to_point(const Point& other) const{
        double result =  sqrt(pow(this->x - other.x,2)+pow(this->y - other.y,2));
        return result;
    }
    //Costructors:
    Point(double x = 0, double y = 0){
        this->x  = x;
        this->y = y;
        cout << "Constructor:\t" << this << endl;
    }
    Point(const Point& other){
        this->x = other.x;
        this->y = other.y;
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Point(){
        cout << "Destructor:\t" << this << endl;
    }
};
double distance (const Point& A, const Point& B){
    double result = sqrt(pow(A.get_x() - B.get_x(),2)+pow(A.get_y() - B.get_y(),2));
    return result;
}
int main() {
    setlocale(LC_ALL, "");
    Point A;
    A.print();
    Point B(2,5);
    B.print();
    //Point C = 5;
    //C.print();
    cout << "The distance between the points A and B is : " << distance(A,B) << endl;
    //cout << "The distance between the points A and B is : " << A.get_distance(B.get_x(),B.get_y()) << endl;
    //cout << "Checking : " << sqrt(2 * 2 + 5 * 5) << endl;
    //cout << "The disctance form point B to point you'll now input is:" << endl;
    cout << B.get_distance_to_point(A) << endl;
    cout << sizeof(Point) << endl;
    Point C = B;
    C.print();
    return 0;
}
