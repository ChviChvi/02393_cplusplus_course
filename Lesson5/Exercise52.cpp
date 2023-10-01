//
// Created by Christiaan Vink on 01/10/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char dataset;
    int value;
    vector<int> dataA, dataB;
    bool hasInput = false;

    while (cin >> dataset >> value) {
        hasInput = true;
        if (dataset == 'a') {
            dataA.push_back(value);
        } else if (dataset == 'b') {
            dataB.push_back(value);
        } else {
            cerr << "bad input: " << dataset << value << endl;
            return 1;
        }
    }

    if (!hasInput) {
        cout << " " << endl;
        return 0;
    }

    int sizeA = dataA.size();
    int sizeB = dataB.size();
    int maxSize = max(sizeA, sizeB);

    for (int i = 0; i < maxSize; ++i) {
        if (i < sizeA) {
            cout << dataA[i] << " ";
        }
        if (i < sizeB) {
            cout << dataB[i] << " ";
        }
    }

    cout << endl;
    return 0;
}