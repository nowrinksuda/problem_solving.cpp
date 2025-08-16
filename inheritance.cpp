// 1. Single Inheritance Problem

/*   You're tasked with developing software for a construction company. Design a base class called `Shape` representing various geometric shapes used in construction, with properties like `width` and `height`. Derive a class `Rectangle` from `Shape`, representing rectangular structures. Implement member functions to calculate the area and perimeter of a rectangular structure. Test your code by creating objects representing different rectangular structures and displaying their area and perimeter.*/
#include <bits/stdc++.h>
using namespace std;

class Shape {
protected:
    double width;
    double height;

public:
    Shape(double w, double h) : width(w), height(h) {}
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}

    double calculateArea() const {
        return width * height;
    }

    double calculatePerimeter() const {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle rect1(5, 4);
    cout << "Rectangle 1:" << endl;
    cout << "Area: " << rect1.calculateArea() << endl;
    cout << "Perimeter: " << rect1.calculatePerimeter() << endl;

    Rectangle rect2(3, 7);
    cout << "\nRectangle 2:" << endl;
    cout << "Area: " << rect2.calculateArea() << endl;
    cout << "Perimeter: " << rect2.calculatePerimeter() << endl;

    return 0;
}

