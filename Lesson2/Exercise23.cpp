//
// Created by Christiaan Vink on 05/09/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

double pi(int n) {
    double approx = 0.0;

    for (int i = 0; i < n; i++) {
        double leibniz = pow(-1, i) / (2 * i + 1);
        approx = approx + leibniz;
    }

    approx = approx * 4;
    return approx;
}

int main() {
    int n;
    cout << "";
    cin >> n;

    double result = pi(n);
    cout << result << endl;
    return 0;
}


