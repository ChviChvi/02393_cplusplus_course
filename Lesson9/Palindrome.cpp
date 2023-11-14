//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// going forward from both sides
bool isthisaPalindrome(const vector<int>& numbers, int start, int end) {
    // looking for mismatch
    if (start >= end) {
        return true;
    }
    if (numbers[start] != numbers[end]) {
        return false;
    }
    return isthisaPalindrome(numbers, start + 1, end - 1);
}

int main() {
    cout << "" << endl;

    string incomming_numbers;
    getline(cin, incomming_numbers);
    istringstream input(incomming_numbers);

    vector<int> numbers_line;

    int number;
    // putting the number sin
    while (input >> number) {
        numbers_line.push_back(number);
    }

    bool palindrome = isthisaPalindrome(numbers_line, 0, numbers_line.size() - 1);

    if (palindrome) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
