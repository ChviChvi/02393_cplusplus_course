//
// Created by Christiaan Vink on 05/09/2023.
//
//Write a program that reads a positive integer n and prints the result of the sum 1 + 2 + . . . + n.
//For example, for n = 100 the result is 5050.
#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    float num;

    cout << "";
    cin >> n;
    for (int i = 0; i < n; ++i) {


        sum = sum + i+1;

    }

    cout << sum << endl;

    return 0;
}