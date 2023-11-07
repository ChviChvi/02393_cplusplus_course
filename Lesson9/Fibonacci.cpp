//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return 1; // Base cases
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}

int main() {
    int n;
    while (cin >> n) { // Read numbers until the end of input
        cout << fibonacci(n) << " "; // Calculate and print Fibonacci number
    }
    return 0;
}
