//
// Created by Christiaan Vink on 01/10/2023.
//
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

    int scalar = 0;
    int sizeA = dataA.size();
    int sizeB = dataB.size();
    int maxSize = max(sizeA, sizeB);

    //iterates through each element and times it with eachother accordingly
    //a 3 b 2 b 1 a 1 a 4 b 2
    //output: 15 (which is obtained from (3, 1, 4) × (2, 1, 2) = 3 · 2 + 1 · 1 + 4 · 2 = 15)
    for (int i = 0; i < maxSize; ++i) {
        int A = (i < sizeA) ? dataA[i] : 0;
        int B = (i < sizeB) ? dataB[i] : 0;
        scalar += A * B;
    }

    cout << scalar << endl;
    return 0;
}