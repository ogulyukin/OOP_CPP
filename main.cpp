#include <iostream>
//#include "windows.h"
#include "math.h"
using namespace std;
enum Color{ //todo реализовать изменение цвет в консоли// сделано
    blue,
    green,
    red,
    yellow,
    default_color
};

class Shape{
    Color color;
protected:
    void set_draw_color(int i){
        switch (i) {
            case 0:
                cout << "\e[0;34m";
                break;
            case 1:
                cout << "\e[0;32m";
                break;
            case 2:
                cout << "\e[0;31m";
                break;
            case 3:
                cout << "\e[0;33m";
                break;
            default:
                cout << "\033[1;0m";
        }
    }
    double rand_value(int value){
        srand(time(0));
        system("sleep 1");
        return rand() % value;
    }
public:
    virtual double get_area()const = 0;
    virtual double get_perimeter() const = 0;
    virtual void draw() = 0;
    Shape(Color color):color(color){
        cout << "ShConstructor:\t" << this << endl;
    }
    virtual~Shape(){
        cout << "ShDestructor:\t" << this << endl;
    }
    Color get_color()const{
        return color;
    }
};
class Square: public Shape{
    double side;
public:
    const double get_side()const{
        return side;
    }
    void set_side(double side){
        side >= 0 ? this ->side = side: this->side = 0;
    }
    //Constructors
    Square(Color color):Shape(color){
        set_side(rand_value(100)/2);
    }
    Square(Color color, double side):Shape(color){
        set_side(side);
        cout << "Constructor:\t" << this << endl;
    }
    ~Square(){
        cout << "SqDestructor:\t" << this << endl;
    }
    //methods
    virtual double get_area()const{
        return side * side;
    }
    virtual double get_perimeter() const{
        return side * 4;
    }
    virtual void draw(){
        //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        //SetCosoleTextAttribute(hConsole, get_color());
        set_draw_color(get_color());
        cout << "Площадь квадрата: " << get_area() << endl;
        cout << "Периметр квадрата: " << get_perimeter() << endl;
        cout << "Стороны квадрата: " << side << endl << endl;
        for (int i = 0; i < side; i++){
            for (int j = 0; j < side; j++){
                cout << "* ";
            }
            cout << endl;
        }
        set_draw_color(100);
        //SetCosoleTextAttribute(hConsole, Color::default_color);
    }
};
class Rectangle: public Shape{
    double side_one;
    double  side_two;
public:
    double get_side_one()const{
        return side_one;
    }
    double get_side_two()const{
        return side_two;
    }
    void set_side_one(double side_one){
        (side_one > 0) ? this->side_one = side_one : this->side_one = 0;
    }
    void set_side_two(double side_two){
        (side_two > 0) ? this->side_two = side_two : this->side_two = 0;
    }
    virtual double get_area()const{
        return side_one * side_two;
    }
    virtual double get_perimeter()const{
        return side_one * 2 + side_two * 2;
    }
    virtual void draw(){
        set_draw_color(get_color());
        cout << "Площадь прямоугольника: " << get_area() << endl;
        cout << "Периметр прямоугольника: " << get_perimeter() << endl;
        cout << "Стороны прямоугольника: " << side_one << "\t" << side_two << endl << endl;
        for (int i = 0; i < side_one; i++){
            for (int j = 0; j < side_two; j++){
                cout << "* ";
            }
            cout << endl;
        }
        set_draw_color(100);
    }
    Rectangle(Color color): Shape(color){
        set_side_one(rand_value(100)/2);
        set_side_two(rand_value(100)/2);
    }
    Rectangle(Color color, double side_one, double side_two):Shape(color){
        set_side_one(side_one);
        set_side_two(side_two);
        cout << "RectConstructor:\t" << this << endl;
    }
    ~Rectangle(){
        cout << "RectDestructor:\t" << this << endl;
    }
};
class Triangle: public Shape{
    double side_one;
    double side_two;
    double side_three;
public:
    double get_side_one()const{
        return side_one;
    }
    double get_side_two()const{
        return side_two;
    }
    double get_side_three()const{
        return side_three;
    }
    void set_side_one(double side_one){
        (side_one > 0) ? this->side_one = side_one : this->side_one = 0;
    }
    void set_side_two(double side_two){
        (side_two > 0) ? this->side_two = side_two : this->side_two = 0;
    }
    void set_side_three(double side_three){
        (side_three > 0) ? this->side_three = side_three : this->side_three = 0;
    }
    virtual double get_area()const{
        double p = (get_side_one() + get_side_two() + get_side_three()) / 2;
        return sqrt(p * (p - get_side_one()) * (p - get_side_two()) * (p - get_side_three()));
    }
    virtual double get_perimeter() const{
        return get_side_one() + get_side_two() + get_side_three();
    }
    virtual void draw(){
        set_draw_color(get_color());
        cout << "Площадь треугольника: " << get_area() << endl;
        cout << "Периметр треугольника: " << get_perimeter() << endl;
        cout << "Стороны треугольника: " << side_one << "\t" << side_two << "\t" << side_three << endl << endl;
        //Todo нарисовать произвольный треугольник... вот только как это сделать??? - А вот так!!!!
        double H = ( 2 * get_area() / side_one);
        double half_side_one = sqrt(pow(get_side_two(),2) - pow(H,2));
        double half_side_two = sqrt(pow(get_side_three(),2) - pow(H,2));
        double index01 = 0;
        double index02 = 0;
        for (int i = 0; i < H; i++){
            for (int j = 0; j < half_side_one; j++){
                (index01 < j) ? cout << "* " : cout << "  ";
            }
            for (int j = half_side_two; j > 0; j--){
                (index02 < j) ? cout << "* " : cout << "  ";
            }
            index01 += (half_side_one / H);
            index02 += (half_side_two / H);
            cout << endl;
        }

        set_draw_color(100);
    }
    Triangle(Color color):Shape(color){
        do{
            set_side_one(rand_value(100)/2);
            set_side_two(rand_value(100)/2);
            set_side_three(rand_value(100)/2);
        }while((side_one + side_two) < side_three && (side_two + side_three) < side_one);
    }
    Triangle(Color color, double side_one, double side_two, double side_three):Shape(color){
        set_side_one(side_one);
        set_side_two(side_two);
        set_side_three(side_three);
        cout << "TriangleConstructor: " << this << endl;
    }
    ~Triangle(){
        cout << "TriangleDestructor: " << this << endl;
    }
};
class Circle: public Shape{
    double radius;
public:
    double get_radius()const{
        return radius;
    }
    void set_radius(double radius){
        this->radius = radius;
    }
    virtual double get_area()const{
        return (2*get_radius()*3.14);
    }
    virtual double get_perimeter() const{
        return (pow(get_radius(), 2) * 3.14);
    }
    virtual void draw(){
        set_draw_color(get_color());
        //todo WoW!! а теперь давай сделаем кружочек!!!
        cout << "Площадь круга: " << get_area() << endl;
        cout << "Длина окружности: " << get_perimeter() << endl;
        cout << "Радиус: " << radius << endl << endl;
        int index01;
        for (int i = 0; i <= radius; i++){
            index01 = sqrt(pow(radius, 2) - pow(radius - i, 2));
            for (int j = 0 ; j < radius - index01 ; j++){
                cout << "  ";
            }
            for (int j = radius - index01; j <= radius; j++){
                cout << "* ";
            }
            //cout << index01;
            for (int j = radius; j <=  index01 + radius; j++){
                cout << "* ";
            }
            cout << endl;
        }
        //второе полукружие
        for (int i = radius; i >= 0; i--){
            index01 = sqrt(pow(radius, 2) - pow(radius - i, 2));
            for (int j = 0 ; j < radius - index01 ; j++){
                cout << "  ";
            }
            for (int j = radius - index01; j <= radius; j++){
                cout << "* ";
            }
            //cout << index01;
            for (int j = radius; j <=  index01 + radius; j++){
                cout << "* ";
            }
            cout << endl;
        }
        set_draw_color(100);
    }
    Circle(Color color): Shape(color){
        set_radius(rand_value(100)/2);
    }
    Circle(Color color, double radius):Shape(color){
        set_radius(radius);
        cout << "CircleConstructor" << this << endl;
    }
    ~Circle(){
        cout << "CircleDestructor" << this << endl;
    }
};
int main() {
    Square square(red);
    square.draw();
    cout << "-----------------------------------------------" << endl;
    Rectangle rect(green);
    rect.draw();
    cout << "-----------------------------------------------" << endl;
    Triangle trig(blue);
    trig.draw();
    Triangle trig01(blue, 10, 6, 8);
    trig01.draw();
    cout << "-----------------------------------------------" << endl;
    Circle circl(yellow);
    circl.draw();
    return 0;
}
