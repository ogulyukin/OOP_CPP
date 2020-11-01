#include <iostream>
using namespace  std;
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
};
int main() {
    setlocale(LC_ALL, "");
    Point A;
    A.set_x(2);
    A.set_y(5);
    cout << A.get_x() << "\t" << A.get_y() << endl;
    Point* pA = &A;
    cout << pA->get_x() << "\t" <<  pA->get_y() << endl;
    return 0;
}
