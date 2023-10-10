//
// Created by Christiaan Vink on 03/10/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//this method finds the GCD(greatest common diviser) so basically it will divide both numbers with th largest positive integer
// which divides both numbers without leaving anything left.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class fraction {

private:
    int numerator;
    int denominator;

public:

    //needed to initialize the fraction with its numerator and denominator
    fraction(int n, int d): numerator(n), denominator(d) {
    }

    //adding fractions on eachother
    void add(fraction f){
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = denominator * f.denominator;
        simplify();
    }

    // multiplying fractions with eachother
    void mult(fraction f){
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        simplify();
    }

    //dividing fractions with eachother
    void div(fraction f){
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;
        simplify();
    }

    void display(void){
        cout << numerator << " / " << denominator;
    }

    //this method we put in every method to make sure that we are working with a GCD number :)
    // our numerator and denominator are made smaller here through the GCD
    void simplify() {
        int the_dividerr = gcd(numerator, denominator);
        numerator = numerator / the_dividerr;
        denominator = denominator / the_dividerr;
    }

};

int main() {

    while(true){

        int a, b, c, d;
        char  forwardslash1, forwardslash2;
        string operations;

        cin >> a >> forwardslash1 >> b >> operations >> c >> forwardslash2 >> d;

        if(cin.fail()){
            break;
        }
        fraction fraction1(a, b);
        fraction fraction2(c, d);
        if (operations == "+") {
            fraction1.add(fraction2);
        } else if (operations == "*") {
            fraction1.mult(fraction2);
        } else if (operations == "div") {
            fraction1.div(fraction2);
        }
        fraction1.display();
        cout << endl;
    }
    return 0;
}