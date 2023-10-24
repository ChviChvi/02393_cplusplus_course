#include "vector2d.h"
#include <cmath>

//Here we make the constructor to initialize the vector which gives (a,b)
v2d::v2d(double a, double b) : x(a), y(b) {
    //
}

// Copying the constructor to make a vector
v2d::v2d(const v2d & v) : x(v.x), y(v.y) {
    //
}

v2d::~v2d() {
    // fyi : this is called when the class that gets called goes out of scope or is destroyed
}

// update the current vector
v2d & v2d::operator=(const v2d &v) {
    if (this == &v) {
        return *this;
    }
    x = v.x;
    y = v.y;
    return *this;
}

// overloading +, adding two vectors together
v2d & v2d::operator+(const v2d &v) {
    x += v.x;
    y += v.y;
    return *this;
}

// scalar product
double v2d::operator*(const v2d &v) {
    return (x * v.x) + (y * v.y);
}

// overloading * , multipliing two vectors together
v2d & v2d::operator*(double k) {
    x *= k;
    y *= k;
    return *this;
}

// Vector Length
double v2d::length() {
    return sqrt(x * x + y * y);
}

