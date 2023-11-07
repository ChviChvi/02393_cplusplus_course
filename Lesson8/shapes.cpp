//
// Created by Christiaan Vink on 31/10/2023.
//
#include "shapes.h"
using namespace std;

Rectangle::Rectangle(double height, double width) : HEIGHT(height), WIDTH(width) {}
Square::Square(double side) : Rectangle(side, side) {}
Circle::Circle(double radius) : RADIUS(radius) {}


// the area of the shape
double Rectangle::area() const {
    return HEIGHT * WIDTH;
}
double Square::area() const {
    return HEIGHT * HEIGHT;
}
double Circle::area() const {
    return 3.14159265359 * RADIUS * RADIUS;
}


// perimeter (the distance around the edge
double Rectangle::perimeter() const {
    return 2 * (HEIGHT + WIDTH);
}
double Square::perimeter() const {
    return 2 * (HEIGHT + WIDTH);
}
double Circle::perimeter() const {
    return 2 * 3.14159265359 * RADIUS;
}


// the height of the shape
double Rectangle::height() const {
    return HEIGHT;
}
double Square::height() const {
    return Rectangle::height();  // Calls Rectangle's height method
}
double Circle::height() const {
    return 2 * RADIUS;
}


//the width of the shape
double Rectangle::width() const {
    return WIDTH;
}
double Square::width() const {
    return HEIGHT;
}
double Circle::width() const {
    return 2 * RADIUS;
}


// Circle and Square are uneffected by rotate
// rotating
void Circle::rotate() {}
void Square::rotate() {}
void Rectangle::rotate() {
    swap(HEIGHT, WIDTH);
}



