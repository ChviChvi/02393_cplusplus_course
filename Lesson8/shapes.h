//
// Created by Christiaan Vink on 31/10/2023.
//

#pragma once
#include <iostream>
#include <algorithm>

class Shape {
public:
     virtual ~Shape() = default;
    [[nodiscard]] virtual double area() const = 0;
    [[nodiscard]] virtual double perimeter() const = 0;
    [[nodiscard]] virtual double height() const = 0;
    [[nodiscard]] virtual double width() const = 0;
    virtual void rotate() = 0;
};

class Rectangle : public Shape {
protected:
    double HEIGHT;
    double WIDTH;
public:
    Rectangle(double height, double width);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

class Square : public Rectangle {
public:
    explicit Square(double side);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

class Circle : public Shape {
protected:
    double RADIUS;
public:
    explicit Circle(double radius);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};


