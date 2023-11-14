//
// Created by Christiaan Vink on 07/11/2023.
//DONE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void reverse(istringstream& input) {
    int number;
    if (input >> number) {
        reverse(input);
        cout << number << " ";
    }
}

int main() {
    cout << "" << endl;

    string incomming_text;

    getline(cin, incomming_text);
    istringstream input(incomming_text);
    reverse(input);

    cout << endl;
    return 0;
}



