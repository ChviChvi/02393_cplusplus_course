//
// Created by Christiaan Vink on 29/08/2023.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    float sum = 0.0;
    float num;

    cout << "";
    cin >> n;
    for (int i = 0; i < n; ++i) {

        cin >> num;
        sum = sum + num;

    }

    cout << sum << endl;

    return 0;
}
