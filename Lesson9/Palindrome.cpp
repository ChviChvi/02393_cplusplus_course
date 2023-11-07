//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const vector<int>& sequence, int start, int end) {
    if (start >= end) return true; // Base case
    if (sequence[start] != sequence[end]) return false; // Not a palindrome
    return isPalindrome(sequence, start + 1, end - 1); // Recursive call
}

int main() {
    vector<int> sequence;
    int num;
    while (cin >> num) { // Read numbers until the end of input
        sequence.push_back(num);
    }
    cout << (isPalindrome(sequence, 0, sequence.size() - 1) ? "yes" : "no");
    return 0;
}
