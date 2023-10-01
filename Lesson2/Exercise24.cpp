//
// Created by Christiaan Vink on 05/09/2023.
//
#include <iostream>

using namespace std;

int main() {
    int array[1001] = {0};
    int input;

    while (true) {
        cout << "";
        cin >> input;

        if (input == 0) {
            break;
        }

        if (input >= 1 && input <= 1000) {
            array[input]++;
            cout << array[input] - 1 << endl;
        }
    }

    return 0;
}
