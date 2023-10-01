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
    bool Isthereinput = false;

    while (cin >> dataset >> value) {
        Isthereinput = true;
        if (dataset == 'a') {
            dataA.push_back(value);
        } else if (dataset == 'b') {
            dataB.push_back(value);
        } else {
            cerr << "bad input" << dataset << value << endl;
            return 1;
        }
    }
    sort(dataA.begin(), dataA.end());
    sort(dataB.begin(), dataB.end());

    if (!Isthereinput) {
        cout << " " << endl;
        return 0;
    }



    for (int val : dataA) {
        cout << val << " ";
    }
    for (int val : dataB) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

