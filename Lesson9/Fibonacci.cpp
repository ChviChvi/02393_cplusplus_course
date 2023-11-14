//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>

using namespace std;

int fibonacci_calculation(int numbers) {
    if (numbers <= 1) {
        return 1;
    } else {
        return fibonacci_calculation(numbers - 1) + fibonacci_calculation(numbers - 2);
    }
}

int main() {
    cout << "" << endl;

    int incomming_numbers;
    while (cin >> incomming_numbers) {
        cout << fibonacci_calculation(incomming_numbers) << " ";
    }
    cout << endl;
    return 0;
}

